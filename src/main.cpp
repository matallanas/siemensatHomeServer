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

/******************************************************************************/
/* APPLIANCES COMMUNICATION PROGRAM (appCom) MAIN FILE                        */
/******************************************************************************/

/******************************************************************************/
/* MAIN LIBRARIES                                                             */ 
/******************************************************************************/
#include "common.h"

#include "mysqldb.h"
#include "soapSAHBindingProxy.h"

#include "testgSoap.h"
#include "dbfunction.h"
#include "appliance.h"

/******************************************************************************/
/* FUNCTIONS PART OF THE MAIN FILE																						*/ 
/******************************************************************************/
void usage( void );
void printTestsID( void );
void _commConfig( string s_config_file, SAHBindingProxy** pc_soap_service, CMysqlDB** pm_magicbox_db, string* s_load_db, string* s_mysql_conf );
void _loadDBInit( string s_load_config, SAHBindingProxy* pc_soap_service, TAppV* v_app_house );
/******************************************************************************/
/* MAIN FUNCTION																															*/
/******************************************************************************/
int main (int argc, char ** argv) {

  string sCommConfig;
  SAHBindingProxy* pcSoapService; 
  CMysqlDB* pmMagicboxDB; 
  TAppV vAppHouse;
  string sLoadDB;
  string sMysqlParams;
  bool bFile=false;
  int nTestNumber = -1;
  int nDBOperation = -1;
  char* pcTable[]={NULL}; 
  //char* cMysqlconf = NULL; // Input Filename

  if (argc < 2 ) {
    usage();
    exit(-1);
  }
  /*Check if the param file is indicated*/
  for(int i=1; i<argc; i++) {
		switch(argv[i][1]) { //switch on current argument
			/* Get Input File */
			case 'p':
				++i;
				sCommConfig.assign(argv[i]);
				cout << " Filename: " << sCommConfig << " CHOOSEN." << endl;
        bFile=true;
				break;			
      /* Get comm Info */
      case 't':
				if(i==argc-1){
          printTestsID();
					exit(-1);
				}
				i++;
				if(argv[i][0] == '-'){
          printTestsID();
					exit(-1);
				}
				nTestNumber = atoi(argv[i]);
				cout << "TEST " << nTestNumber << " CHOOSEN" << endl;
        break;
			/* Execute action */
			case 'a':
				i++;
				nDBOperation = ACTUATION;
				break;
			/* Create Table */
      case 'c':
        ++i;
				if(argv[i]!=NULL)
					pcTable[0]=argv[i];
        nDBOperation = CREATE_TABLE;
        break;
			/* Drop Table */
			case 'd':
				i++;
				if(argv[i]!=NULL)
					pcTable[0]=argv[i];
				nDBOperation = DELETE_TABLE;
				break;
			/* Drop Table */
			case 'D':
				i++;
				if(argv[i]!=NULL)
					pcTable[0]=argv[i];
				nDBOperation = DROP_TABLE;
				break;
			/* Drop Table */
			case 'u':
				i++;
				if(argv[i]!=NULL)
					pcTable[0]=argv[i];
				nDBOperation = UPDATE_STATUS;
				break;
			/* Drop Table */
			case 'h':
        usage();
        break;
			/* Option not recognized*/
			default:
				cout << "ERROR: Option not recognized" << endl;
        usage();
        exit(-1);
				break;
		}
  }

  if(!bFile){
    cout<<"MAIN ==> ERROR THERE IS NOT PARAM FILE"<<endl;
    exit(-1);
  }

  _commConfig(sCommConfig, &pcSoapService, &pmMagicboxDB, &sLoadDB, &sMysqlParams);
  _loadDBInit(sLoadDB, pcSoapService, &vAppHouse);

	if ( nTestNumber != -1 ) {
		CtestgSoap* pcTest = new CtestgSoap(pcSoapService, vAppHouse);
    pcTest->TestMain(nTestNumber);
	}
  if ( nDBOperation != -1 ) {
    CDBFunction* pcDBoperator = new CDBFunction(pmMagicboxDB, vAppHouse, sMysqlParams); 
    pcDBoperator->dbOperation(nDBOperation, pcTable[0]);
  }
};
/******************************************************************************/
/* CONFIGURATION COMM FUNCTION        																				*/
/* Configuration of the different communication servers for the communication */
/* of the appliances and the database 											                  */
/******************************************************************************/
void _commConfig( string s_config_file, SAHBindingProxy** pc_soap_service, CMysqlDB** pm_magicbox_db, string* s_load_db, string* s_mysql_conf){
  
	XMLDocument conf;
    	conf.LoadFile( s_config_file.c_str() );
	XMLElement* root = conf.FirstChildElement();
	string elemName , attr;	
  string sOutDataFolder, sCnfFolder;
	for( XMLElement* elem = root->FirstChildElement() ; elem != NULL ; elem = elem->NextSiblingElement() ){
		elemName = elem->Value();
		if ( elemName == "data" ) {
      sOutDataFolder = elem->Attribute("output");
      sCnfFolder = elem->Attribute("configuration");
		} else if ( elemName == "soapServer" ) {
      char cAux[128];
      sprintf(cAux,"http://%s:%s/sah-ws",elem->Attribute("ip"),elem->Attribute("port"));
      *pc_soap_service = new SAHBindingProxy();
      (*pc_soap_service)->soap_endpoint=strdup(cAux);
		} else if ( elemName == "mysql" ) {
      
      MySQL_Param smMysqlAux;
      string sLogFileAux = sOutDataFolder;
      
      smMysqlAux.sHost = elem->Attribute("host");  
      smMysqlAux.sUser = elem->Attribute("user");
      smMysqlAux.sPass = elem->Attribute("pass");
      smMysqlAux.sDb = elem->Attribute("database");

      sLogFileAux.append(elem->Attribute("log"));

      *pm_magicbox_db = new CMysqlDB (smMysqlAux, sLogFileAux);

      s_mysql_conf->assign(sCnfFolder); 
      s_mysql_conf->append(elem->Attribute("cnf"));

		} else if ( elemName == "appliances" ) {
      s_load_db->assign(sCnfFolder);
      s_load_db->append(elem->Attribute("cnf"));
    }
	}
  conf.Clear();
  
  return;
}
/******************************************************************************/
/* LOAD DB FUNCTION                    																				*/
/* Configuration of the different appliances that compose the siemens@Home    */
/* server.                                                                    */
/******************************************************************************/
void _loadDBInit( string s_load_config, SAHBindingProxy* pc_soap_service, TAppV* v_app_house ){

	XMLDocument conf;
    	conf.LoadFile( s_load_config.c_str() );
	XMLElement* root = conf.FirstChildElement();
	string elemName , appElemName, vars;	
  sApp sAppAux;
	for( XMLElement* elem = root->FirstChildElement() ; elem != NULL ; elem = elem->NextSiblingElement() ){
		elemName = elem->Value();
    sAppAux.nID = atoi(elem->Attribute("id")); 
    sAppAux.sSoapID = elem->Attribute("soap_id"); 
	  for( XMLElement* app = elem->FirstChildElement() ; app != NULL ; app = app->NextSiblingElement() ){
      appElemName = app->Value();
      if(appElemName == "parameters")
        for( XMLElement* param = app->FirstChildElement() ; param != NULL ; param = param->NextSiblingElement() )
          sAppAux.vsVariables.push_back(param->Attribute("name"));
      else if(appElemName == "mysql")
        for( XMLElement* param = app->FirstChildElement() ; param != NULL ; param = param->NextSiblingElement() )
          sAppAux.vsDBstatus.push_back(param->Attribute("col"));
      else if(appElemName == "actions")
        for( XMLElement* param = app->FirstChildElement() ; param != NULL ; param = param->NextSiblingElement() )
          sAppAux.vsActions.push_back(param->Attribute("name"));
    }
    CAppliance* cApp = new CAppliance (pc_soap_service, sAppAux); 
    v_app_house->push_back(cApp);
    sAppAux.vsVariables.clear();
    sAppAux.vsDBstatus.clear();
    sAppAux.vsActions.clear();
  } 
  conf.Clear();
};
/******************************************************************************/
/* USAGE FUNCTION																															*/
/* Print the help needed to execute this software															*/
/******************************************************************************/
void usage( void ) {
	cout << "\nERROR: ./mysql_soft [-p <files_path>] [rest of the options]" << endl;
  cout << "OPTIONS: "<<endl;
  cout << " -a\tCheck the programs of the appliances and actuate\n   \tover them." <<endl;
  cout << endl;
  cout << " -c\tCreate a table in the database" <<endl;
  cout << "   \t  You can provide the name of the table from the .xml\n   \t  that you want to create. Otherwise is going to create\n   \t  all the tables availavle in the configuration xml\n   \t  file." <<endl;
  cout << endl;
  cout << " -D\tDrop a table in the database" <<endl;
  cout << "   \t  You can provide the name of the table from the .xml\n   \t  that you want to drop. Otherwise is going to drop\n   \t  all the tables availavle in the configuration xml\n   \t  file." <<endl;
  cout << endl;
  cout << " -d\tDelete the values of a table" <<endl;
  cout << "   \t  You can provide the name of the table from the .xml\n   \t  that you want to delete. Otherwise is going to delete\n   \t  all the values of tables availavle in the configuration\n   \t  xml file." <<endl;
  cout << endl;
  cout << " -u\tUpdate the status of the different appliances" <<endl;
  cout << "   \t  You can provide the ID of the appliance to check only\n   \t  one of all available appliances. If the ID is not\n   \t  specified, it is going to check the status of all the\n   \t  appliances." << endl;
  cout << endl;
  cout << " -h\tShows this help" <<endl;
  cout << endl;
	exit(0);
};
/******************************************************************************/
/******************************************************************************/

void printTestsID ( void ) {

	cout << "TESTS IDENTIFIERS" << endl;
	cout << endl;
	cout << "1  - Selected appliance execute action" << endl;
	cout << "2  - I.D. of the appliances" << endl;
	cout << "3  - Available actions of an appliance " << endl;
	cout << "4  - General status" << endl;
	cout << "5  - Status of an appliance" << endl;
	cout << "6  - Extended status of an appliance" << endl;
	cout << "7  - Events" << endl;
	cout << "8  - Server date " << endl;
	cout << "9  - All appliance information " << endl;
	cout << "10 - Extended information of all appliances " << endl;
	cout << "11 - Communication with the loads to set different parameters " << endl;
}
