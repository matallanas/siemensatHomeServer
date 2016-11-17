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
/* LIBRARY TESTGSOAP 							                              */
/* It contains common data types and structures				          */
/****************************************************************/
#ifndef CTESTGSOAP_H_
#define CTESTGSOAP_H_


/****************************************************************/
/* MACROS */
#define ACTION          1
#define ID_APP          2
#define ACTION_APP      3
#define STATUS          4
#define STATUS_APP      5
#define STATUS_APP_EXT  6
#define EVENTS          7
#define DATE_SERV       8
#define INFO_ALL        9
#define INFO_ALL_EXT   10
#define COM_LOADS      11

/****************************************************************/
/* LIBRARIES */
#include "common.h"
#include "soapSAHBindingProxy.h"
#include "appliances/appliance.h"
#include "appliances/communication.h"

/******************************************************************************/
/* CLASS DECLARATION */
class CtestgSoap {
  public:
    CtestgSoap (SAHBindingProxy* pc_service_gsoap, TAppV v_app);
    ~CtestgSoap ();
    
    void TestMain(int n_test_number);

	protected:
		/*VARIABLES*/

		/*FUNCTIONS*/

	private:
		/* VARIABLES */
    SAHBindingProxy* m_pcServiceGSoap;
    string m_sAuxVars[12];
    CCommunication* m_pcComm;
    /*TAppV m_vApp;*/
		/* FUNCTIONS */
    int array(ArrayOfString& variables);
    void ExecuteAction( void );
    void IDdisp( void );
    void AppAvailableActions ( void );
    void Status ( void );
    void StatusAppliance ( void );
    void StatusApplianceExtended ( void );
    void Events ( void );
    void ServerDate ( void );
    void ApplianceInfo ( void );
    void ExtendedApplianceInfo ( void );
    /* Communication with the loads */
    bool LoadComm ( void );
};
#endif
