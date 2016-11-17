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
/*******************************************************************************/
/* MYSQL DB METHODS																											       */
/* This file implements the API to communicate and manage the data base in c++.*/
/* It connects with the specified DB and ask the DB to do different tasks.		 */
/* - Connect/Disconnect																												 */
/* - Create Database																													 */
/* - Create Tables																														 */
/* - Delete Values from the different tables																	 */
/* - Drop values																															 */
/* - Insert Values																														 */
/* - Fetch Data																																 */
/*******************************************************************************/

#include "mysqldb.h"

/******************************************************************************/
/* CONSTRUCTOR 																																*/
/* The constructor initializes the different paramaters, the connection to    */
/* the DB, host, user, name of the DB and password.														*/
/******************************************************************************/
CMysqlDB::CMysqlDB ( MySQL_Param sm_mysql_param, string s_log_file) { 
	/* Log File */
	m_sLogFile = s_log_file; 

	char cAuxLog[512];
	/* Initialize MySQL DB */
	if (mysql_library_init(0, NULL, NULL)) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,1,"CMysqlDB::CMysqlDB==>COULD NOT INITIALIZE MySQL LIBRARY");
		return;
	}
	
	mysql_init(&m_pMysql);
	mysql_options(&m_pMysql,MYSQL_READ_DEFAULT_GROUP,"main");
	/* Parameters Of the DB */
  m_sMysqlParams.sHost = sm_mysql_param.sHost;
  m_sMysqlParams.sUser = sm_mysql_param.sUser;
  m_sMysqlParams.sPass = sm_mysql_param.sPass;
  m_sMysqlParams.sDb = sm_mysql_param.sDb;
	/* LOG FILE */
	if (m_sMysqlParams.sHost.empty() || m_sMysqlParams.sUser.empty() || m_sMysqlParams.sPass.empty() || m_sMysqlParams.sDb.empty() ) {
		writeLogFile (m_sLogFile,1,"CMysqlDB::CMysqlDB==> THERE IS NO HOST, USER OR DATABASE SELECTED");
		exit(-1);
		return;	
	}
	/* Connect to DB */
	if (!mysql_real_connect(&m_pMysql,m_sMysqlParams.sHost.c_str(),m_sMysqlParams.sUser.c_str(),m_sMysqlParams.sPass.c_str(),m_sMysqlParams.sDb.c_str(),0,NULL,0)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::CMysqlDB==>FAILED TO CONNECT TO DATABASE: ERROR: %s ",mysql_error(&m_pMysql));
		writeLogFile (m_sLogFile,1,cAuxLog);
		return;
	}

	/* LOG FILE */
	sprintf(cAuxLog,"MysqlDB => Connection stablished with the host %s, user %s  and database %s",m_sMysqlParams.sHost.c_str(),m_sMysqlParams.sUser.c_str(),m_sMysqlParams.sDb.c_str());
	writeLogFile (m_sLogFile,3,cAuxLog);
	writeLogFile (m_sLogFile,3,"CMysqlDB::CMysqlDB==>MySQL INITIALIZATION SUCCESFUL");

	/*DEBUG*/
	//cout << "\nConnection stablished with the host "<< m_sMysqlParams.cHost << ", user " << m_sMysqlParams.cUser <<" and database " << m_sMysqlParams.cDb << "\n" << endl; 
	/*DEBUG*/
};
/******************************************************************************/
/* DESTRUCTOR 																																*/
/******************************************************************************/
CMysqlDB::~CMysqlDB ( void ) {
	return;
};
/******************************************************************************/
/* CONNECT FUNCTION																														*/
/* Stablish the communication with the DB.																		*/
/******************************************************************************/
void CMysqlDB::Connect ( void ) {
	char cAuxLog[512];
	
	mysql_init(&m_pMysql);
	mysql_options(&m_pMysql,MYSQL_READ_DEFAULT_GROUP,"main");
	
	if (!mysql_real_connect(&m_pMysql,m_sMysqlParams.sHost.c_str(),m_sMysqlParams.sUser.c_str(),m_sMysqlParams.sPass.c_str(),m_sMysqlParams.sDb.c_str(),0,NULL,0)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::CMysqlDB==>FAILED TO CONNECT TO DATABASE: ERROR: %s ",mysql_error(&m_pMysql));
		writeLogFile (m_sLogFile,1,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* CONNECT FUNCTION																														*/
/* Stablish the communication with the DB.																		*/
/******************************************************************************/
void CMysqlDB::Connect ( MySQL_Param sc_mysql_params ) {
	/* Close previous connections */
	mysql_close(&m_pMysql);
	/* Initialize DB */
	if (mysql_library_init(0, NULL, NULL)) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,1,"CMysqlDB::Connect==>COULD NOT INITIALIZE MySQL LIBRARY");
		return;
	}

	mysql_init(&m_pMysql);
	mysql_options(&m_pMysql,MYSQL_READ_DEFAULT_GROUP,"main");
	/* LOG FILE */
  //if (sc_mysql_params.cHost[0] == '\000' || sc_mysql_params.cUser[0] == '\000' || sc_mysql_params.cPass[0] == '\000' || sc_mysql_params.cDb[0] == '\000' ) {
	if ( m_sMysqlParams.sHost.empty() || m_sMysqlParams.sUser.empty() || m_sMysqlParams.sPass.empty() || m_sMysqlParams.sDb.empty() ) {
		writeLogFile (m_sLogFile,1,"CMysqlDB::Connect==>THERE IS NO HOST, USER OR DATABASE SELECTED");
		exit(-1);
		return;	
	}
	/* Connection to the DB*/
    //if (!mysql_real_connect(&m_pMysql,sc_mysql_params.cHost,sc_mysql_params.cUser,sc_mysql_params.cPass,sc_mysql_params.cDb,0,NULL,0)) {
	if (!mysql_real_connect(&m_pMysql,m_sMysqlParams.sHost.c_str(),m_sMysqlParams.sUser.c_str(),m_sMysqlParams.sPass.c_str(),m_sMysqlParams.sDb.c_str(),0,NULL,0)) {
		/* LOG FILE */
		char caux[512];
		sprintf(caux,"CMysqlDB::Connect==>FAILED TO CONNECT TO DATABASE: ERROR: %s ",mysql_error(&m_pMysql));
		writeLogFile (m_sLogFile,1,caux);
		return;
	}
	return;
};
/******************************************************************************/
/* DISCONNECT FUNCTION																												*/
/* Disconnect the communication from DB.																			*/
/******************************************************************************/
void CMysqlDB::Disconnect ( void ) { 
	mysql_close(&m_pMysql);
	mysql_library_end();
	return;
};
/******************************************************************************/
/* DELETE A VALUE OF TABLE FUNCTION																						*/
/* Delete a value inside a certain table of the DB.														*/
/******************************************************************************/
void CMysqlDB::DeleteValueTable ( const char* pc_table, const char* pc_condition ) { 
	/* QUERY TO DB*/
	char pcQuery[1024];
	/*Delete a value of a date and a certain time*/
	if ( pc_condition == NULL )
		sprintf(pcQuery,"DELETE FROM %s", pc_table);
	/*Delete the values of a certain condition*/
	else if (pc_condition != NULL)
	  sprintf(pcQuery,"DELETE FROM %s WHERE %s", pc_table, pc_condition);
	/* Send Query */
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::DeleteValueTable==> Failed to delete the value of the table %s with index %s",pc_table,pc_condition);
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* INSERT VALUES IN A TABLE FUNCTION																					*/
/* Insert values inside a certain table of the DB.														*/
/******************************************************************************/
void CMysqlDB::Insert (const char* pc_table, const char* pc_field, const char* pc_value) {
	/* QUERY TO DB */
	char pcQuery[2048];
	sprintf(pcQuery,"INSERT INTO %s (%s) VALUES (%s)",pc_table,pc_field,pc_value);
	/* Send Query */
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::Insert==>Failed to insert the values in table %s", pc_table); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* CREATE TABLES IN DB FUNCTION																								*/
/* Create a table with the fields indicated inside the DB.										*/
/******************************************************************************/
void CMysqlDB::CreateTable (const char* pc_table, const char* pc_field) {
	/* QUERY TO DB */
	char pcQuery[1024];
	sprintf(pcQuery,"CREATE TABLE %s (%s)",pc_table,pc_field);
	/* Send Query */
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::CreateTable==>Failed to create table %s. Maybe it has been already created or the name is incorrect.", pc_table); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* DROP TABLES IN DB FUNCTION																									*/
/* Drop a table inside the DB.																								*/
/******************************************************************************/
void CMysqlDB::DropTable (const char* pc_table) {
	/* QUERY TO DB */
	char pcQuery[2048];
	sprintf(pcQuery,"DROP TABLE %s",pc_table);
	/* Send Query */
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::DropTable==>Failed to drop table %s. Maybe it has been already dropped or the name is incorrect.", pc_table); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* CREATE DB FUNCTION																													*/
/* Create a DataBase in the specified MySQL Server.														*/
/******************************************************************************/
void CMysqlDB::CreateDataBase (const char* pc_db) {
	/* QUERY TO DB */
	char pcQuery[1024];
	sprintf(pcQuery,"CREATE DATABASE %s",pc_db);
	/* SEND QUERY */	
	if(mysql_query(&m_pMysql,pcQuery)){
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::CreateDataBase==>Failed to create database %s",pc_db); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* DROP DB FUNCTION																														*/
/* Drop a DataBase in the specified MySQL Server. 														*/
/******************************************************************************/
void CMysqlDB::DropDataBase (const char* pc_db) {
	/* QUERY TO DB */
	char pcQuery[1024];
	sprintf(pcQuery,"DROP DATABASE %s",pc_db);
	/* SEND QUERY */	
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::DropDataBase==>Failed to drop database %s",pc_db); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}
	return;
};
/******************************************************************************/
/* ROW COUNTER FUNCTION																												*/
/* Count the number of rows of a table of the DB based on the conditions, 		*/
/* counting the number of coincidences.					  														*/
/******************************************************************************/
int CMysqlDB::RowCounter (const char* pc_table, const char* pc_field, const char* pc_condition) {
	/* QUERY TO DB */
	char pcQuery[1024];
	/* Response of DB*/
	MYSQL_RES* pMysqlRes;
	int nRows = 0;

  /* Select the value without condition */
  if(pc_condition==NULL)
		sprintf(pcQuery,"SELECT %s FROM %s",pc_field,pc_table,pc_condition);
	/*Select the value for the two conditions*/
  else if(pc_condition!=NULL)
		/* Two conditions */
		sprintf(pcQuery,"SELECT %s FROM %s WHERE %s",pc_field,pc_table,pc_condition);
	else {	
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::RowCounter==>Wrong conditions for selecting value, both are NULL");
		return -1;
	}	
	/* SEND QUERY */
	if(mysql_query(&m_pMysql,pcQuery)) {
		char cAuxLog[512];
		sprintf(cAuxLog, "CMysqlDB::RowCounter==> Failed to select all in table %s", pc_table); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return -1;
	}	
	/* Result of sending the query*/
	pMysqlRes = mysql_store_result(&m_pMysql);
	/* Number of Rows */
	nRows = pMysqlRes->row_count;
	/* Free Space */
	mysql_free_result(pMysqlRes);

	return nRows;
};
/******************************************************************************/
/* UPDATE VALUE FUNCTION																											*/
/* Update the value of a defined field of a table inside the DB based on 			*/
/* different conditions.																											*/
/******************************************************************************/
void CMysqlDB::UpdateValue (const char* pc_table, const char* pc_value, const char* pc_condition) {
	/* QUERY TO DB */
	char pcQuery[1024];
	/* Update the value for the two conditions */
	if(pc_condition!=NULL)
		sprintf(pcQuery,"UPDATE %s SET %s WHERE %s", pc_table,pc_value,pc_condition);
	else {	
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::UpdateValue==>Wrong conditions for update value, there is no condition to update");
		return;
	}	
	/* SEND QUERY */
	if(mysql_query(&m_pMysql,pcQuery)){
		/* LOG FILE */
		char cAuxLog[512];
		sprintf(cAuxLog,"CMysqlDB::UpdateValue==>Failed to update value in table %s", pc_table ); 
		writeLogFile (m_sLogFile,2,cAuxLog);
		return;
	}	
	return;
};
/******************************************************************************/
/* FETCH DATA TYPE STRING FUNCTION																						*/
/* Fetch a type string of the DB from a specific table based of different 		*/
/* conditions.																																*/
/******************************************************************************/
string CMysqlDB::FetchDataString ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows) { 
	char cAuxLog[512];
	/* Initial parameters to fetch the data */	
	MYSQL_STMT    *stmt;
	MYSQL_BIND    bind[1];
	MYSQL_RES     *prepare_meta_result;
	unsigned long length[1];
	int           param_count, row_count;
	char          str_data[STRING_SIZE];
	my_bool       is_null[1];
	my_bool       error[1];
	char 				  cSelect[100];	
	/* Query to DB */
	/* SELECT the data based on the two conditions */
	if(pc_condition==NULL)
		sprintf(cSelect,"SELECT %s FROM %s", pc_field_name, pc_table);
		/* SELECT the data based on one condition */
	else if (pc_condition!=NULL)
		sprintf(cSelect,"SELECT %s FROM %s WHERE %s", pc_field_name, pc_table,pc_condition);
	else {	
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataString==>Wrong conditions both are NULL");
		return VOID_CHAR;
	}	
	/* Prepare a SELECT query to fetch data from test_table */
	stmt = mysql_stmt_init(&m_pMysql);
	/* Check if it is valid */
	if (!stmt) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataString==>mysql_stmt_init(), out of memory");
		return VOID_CHAR;
	}
	/* Prepare the statement to send to the DB */
	if (mysql_stmt_prepare(stmt, cSelect, strlen(cSelect))) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>mysql_stmt_prepare(), SELECT failed %s" ,mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Get the parameter count from the statement */
	param_count= mysql_stmt_param_count(stmt);
	/* validate parameter count */	
	if (param_count != 0) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataString==>Invalid parameter count returned by MySQL");
		return VOID_CHAR;
	}
	/* Fetch result set meta information */
	prepare_meta_result = mysql_stmt_result_metadata(stmt);
	/* Check the result */
	if (!prepare_meta_result) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>mysql_stmt_result_metadata(), returned no meta information %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Execute the SELECT query */
	if (mysql_stmt_execute(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>mysql_stmt_execute(), failed %s" ,mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Bind the result buffers for all 4 columns before fetching them */
	memset(bind, 0, sizeof(bind));
	/* STRING COLUMN */
	bind[0].buffer_type= MYSQL_TYPE_STRING;
	bind[0].buffer= (char *)str_data;
	bind[0].buffer_length= STRING_SIZE;
	bind[0].is_null= &is_null[0];
	bind[0].length= &length[0];
	bind[0].error= &error[0];
	/* Bind the result buffers */
	if (mysql_stmt_bind_result(stmt, bind)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>mysql_stmt_bind_result() failed %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Now buffer all results to client (optional step) */
	if (mysql_stmt_store_result(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>mysql_stmt_store_result() failed %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Stablish the cursor in teh row selected */
	mysql_stmt_data_seek(stmt, n_rows);
	/* Fetch the data */
	if (mysql_stmt_fetch(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>It does not fetch anything from row %d",n_rows);	
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Free the prepared result metadata */
	mysql_free_result(prepare_meta_result);
	/* Close the statement */
	if (mysql_stmt_close(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataString==>Failed while closing the statement %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return VOID_CHAR;
	}
	/* Data result */
	string data = str_data;
	if(is_null[0])
		return VOID_CHAR;
	else		
	 return data;
};
/******************************************************************************/
/* FETCH DATA TYPE DOUBLE FUNCTION																						*/
/* Fetch a type double of the DB from a specific table based of different 		*/
/* conditions.																																*/
/******************************************************************************/
double CMysqlDB::FetchDataDouble ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows ) { 
	char 					cAuxLog[512];
	/* Initial parameters to fetch the data */	
	MYSQL_STMT    *stmt;
	MYSQL_BIND    bind[1];
	MYSQL_RES     *prepare_meta_result;
	unsigned long length[1];
	int           param_count, row_count;
	double        data;
	my_bool       is_null[1];
	my_bool       error[1];
	char 				  cSelect[100];	
	/* Query to DB */
	/* SELECT the data based on the two conditions */
	if ( pc_condition == NULL )
		sprintf(cSelect,"SELECT %s FROM %s", pc_field_name, pc_table);
		/* SELECT the data based on one condition */
	else if ( pc_condition != NULL )
		sprintf(cSelect,"SELECT %s FROM %s WHERE %s", pc_field_name, pc_table, pc_condition);
	else {	
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataDouble==>Wrong conditions both are NULL");
		return DBL_MIN;
	}	
	/* Prepare a SELECT query to fetch data from test_table */
	stmt = mysql_stmt_init(&m_pMysql);
	/* Check if it is valid */
	if (!stmt) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataDouble==>mysql_stmt_init(), out of memory");
		return DBL_MIN;
	}
	/* Prepare the statement to send to the DB */
	if (mysql_stmt_prepare(stmt, cSelect, strlen(cSelect))) {
		/* LOG FILE */
		sprintf(cAuxLog, "CMysqlDB::FetchDataDouble==>mysql_stmt_prepare(), SELECT failed %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Get the parameter count from the statement */
	param_count= mysql_stmt_param_count(stmt);
	/* validate parameter count */	
	if (param_count != 0)  {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataDouble==>Invalid parameter count returned by MySQL");
		return DBL_MIN;
	}
	/* Fetch result set meta information */
	prepare_meta_result = mysql_stmt_result_metadata(stmt);
	/* Check the result */
	if (!prepare_meta_result) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>mysql_stmt_result_metadata(), returned no meta information %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Execute the SELECT query */
	if (mysql_stmt_execute(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>mysql_stmt_execute(), failed %s" ,mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Bind the result buffers for all 4 columns before fetching them */
	memset(bind, 0, sizeof(bind));
	/* DOUBLE COLUMN */
	bind[0].buffer_type= MYSQL_TYPE_DOUBLE;
	bind[0].buffer= (char*)&data;
	bind[0].is_null= &is_null[0];
	bind[0].length= &length[0];
	bind[0].error= &error[0];
	/* Bind the result buffers */
	if (mysql_stmt_bind_result(stmt, bind)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>mysql_stmt_bind_result() failed %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Now buffer all results to client (optional step) */
	if (mysql_stmt_store_result(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>mysql_stmt_store_result() failed %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Stablish the cursor in teh row selected */
	mysql_stmt_data_seek(stmt, n_rows);
	/* Fetch the data */
	if (mysql_stmt_fetch(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>It does not fetch anything from row %d",n_rows);	
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Free the prepared result metadata */
	mysql_free_result(prepare_meta_result);
	/* Close the statement */
	if (mysql_stmt_close(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataDouble==>Failed while closing the statement %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return DBL_MIN;
	}
	/* Data result */
	if(is_null[0])
		return DBL_MIN;
	else		
	 return data;
};
/******************************************************************************/
/* FETCH DATA TYPE INTEGER FUNCTION																						*/
/* Fetch a type integer of the DB from a specific table based of different 		*/
/* conditions.																																*/
/******************************************************************************/
int CMysqlDB::FetchDataInt ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows ) { 
	char 					cAuxLog[512];
	/* Initial parameters to fetch the data */	
	MYSQL_STMT    *stmt;
	MYSQL_BIND    bind[1];
	MYSQL_RES     *prepare_meta_result;
	unsigned long length[1];
	int           param_count, row_count;
	int		        data;
	my_bool       is_null[1];
	my_bool       error[1];
	char 				  cSelect[100];	
	/* Query to DB */
	/* SELECT the data based on the two conditions */
	if ( pc_condition == NULL )
		sprintf(cSelect,"SELECT %s FROM %s", pc_field_name, pc_table);
	/* SELECT the data based on one condition */
	else if ( pc_condition != NULL )
		sprintf(cSelect,"SELECT %s FROM %s WHERE %s", pc_field_name, pc_table, pc_condition);
	/* LOG FILE */
	else {	
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataInt==>Wrong conditions both are NULL");
		return INT_MIN;
	}	
	/* Prepare a SELECT query to fetch data from test_table */
	stmt = mysql_stmt_init(&m_pMysql);
	/* Check if it is valid */
	if (!stmt) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataInt==>mysql_stmt_init(), out of memory");
		return INT_MIN;
	}
	/* Prepare the statement to send to the DB */
	if (mysql_stmt_prepare(stmt, cSelect, strlen(cSelect))) {
		/* LOG FILE */
		sprintf(cAuxLog, "CMysqlDB::FetchDataInt==>mysql_stmt_prepare(), SELECT failed %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Get the parameter count from the statement */
	param_count= mysql_stmt_param_count(stmt);
	/* validate parameter count */	
	if (param_count != 0) {
		/* LOG FILE */
		writeLogFile (m_sLogFile,2,"CMysqlDB::FetchDataInt==>Invalid parameter count returned by MySQL");
		return INT_MIN;
	}
	/* Fetch result set meta information */
	prepare_meta_result = mysql_stmt_result_metadata(stmt);
	/* Check the result */
	if (!prepare_meta_result) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>mysql_stmt_result_metadata(), returned no meta information %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Execute the SELECT query */
	if (mysql_stmt_execute(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>mysql_stmt_execute(), failed %s" ,mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Bind the result buffers for all 4 columns before fetching them */
	memset(bind, 0, sizeof(bind));
	/* DOUBLE COLUMN */
	bind[0].buffer_type= MYSQL_TYPE_LONG;
	bind[0].buffer= (char*)&data;
	bind[0].is_null= &is_null[0];
	bind[0].length= &length[0];
	bind[0].error= &error[0];
	/* Bind the result buffers */
	if (mysql_stmt_bind_result(stmt, bind)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>mysql_stmt_bind_result() failed %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Now buffer all results to client (optional step) */
	if (mysql_stmt_store_result(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>mysql_stmt_store_result() failed %s",mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Stablish the cursor in the row selected */
	mysql_stmt_data_seek(stmt,n_rows);
	/* Fetch the data */
	if (mysql_stmt_fetch(stmt)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>It does not fetch anything from row %d",n_rows);	
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Free the prepared result metadata */
	mysql_free_result(prepare_meta_result);
	/* Close the statement */
	if (mysql_stmt_close(stmt)) {
		sprintf(cAuxLog,"CMysqlDB::FetchDataInt==>Failed while closing the statement %s", mysql_stmt_error(stmt));
		writeLogFile (m_sLogFile,2,cAuxLog);
		return INT_MIN;
	}
	/* Data result */
	if(is_null[0])
		return INT_MIN;
	else		
	 return data;
};
/******************************************************************************/
/* FETCH TABLE FUNCTION																												*/
/* Fetch a table of the DB from a specific table based of different 					*/
/* conditions.																																*/
/******************************************************************************/
MYSQL_RES* CMysqlDB::FetchTable ( const char *pc_table, const char* pc_field_name, const char* pc_condition ) { 
	char cAuxLog[512];
	/* QUERY TO DB */
	char pcQuery[2048];
	MYSQL_RES* pcMySQLResult;

	/* Query to DB */
	/* SELECT the data based on the two conditions */
  if ( pc_condition == NULL )
    sprintf(pcQuery,"SELECT %s FROM %s", pc_field_name, pc_table);
  /* SELECT the data based on one condition */
  else if ( pc_condition != NULL )
    sprintf(pcQuery,"SELECT %s FROM %s WHERE %s", pc_field_name, pc_table, pc_condition);
  /* LOG FILE */
  else {	
    writeLogFile (m_sLogFile,2,"CMysqlDB::FetchTable==>Wrong conditions both are NULL");
    return NULL;
  }
	/* Send Query */
	if(mysql_query(&m_pMysql,pcQuery)) {
		/* LOG FILE */
		sprintf(cAuxLog,"CMysqlDB::FetchTable==>Failed to fetch all the table %s",pc_table);
		writeLogFile (m_sLogFile,2,cAuxLog);
		return NULL;
	} else {
		/* QUERY RESULT */
		pcMySQLResult = mysql_store_result(&m_pMysql);  
		if (!pcMySQLResult)   {
			sprintf(cAuxLog,"CMysqlDB::FetchTable==>There is no data inside the table %s",pc_table);
			writeLogFile (m_sLogFile,2,cAuxLog);
			return NULL;
		}
		return pcMySQLResult;
	}
	return NULL;
};
