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
/* COMMUNICATION METHODS				                                */
/****************************************************************/
#include "communication.h"

/****************************************************************/
/* CONSTRUCTOR 							                                    */
/****************************************************************/
CCommunication::CCommunication( TAppV v_app ){
  m_vApp = v_app;
};
/****************************************************************/
/* DESTRUCTOR 							                                    */
/****************************************************************/
CCommunication::~CCommunication(){

};
/****************************************************************/
/* FRIDGE COMM 							                                    */
/****************************************************************/
void CCommunication::FridgeMenu ( void ){
  int nElection, nTemp, nSuper;

  cout<<" Action to set up the fridge/freezer: "<<endl;
  cout << "   1 - Status of the fridge & freezer "<< endl;
  cout << "   2 - Change the temperature of the fridge"<<endl;
  cout << "   3 - Change the temperature of the freezer"<< endl;
  cout << "   4 - Activate/deactivate supercooling"<<endl;
  cout << "   5 - Activate/deactivate superfreezing"<< endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      FridgeStatus(m_vApp[FRIDGE]->Update());
      break;
    case 2:
      cout << " Enter temperature: ";
      cin >> nTemp;
      cout << endl;
      m_vApp[FRIDGE]->Action("setKFTargetTemperature",nTemp);
      break;
    case 3:
      cout << " Enter temperature: ";
      cin >> nTemp;
      cout << endl;
      m_vApp[FRIDGE]->Action("setGFTargetTemperature",nTemp);
      break;
    case 4:
      cout << " Indicate an option: "<<endl;
      cout << "   1 - Activate supercooling"<<endl;
      cout << "   2 - Deactivate supercooling"<<endl;
      cin >> nSuper;
      cout << endl;
      if(nSuper == 1)
        m_vApp[FRIDGE]->Action("setSuperKF","true");
      else if(nSuper == 2)
        m_vApp[FRIDGE]->Action("setSuperKF","false");
      else
        cout<<"CCommunication::FridgeMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
    case 5:
      cout << " Indicate an option: "<<endl;
      cout << "   1 - Activate superfreezing"<<endl;
      cout << "   2 - Deactivate superfreezing"<<endl;
      cin >> nSuper;
      cout << endl;
      if(nSuper == 1)
        m_vApp[FRIDGE]->Action("setSuperGF","true");
      else if(nSuper == 2)
        m_vApp[FRIDGE]->Action("setSuperGF","false");
      else
        cout<<"CCommunication::FridgeMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
    default:
      cout<<"CCommunication::FridgeMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
  return;
};
/****************************************************************/
/* FRIDGE STATUS						                                    */
/****************************************************************/
void CCommunication::FridgeStatus ( TSV v_status ){
  cout << " Information of the fridge/freezer status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout << "   Fridge temperature: "<< v_status[3] << endl;
  cout << "   Freezer temperature: "<< v_status[4] << endl;
  if (strcmp(v_status[5].c_str(),"true")==0)
    cout << "   Supercooling activated"<< std::endl;
  else
    cout << "   Supercooling deactivated"<< std::endl;
  if (strcmp(v_status[6].c_str(),"true")==0)
    cout << "   Superfreezing activated"<< std::endl;
  else
    cout << "   Superfreezing deactivated"<< std::endl;

  return;   
};
/****************************************************************/
/* WASHING MACHINE COMM			                                    */
/****************************************************************/
void CCommunication::WMMenu ( void ){
  int nElection, nInput, nResult;

  cout<<" Action to set up the washing machine: "<<endl;
  cout << "   1 - Status of the washing machine "<< endl;
  cout << "   2 - Start new program"<<endl;
  cout << "   3 - Pause current program"<< endl;
  cout << "   4 - Resume current program"<<endl;
  cout << "   5 - Stop current program"<<endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      WMStatus(m_vApp[WASHING_MACHINE]->Update());
      break;
    case 2:
       cout << "   Set program: "<<endl;
      cout << "     00 => Cottons / Coloured"<<endl;
      cout << "     01 => Easy-care"<<endl;
      cout << "     02 => Delicates"<<endl;
      cout << "     03 => Wool"<<endl;
      cout << "     04 => Memory1"<<endl;
      cout << "     05 => Memory2"<<endl;
      cout << "     06 => Memory3"<<endl;
      cout << "     07 => Blouse/shirt"<<endl;
      cout << "     08 => Outdoor wear"<<endl;
      cout << "     09 => Silk"<<endl;
      cout << "     10 => Mix"<<endl;
      cout << "     11 => Coloured Eco"<<endl;
      cout << "     12 => Courtains"<<endl;
      cout << "     13 => Rinse"<<endl;
      cout << "     14 => Spin"<<endl;
      cout << "     15 => Drain"<<endl;
      cout << "     16 => Short Demo"<<endl;
      cout << "     17 => Cont Demo"<<endl;
      cin >> nInput;
      nResult = m_vApp[WASHING_MACHINE]->Action("setWashingParameters0",nInput);
      if(nResult!=0){
        cout << "   Set program temperature: "<<endl;
        cin >> nInput;
        nResult = m_vApp[WASHING_MACHINE]->Action("setTargetTemperature0",nInput);
        if(nResult!=0){
          cout << "   Set program spin: "<<endl;
          cin >> nInput;
          nResult = m_vApp[WASHING_MACHINE]->Action("setSpin0",nInput);
          if(nResult!=0){
            cout << "   Starting program"<<endl;
            nResult = m_vApp[WASHING_MACHINE]->Action("start0");
          }
        }
      }
      break;
    case 3:
      m_vApp[WASHING_MACHINE]->Action("pause0");
      break;
    case 4:
      m_vApp[WASHING_MACHINE]->Action("start0");
      break;
    case 5:
      m_vApp[WASHING_MACHINE]->Action("stop0");
      break;
    default:
      cout<<"CCommunication::WMMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
   return;
};
/****************************************************************/
/* WASHING MACHINE STATUS		                                    */
/****************************************************************/
void CCommunication::WMStatus ( TSV v_status ){
  cout << " Information of the washing machine status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout<<"   Washing program: "<<v_status[3]<<endl;
  cout<<"   Current phase:   "<<v_status[7]<<endl;
  cout<<"   Temperature:     "<<v_status[4]<<endl;
  cout<<"   Spin speed:      "<<v_status[5]<<endl;
  cout<<"   Finish Time:     "<<v_status[6]<<endl;
  return;
};
/****************************************************************/
/* DISHWASHER COMM    			                                    */
/****************************************************************/
void CCommunication::DWMenu ( void ){
  int nElection, nInput, nResult;

  cout<<" Action to set up the dishwasher: "<<endl;
  cout << "   1 - Status of the dishwasher"<< endl;
  cout << "   2 - Start washing program"<< endl;
  cout << "   3 - Stop current program"<<endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      DWStatus(m_vApp[DISHWASHER]->Update());
      break;
    case 2:
      cout << "     Choose your program:"<<endl;
      cin >> nInput;
      m_vApp[DISHWASHER]->Action("setWashingParameters0",nInput);
      m_vApp[DISHWASHER]->Action("start0");
      break;
    case 3:
      m_vApp[DISHWASHER]->Action("stop0");
      break;
    default:
      cout<<"CCommunication::DWMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
  return;
};
/****************************************************************/
/* DISHWASHER STATUS		                                        */
/****************************************************************/
void CCommunication::DWStatus ( TSV v_status ){
  cout << " Information of the dishwasher status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout<<"   Washing parameters: "<<v_status[3]<<endl;
  cout<<"   Current phase:      "<<v_status[6]<<endl;
  cout<<"   Remaining Time:     "<<v_status[5]<<endl;
  cout<<"   Start Time:         "<<v_status[4]<<endl;
  return;
};
/****************************************************************/
/* DRYER COMM         			                                    */
/****************************************************************/
void CCommunication::DryerMenu ( void ){
  int nElection, nInput, nResult;

  cout<<" Action to set up the dryer: "<<endl;
  cout << "   1 - Status of the dryer"<< endl;
  cout << "   2 - Start drying program"<< endl;
  cout << "   3 - Pause current program"<<endl;
  cout << "   4 - Resume current program"<<endl;
  cout << "   5 - Stop current program"<<endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      DryerStatus(m_vApp[DRYER]->Update());
      break;
    case 2:
      cout << "     Set program spin:"<<endl;
      cin >> nInput;
      m_vApp[DRYER]->Action("setSpin",nInput);
      m_vApp[DRYER]->Action("start");
      break;
    case 3:
      m_vApp[DRYER]->Action("pause");
      break;
    case 4:
      m_vApp[DRYER]->Action("start");
      break;
    case 5:
      m_vApp[DRYER]->Action("stop");
      break;
    default:
      cout<<"CCommunication::DryerMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
  return;
};
/****************************************************************/
/* DRYER STATUS      		                                        */
/****************************************************************/
void CCommunication::DryerStatus ( TSV v_status ){
  cout << " Information of the dryer status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout<<"   Washing parameters: "<<v_status[3]<<endl;
  cout<<"   Current phase:      "<<v_status[6]<<endl;
  cout<<"   Remaining Time:     "<<v_status[5]<<endl;
  cout<<"   Start Time:         "<<v_status[4]<<endl;
  return;
};
/****************************************************************/
/* OVEN COMM          			                                    */
/****************************************************************/
void CCommunication::OvenMenu ( void ){
  int nElection, nInput;
  string sInput;
  TSV vParameters;
  cout<<" Action to set up the oven: "<<endl;
  cout << "   1 - Status of the oven"<< endl;
  cout << "   2 - Start oven"<< endl;
  cout << "   3 - Start oven programming duration"<<endl;
  cout << "   4 - Stop current program"<<endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      OvenStatus(m_vApp[OVEN]->Update());
      break;
    case 2:
      cout << "     Locking oven controls" << endl;
      if( m_vApp[OVEN]->UserAction("lock")){
        cout << "     Set mode (Normally 3): "<<endl;
        cin >> nInput;
        if(m_vApp[OVEN]->Action("setHeatingMode",nInput)){
          cout << "     Set Temperature (30ºC -- 300ºC): "<<endl;
          cin >> nInput;
          if(m_vApp[OVEN]->Action("setTemperature",nInput)){
            cout<< "     Realising the controls"<<endl;
            m_vApp[OVEN]->Action("flush");
          }
        }
      }
      break;
    case 3:
      cout << "     Set mode: "<<endl;
      cin >> sInput;
      vParameters.push_back(sInput);
      cout << "     Set temperature: "<<endl;
      cin >> sInput;
      vParameters.push_back(sInput);
      cout << "     Set duration: "<<endl;
      cin >> sInput;
      vParameters.push_back(sInput);
      cout << "     Set end time: "<<endl;
      cin >> sInput;
      vParameters.push_back(sInput);
      m_vApp[OVEN]->Action("setHeatingModeComplete0",vParameters);
      break;
    case 4:
      m_vApp[OVEN]->Action("reset0");
      break;
    default:
      cout<<"CCommunication::OvenMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
  return;
};
/****************************************************************/
/* OVEN STATUS      		                                        */
/****************************************************************/
void CCommunication::OvenStatus ( TSV v_status ){
  cout << " Information of the Oven status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout<<"   Heating Mode:      "<<v_status[3]<<endl;
  cout<<"   Temperature:       "<<v_status[4]<<endl;
  cout<<"   Finish time:       "<<v_status[6]<<endl;
  cout<<"   Duration time:     "<<v_status[5]<<endl;
  cout<<"   Lock for children: "<<v_status[7]<<endl;
  return;
};
/****************************************************************/
/* HOOD COMM          			                                    */
/****************************************************************/
void CCommunication::HoodMenu ( void ){
  int nElection, nInput;
  string sInput;
  TSV vParameters;
  cout<<" Action to set up the hood: "<<endl;
  cout << "   1 - Status of the hood"<< endl;
  cout << "   2 - Set the light"<< endl;
  cout << "   3 - Set the fan speed"<<endl;
  cout << "   4 - Stop the hood"<<endl;
  cin >> nElection;

  switch (nElection){
    case 1:
      HoodStatus(m_vApp[HOOD]->Update());
      break;
    case 2:
      cout<<"     Set the intensity of the light:"<<endl;
      cin >> nInput;
      cout << endl;
      m_vApp[HOOD]->Action("setLightOnOffDim",nInput);
      break;
    case 3:
      cout<<"     Set the speed of the fan:"<<endl;
      cin >> sInput;
      cout << endl;
      vParameters.push_back("0");
      vParameters.push_back(sInput);
      m_vApp[HOOD]->Action("programFan",vParameters);
      break;
    case 4:
      m_vApp[HOOD]->Action("stop");
      cout<<"     The hood has been stopped"<<endl;
      break;
    default:
      cout<<"CCommunication::OvenMenu ==> OPTION NOT RECOGNIZED"<<endl;
      break;
  }
  return;
};
/****************************************************************/
/* OVEN STATUS      		                                        */
/****************************************************************/
void CCommunication::HoodStatus ( TSV v_status ){
  cout << " Information of the Oven status:" << endl;
  RemoteState(v_status[0],v_status[1],v_status[2]); 
  cout<<"   Fan speed:       "<<v_status[3]<<endl;
  cout<<"   Light Intensity: "<<v_status[4]<<endl;
  return;
};
/****************************************************************/
/* REMOTE STATUS OF THE APPLIANCE                               */
/****************************************************************/
void CCommunication::RemoteState ( string s_remote_enable, string s_state, string s_connection ){
  
  //REMOTE CONTROL
  int nRemote = atoi(s_remote_enable.c_str()); 
  cout<<"   Remote control ";
  if( nRemote == 0 )
    cout<<"disabled"<<endl;
  else if( nRemote == 1 )
    cout<<"enabled"<<endl;
  
  //State of the connection
  int nState = atoi(s_state.c_str()); 
  cout<<"   Connection mode: ";
  switch (nState){
    case 0:
      cout<<"offline"<<endl;
      break;
    case 1:
      cout<<"initializing"<<endl;
      break;
    case 2:
      cout<<"failure with @ mode activated"<<endl;
      break;
    case 3:
      cout<<"failure"<<endl;
      break;
    case 4:
      cout<<"online with @ mode activated"<<endl;
      break;
    case 5:
      cout<<"online"<<endl;
      break;
    case 6:
      cout<<"standby with @ mode activated"<<endl;
      break;
    case 7:
      cout<<"standby"<<endl;
      break;
    default:
      cout<<"MODE NOT RECOGNISED"<<endl;
      break;
  }

  //Connected to the platform
  if(strcmp(s_connection.c_str(), "online")==0)
    cout<<"   Connected to the platform"<<endl;
  else
    cout<<"   Not connected to the platform"<<endl;

  return;
};
