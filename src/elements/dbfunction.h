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
/* LIBRARY DB FUNCTIONS						                              */
/* It contains common data types and structures				          */
/****************************************************************/
#ifndef CDBFUNCTION_H_
#define CDBFUNCTION_H_
/****************************************************************/
/* MACROS */
# define CREATE_TABLE  0
# define DROP_TABLE    1
# define DELETE_TABLE  2
# define UPDATE_STATUS 3
# define ACTUATION     4

# define APP_STATUS 0

# define START_TIME 0
# define EXEC_TIME  6
# define PROGRAM    9

/****************************************************************/
/* LIBRARIES */
#include "common.h"
#include "mysqldb.h"
#include "appliances/appliance.h"

/****************************************************************/
/*STRUCTURE*/
struct sMysqlTable {	
  string sName;
  TSV vColName;
  TSV vColType;
};
/*Table vector*/
typedef vector<sMysqlTable> TMysqlTV;
typedef vector<sMysqlTable>::iterator TMysqlTVite;
/******************************************************************************/
/* CLASS DECLARATION */
class CDBFunction {
  public:
    CDBFunction (CMysqlDB* pm_magicbox_db, TAppV v_app, string s_mysql_conf);
    ~CDBFunction ();
    void dbOperation ( int n_db_operation, char* pc_table );

	protected:
		/*VARIABLES*/
 
		/*FUNCTIONS*/

	private:
		/* VARIABLES */
    CMysqlDB* m_pcMysql;
    TAppV m_vApp;
    TMysqlTV m_vMysqlTables;
    string m_sLogFile;
		/* FUNCTIONS */
    void CreateTable( char* pc_table );
    void DropTable( char* pc_table );
    void DeleteTable( char* pc_table );
    void UpdateStatus( char* pc_appliance );
    void UpdateStatusAppliance ( int n_rows, int n_app );
    void Actuation( void );
    time_t getTime ( void );
};

#endif
