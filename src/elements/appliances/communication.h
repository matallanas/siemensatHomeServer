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
/* LIBRARY COMMUNICATION 							                          */
/* It contains common data types and structures				          */
/****************************************************************/
#ifndef CCOMMUNICATION_H_
#define CCOMMUNICATION_H_

/****************************************************************/
/* MACROS */
/****************************************************************/
/* LIBRARIES */
#include "common.h"
#include "appliance.h"

/****************************************************************/
/*STRUCTURE*/

/****************************************************************/
/* CLASS DECLARATION */
class CCommunication {

  public:
    CCommunication ( TAppV v_app );
    ~CCommunication ();
    void FridgeMenu ( void );
    void WMMenu ( void );
    void DWMenu ( void );
    void DryerMenu ( void );
    void OvenMenu ( void );
    void HoodMenu ( void );

	protected:
		/*VARIABLES*/

		/*FUNCTIONS*/

	private:
		/* VARIABLES */
    TAppV m_vApp;
		/* FUNCTIONS */
    void FridgeStatus ( TSV v_status );
    void WMStatus ( TSV v_status );
    void DWStatus ( TSV v_status );
    void DryerStatus ( TSV v_status );
    void OvenStatus ( TSV v_status );
    void HoodStatus ( TSV v_status );
    void RemoteState ( string s_remote_enable, string s_state, string s_connection );
};
#endif
