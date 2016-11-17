/*
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    Copyright (C) 2016 Robolabo
 *
 *    Authors: Eduardo Matallanas de Avila <eduardo.matallanas@upm.es>
 *             Manuel Castillo Cagigal <manuel.castillo@upm.es>
 *             Alvaro Gutierrez Martin <aguti@etsit.upm.es>
 *
 *    Developed in Robolabo <http://www.robolabo.etsit.upm.es/>
 */
/****************************************************************/
/* DB METHODS       						                                */
/****************************************************************/
#include "dbfunction.h"

/****************************************************************/
/* CONSTRUCTOR 							                                    */
/****************************************************************/
CDBFunction::CDBFunction(CMysqlDB* pm_magicbox_db, TAppV v_app, string s_mysql_conf){
  m_pcMysql = pm_magicbox_db;
  m_vApp = v_app;
  m_sLogFile = m_pcMysql->getLogFile();

	XMLDocument conf;
    	conf.LoadFile( s_mysql_conf.c_str() );
	XMLElement* root = conf.FirstChildElement();
	string elemName , sName, sType;	
  sMysqlTable sAuxTable;
	for( XMLElement* elem = root->FirstChildElement() ; elem != NULL ; elem = elem->NextSiblingElement() ){
    sAuxTable.sName=elem->Attribute("name");
    for( XMLElement* param = elem->FirstChildElement() ; param != NULL ; param = param->NextSiblingElement() ){
      sAuxTable.vColName.push_back(param->Attribute("name"));
      sAuxTable.vColType.push_back(param->Attribute("type"));
    }

    m_vMysqlTables.push_back(sAuxTable);

    sAuxTable.vColName.clear();
    sAuxTable.vColType.clear();
  } 
  conf.Clear();
};
/****************************************************************/
/* DESTRUCTOR 							                                    */
/****************************************************************/
CDBFunction::~CDBFunction(){
};
/****************************************************************/
/* DB OPERATION FUNCTION 																				*/
/* Select the operation to interact with the database           */
/****************************************************************/
void CDBFunction::dbOperation ( int n_db_operation,  char* pc_table){
	switch (n_db_operation){
    case CREATE_TABLE:
      CreateTable (pc_table);
      break;
    case DROP_TABLE:
      DropTable (pc_table);
      break;
    case DELETE_TABLE:
      DeleteTable (pc_table);
      break;
    case UPDATE_STATUS:
      UpdateStatus (pc_table);
      break;
    case ACTUATION:
      Actuation ();
      break;
  }
  return;
};
/****************************************************************/
/* CREATE TABLE FUNCTION 																				*/
/* Creates the table in the MySQL DB with the parameter and the */
/* types specified in the configuration file.										*/
/****************************************************************/
void CDBFunction::CreateTable ( char* pc_table ) {
  stringstream ssLog;
  stringstream ssParams;
  //All the tables are created from the xml file
  if(pc_table == NULL){
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      for(int col=0; col<m_vMysqlTables[tab].vColName.size(); col++){
        ssParams<<m_vMysqlTables[tab].vColName[col]<<" "<<m_vMysqlTables[tab].vColType[col];
        if(col!=m_vMysqlTables[tab].vColName.size()-1)
          ssParams<<", ";
      }

      m_pcMysql->CreateTable (m_vMysqlTables[tab].sName.c_str(),(ssParams.str()).c_str()); 

      /*LOG FILE*/
      ssLog<<"CDBFunctions::CreateTable==>Created table "<<m_vMysqlTables[tab].sName<<" succesfully";
      writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());

      ssParams.str("");
      ssLog.str("");
    }
  //Indicate from the command line which table is created
  }else{
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      if(m_vMysqlTables[tab].sName.compare(pc_table)==0){
        for(int col=0; col<m_vMysqlTables[tab].vColName.size(); col++){
          ssParams<<m_vMysqlTables[tab].vColName[col]<<" "<<m_vMysqlTables[tab].vColType[col];
          if(col!=m_vMysqlTables[tab].vColName.size()-1)
            ssParams<<", ";
        }

        m_pcMysql->CreateTable (m_vMysqlTables[tab].sName.c_str(),(ssParams.str()).c_str()); 

        /*LOG FILE*/
        ssLog<<"CDBFunctions::CreateTable==>Created table "<<m_vMysqlTables[tab].sName<<" succesfully";
        writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());

        ssParams.str("");
        ssLog.str("");
      }
    }
  }
	return;
};
/****************************************************************/
/* DROP TABLE FUNCTION																					*/
/* Eliminate the table specified from the MySQL DB.							*/
/****************************************************************/
void CDBFunction::DropTable ( char* pc_table ) {
  stringstream ssLog;

  //All the tables are dropped from the xml file
  if(pc_table == NULL){
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      //Drop the Table
      m_pcMysql->DropTable (m_vMysqlTables[tab].sName.c_str());

      /*LOG FILE*/
      ssLog<<"CDBFunctions::DropTable==>Dropped table "<<m_vMysqlTables[tab].sName.c_str()<<" succesfully";
      writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());

      ssLog.str("");
    }
  //Indicate from the command line which table is dropped
  } else {
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      if(m_vMysqlTables[tab].sName.compare(pc_table)==0){
        //Drop the Table
        m_pcMysql->DropTable (m_vMysqlTables[tab].sName.c_str());

        /*LOG FILE*/
        ssLog<<"CDBFunctions::DropTable==>Dropped table "<<m_vMysqlTables[tab].sName.c_str()<<" succesfully";
        writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());

        ssLog.str("");
      }
    } 
  }

  return;
};
/****************************************************************/
/* DELETE VALUES FUNCTION																				*/
/* Delete all the values from the table if there is no          */
/* condition specified from the command line. 									*/
/****************************************************************/
void CDBFunction::DeleteTable ( char* pc_table ) {
  stringstream ssLog;

  //All the values of the tables are deleted from the xml file
  if(pc_table == NULL){
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      /*Delete all the values*/
      m_pcMysql->DeleteValueTable (m_vMysqlTables[tab].sName.c_str(),NULL);
      /*LOG FILE*/
      ssLog<<"CDBFunctions::DeleteTable==>Deleted all values of table "<<m_vMysqlTables[tab].sName.c_str();
      writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());
    }
  //Indicate from the command line which table is deleted
  }else{
    for(int tab=0; tab<m_vMysqlTables.size(); tab++){
      if(m_vMysqlTables[tab].sName.compare(pc_table)==0){
        /*Delete all the values*/
        m_pcMysql->DeleteValueTable (m_vMysqlTables[tab].sName.c_str(),NULL);
        /*LOG FILE*/
        ssLog<<"CDBFunctions::DeleteTable==>Deleted all values of table "<<m_vMysqlTables[tab].sName.c_str();
        writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());
      }
    }
  }

  return;
};
/****************************************************************/
/* INSERT STATUS FUNCTION																				*/
/* Insert the processed data in the tables of the MySQL DB. 		*/
/* The data can be inserted to a specific table or a group of   */ 
/* them. 					                                              */
/****************************************************************/
void CDBFunction::UpdateStatus ( char* pc_appliance ) {
  stringstream ssLog; 
  stringstream ssCondition; 
  int nRows; 

  if(pc_appliance == NULL){
    nRows = m_pcMysql->RowCounter(m_vMysqlTables[APP_STATUS].sName.c_str(),"id",NULL);
    for(int app=0; app<m_vApp.size(); app++)
      UpdateStatusAppliance(nRows, app);
  } else {
    ssCondition<<"id="<<atoi(pc_appliance)+1<<endl;
    nRows = m_pcMysql->RowCounter(m_vMysqlTables[APP_STATUS].sName.c_str(),"id",(ssCondition.str()).c_str());
    UpdateStatusAppliance(nRows, atoi(pc_appliance));
  }

  ssLog<<"CDBFunctions::UpdateStatus==>Update the status of the appliances in table "<<m_vMysqlTables[APP_STATUS].sName.c_str()<<" succesfully";
  writeLogFile (m_sLogFile,3, (ssLog.str()).c_str());
  
	return;
};
/****************************************************************/
/* INSERT STATUS FUNCTION																				*/
/* Insert the processed data in the tables of the MySQL DB. 		*/
/* The data can be inserted to a specific table or a group of   */ 
/* them. 					                                              */
/****************************************************************/
void CDBFunction::UpdateStatusAppliance ( int n_rows, int n_app ) {
  TSV vAppStatus;
  TSV vAppMysql;
  stringstream ssParams; 
  stringstream ssValues; 

  vAppStatus = m_vApp[n_app]->Update();
  vAppMysql = m_vApp[n_app]->getMysqlStatus();

  if(n_rows == 0){
    //ID of the appliance
    ssParams<<vAppMysql[0]<<","<<vAppMysql[1]<<",";
    ssValues<<n_app+1<<",\""<<m_vApp[n_app]->getSoapID()<<"\",";
    //Status of the appliance
    ssParams<<vAppMysql[2]<<",";
    if(vAppStatus[1].compare("4") == 0 || vAppStatus[1].compare("5") == 0)
      ssValues<<"1,";
    else
      ssValues<<"0,";
    //The parameters of the appliance to update
    for(int s=3; s<vAppMysql.size(); s++){
      if(vAppStatus[s].compare(" ")==0)
        vAppStatus[s]="0";
      ssParams<<vAppMysql[s];
      ssValues<<vAppStatus[s];
      if(s!=vAppMysql.size()-1){
        ssParams<<",";
        ssValues<<",";
      }
    }
    m_pcMysql->Insert(m_vMysqlTables[APP_STATUS].sName.c_str(),(ssParams.str()).c_str(),(ssValues.str()).c_str());
    ssParams.str("");

  }else{
    ssParams<<"ID="<<n_app+1;
    //Status of the appliance
    ssValues<<vAppMysql[2]<<"=";
    if(vAppStatus[1].compare("4") == 0 || vAppStatus[1].compare("5") == 0)
      ssValues<<"1,";
    else
      ssValues<<"0,";
    //The parameters of the appliance to update
    for(int s=3; s<vAppMysql.size(); s++){
      ssValues<<vAppMysql[s]<<"="<<vAppStatus[s];
      if(s!=vAppMysql.size()-1)
        ssValues<<",";
    }

    m_pcMysql->UpdateValue(m_vMysqlTables[APP_STATUS].sName.c_str(),(ssValues.str()).c_str(),(ssParams.str()).c_str());
    ssParams.str("");
  }
  ssValues.str("");
};
/****************************************************************/
/* ACTUATION FUNCTION																				    */
/* Select the program from the table corresponding to the       */
/* appliance                                                    */
/****************************************************************/
void CDBFunction::Actuation ( void ) {
  
  int nRows;
  int nExecTime;
  int nError=-1;
  stringstream ssCondition;
  stringstream ssLog;
  time_t result;
	int nNumFields;
  MYSQL_ROW  MySQLRow;
  MYSQL_RES* pMySQLResult;
  TSV vsProgram;
  result = getTime();

  for(int tab=1; tab<m_vMysqlTables.size(); tab++){
    ssCondition<<"start_timestamp >= "<<result<<" ORDER BY start_timestamp";
    nRows = m_pcMysql->RowCounter(m_vMysqlTables[tab].sName.c_str(),(m_vMysqlTables[tab].vColName[0]).c_str(),(ssCondition.str()).c_str());
    if( nRows > 0 ){
      /*Get the correspondant elements of the table*/
      pMySQLResult = m_pcMysql->FetchTable (m_vMysqlTables[tab].sName.c_str(),"*",(ssCondition.str()).c_str());
      /* Get Number of Fields */
      nNumFields = mysql_num_fields(pMySQLResult);
      /* Get the first row that is equal to the condition */
      MySQLRow = mysql_fetch_row(pMySQLResult);
      /* Check the execution time */
      if ( MySQLRow[EXEC_TIME] == NULL )
        nExecTime = abs(atoi(MySQLRow[START_TIME])-result);
      else
        nExecTime = abs(atoi(MySQLRow[EXEC_TIME])-result);
      /* If it is the same time */
      if( nExecTime == 0 ){
        /* For every field */
        for(int fieldIndex=PROGRAM; fieldIndex < nNumFields; fieldIndex++) 
          vsProgram.push_back(MySQLRow[fieldIndex]);
        nError = m_vApp[tab-1]->DBProgram(tab-1,vsProgram);
        if( nError == -1){
          ssLog<<"CDBFunctions::Actuation==>The program of the table "<<m_vMysqlTables[APP_STATUS].sName.c_str()<<" was not sent";
          writeLogFile (m_sLogFile,2, (ssLog.str()).c_str());
        }else{
          m_pcMysql->DeleteValueTable (m_vMysqlTables[tab].sName.c_str(),(ssCondition.str()).c_str());
          ssLog<<"CDBFunctions::Actuation==>The program of the table "<<m_vMysqlTables[APP_STATUS].sName.c_str()<<" succesfully updated";
          writeLogFile (m_sLogFile,23, (ssLog.str()).c_str());
        }
      }
    }
    ssCondition.str("");
    vsProgram.clear();
  }
  return;
};
/****************************************************************/
/* GET TIME FUNCTION																				    */
/* Get the time in the 0 seconds                                */
/****************************************************************/
time_t CDBFunction::getTime ( void ) {
  time_t tRawTime;
  struct tm * timeinfo;

  time(&tRawTime);
  timeinfo = localtime (&tRawTime);
  timeinfo->tm_sec=0;
  tRawTime=mktime(timeinfo);

  return tRawTime;
};
