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
/* MySQL DB API FUNCTION CLASS	       																				 */
/*																																						 */
/* Tasks:                                                                      */
/* - Connect/Disconnect																												 */
/* - Create/Drop Database																											 */
/* - Create/Drop Tables																												 */
/* - Delete values of the tables.																							 */
/* - Update values of them.																										 */
/* - Insert data in the DB.																										 */
/* - Fetch Data																																 */
/*																																						 */
/*******************************************************************************/
#ifndef MYSQLDB_H_
#define MYSQLDB_H_

/*******************************************************************************/
/* LIBRARIES*/
#include "common.h"

#include <my_global.h>
#include <mysql.h>
#include <string.h>
/*******************************************************************************/

/* MACROS */
#define STRING_SIZE 50
#define VOID_CHAR   ""

typedef struct{
  string sHost;
  string sUser;
  string sPass;
  string sDb;
} MySQL_Param;

/******************************************************************************/
/* CLASS DECLARATION */
class CMysqlDB {

	public:
		/*FUNCTIONS */
    CMysqlDB ( MySQL_Param sm_mysql_param, string s_log_file);
		~CMysqlDB ( void );
		/* CONNECT/DISCONNECT */
		void Connect ( void );
		void Connect ( MySQL_Param sc_mysql_params );
		void Disconnect ( void ); 
		/* INSERT */
		void Insert (const char* pc_table, const char* pc_field, const char* pc_value);
		/* CREATE */
		/* DB */
		void CreateDataBase (const char* pc_db);
		/* Table */
		void CreateTable (const char* pc_table, const char* pc_field); 
		/* DROP */
		/* DB */
		void DropTable (const char* pc_table);
		/* Table */
		void DropDataBase (const char* pc_db);
		/* ROW COUNTER */
		int RowCounter (const char* pc_table, const char* pc_field, const char* pc_condition);
		/* UPDATE */
		void UpdateValue (const char* pc_table, const char* pc_value, const char* pc_condition);
		/* DELETE*/
		/* A value */
		void DeleteValueTable ( const char* pc_table, const char* pc_condition ); 
		/* Fetch Data*/
		/* STRINGS */
		string FetchDataString ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows ); 
		/* DOUBLES */
		double FetchDataDouble ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows ); 
		/* INTEGERS */
		int FetchDataInt ( const char *pc_table, const char* pc_field_name, const char* pc_condition, int n_rows ); 
		/* TABLE */
		MYSQL_RES* FetchTable ( const char *pc_table, const char* pc_field_name, const char* pc_condition); 
		
		/*GETTERS*/
		MYSQL getDB ( void ) { return m_pMysql; };
		MySQL_Param getMysqlParams ( void ) { return m_sMysqlParams; }; 
		string getLogFile ( void ) {return m_sLogFile;};
		/*SETTERS*/
		void setDB ( MYSQL p_mysql ) { m_pMysql = p_mysql; };
		void setMysqlParams ( MySQL_Param s_mysql_params ) { m_sMysqlParams = s_mysql_params; };

		void SelectTable (const char* pc_table);
	protected:
		/*VARIABLES*/

		/*FUNCTIONS*/

	private:
		/*VARIABLES */
		MYSQL 				m_pMysql;
		string				m_sLogFile;
		MySQL_Param		m_sMysqlParams;
};

#endif
