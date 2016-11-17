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
/* LIBRARY APPLIANCES							                              */
/* It contains common data types and structures				          */
/****************************************************************/
#ifndef CAPPLIANCE_H_
#define CAPPLIANCE_H_

class CAppliance;

/****************************************************************/
/* MACROS */
#define FRIDGE          0
#define DISHWASHER      1
#define WASHING_MACHINE 2
#define DRYER           3
#define OVEN            4
#define HOOD            5
/****************************************************************/
/* LIBRARIES */
#include "common.h"
#include "soapSAHBindingProxy.h"

/****************************************************************/
/*STRUCTURE*/
struct sApp {	
  int nID;
  string sSoapID;
  TSV vsVariables;
  TSV vsDBstatus;
  TSV vsActions;
};

typedef vector<CAppliance*>            TAppV;
typedef vector<CAppliance*>::iterator  TAppVIterator;


/****************************************************************/
/* CLASS DECLARATION */
class CAppliance {

  public:
    CAppliance (SAHBindingProxy* pc_service_gsoap, sApp s_app_params);
    ~CAppliance ();
    TSV Update( void );    
    int Action( string s_action );
    int Action( string s_action, int n_input );
    int Action( string s_action, string s_input );
    int Action( string s_action, TSV vs_input );
    int UserAction( string s_action );
    int DBProgram( int n_app, TSV vs_input );
    /*GETTERS*/
    string getSoapID( void ) { return m_sAppParams.sSoapID; };
    TSV getMysqlStatus( void ) { return m_sAppParams.vsDBstatus; };
	protected:
		/*VARIABLES*/

		/*FUNCTIONS*/

	private:
		/* VARIABLES */
    SAHBindingProxy* m_pcServiceGSoap;
    sApp             m_sAppParams;
		/* FUNCTIONS */
};
#endif
