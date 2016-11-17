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
/* TEST GSOAP METHODS						                                */
/****************************************************************/
#include "testgSoap.h"

/****************************************************************/
/* CONSTRUCTOR 							                                    */
/****************************************************************/
CtestgSoap::CtestgSoap(SAHBindingProxy* pc_service_gsoap, TAppV v_app){

  m_pcServiceGSoap = pc_service_gsoap;
  m_pcComm = new CCommunication(v_app); 
};

/****************************************************************/
/* DESTRUCTOR 							                                    */
/****************************************************************/
CtestgSoap::~CtestgSoap(){
  delete m_pcComm;
};
/****************************************************************/
/* EXECUTION THE CORRESPONDING TEST                             */
/****************************************************************/
void CtestgSoap::TestMain(int n_test_number) {

	switch (n_test_number){
    case ACTION:{
      ExecuteAction();
      break;
    }case ID_APP:{
      IDdisp();
      break; 
    }case ACTION_APP:{
      AppAvailableActions();
      break;
    }case STATUS:{
      Status();
      break;
    }case STATUS_APP:{
      StatusAppliance();
      break;
    }case STATUS_APP_EXT:{
      StatusApplianceExtended();
      break;
    }case EVENTS:{
      Events();
      break;
    }case DATE_SERV:{
      ServerDate();
      break;
    }case INFO_ALL:{
      ApplianceInfo();
      break;
    }case INFO_ALL_EXT:{
      ExtendedApplianceInfo();
      break;
    }case COM_LOADS:{
      while(!LoadComm());
      break;
    }default:
			cout << "CtestgSoap::TestMain==>TEST NUMBER NOT RECOGNIZED" << endl;
			exit(-1);
			break;
	}
}
/****************************************************************/
/* ARRAY of parameters			                                    */
/****************************************************************/
int CtestgSoap::array(ArrayOfString& variables){

  variables.__ptr = m_sAuxVars; //Pointer to the start of the pointer.
  variables.__size=0;           //Size of the array.
  char *paux;                   //Auxiliar pointer to add data.
  bool ready = false;           //condition to exit the loop

  while (ready != true){
    paux = new char[50];                     
    cin.getline (paux,50);              
    if (strlen(paux)!= 0){                   
      m_sAuxVars[variables.__size] = paux;        
      variables.__size++;
      cout <<"Number of variables inserted : "<<variables.__size <<endl;
    }
    else
      ready=true;
    delete paux;
  }

  for (int i = 0; i < variables.__size; i++){
    cout << "pointers :  "<< &variables.__ptr <<"   "<< (variables.__ptr + i) <<"    "<<*(variables.__ptr + i) <<endl;        
  }
  return 0;
};
/****************************************************************/
/* FUNCTION ExecuteAction( void )                               */
/* Carry out an action of the selected appliance                */
/****************************************************************/
void CtestgSoap::ExecuteAction( void ) {

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  int numdisp;
  char devID[50];
  char action[50];
    
  //ID of the appliance
  cout << "ID of the appliance:"<<endl;       
  cin.getline(devID, 50);
    
  //Action to execute
  cout << "Insert action:"<<endl;       
  cin.getline(action, 50);
    
  //Parameters of the action
  cout << "Insert parameters of the action:"<<endl;
  array(parameters);
    
  for (int j = 0; j < parameters.__size; j++)
    cout << "pointers :  "<< &parameters.__ptr <<"   "<< (parameters.__ptr + j) <<"    "<<*(parameters.__ptr + j) <<endl;
    
  if (m_pcServiceGSoap->invokeAction( devID, action, &parameters, resp)== SOAP_OK){ 
    numdisp = resp.return_->__size;
    cout<<"Action done succesfully"<<endl;
    for (int i = 0; i < numdisp; i++)             
      cout << *((*(resp.return_->__ptr + i))->__item) << endl;
  }else
    m_pcServiceGSoap->soap_stream_fault(cerr);
  
  return;     
};
/****************************************************************/
/* FUNCTION IDdisp( void )                                      */
/* Shows the different elements of the system                   */
/****************************************************************/
void CtestgSoap::IDdisp( void ) {
   
  ns1__getAvailableDevicesIDsResponse resp;  //Structure to receive the data of the function getAvailableDevicesIDs. 
  int numdisp;
   
  if (m_pcServiceGSoap->getAvailableDevicesIDs(resp)== SOAP_OK){
    numdisp = resp.return_->__size;
    cout << "We have "<< numdisp << " elements." << endl; //It shows the number of available appliances.
    for (int i = 0; i < numdisp; i++)       
      cout << *(resp.return_->__ptr+i) << endl; //List of appliances.     
  }else
    m_pcServiceGSoap->soap_stream_fault(std::cerr); //Error in the connection.   
  
  return;
}; 
/****************************************************************/
/* FUNCTION AppAvailableAction( void )                          */
/* Shows the available actions of the selected appliance        */
/****************************************************************/
void CtestgSoap::AppAvailableActions ( void ) {

  ns1__getDeviceAvailableActionsResponse resp; //Structure to receive the data of the function getDeviceAvailableActions. 
  int numacciones;   
  char devID[60];                              //ID of the appliance
    
  cout << "Insert the ID of the appliance to check its actions:"<<endl; 
  cin.getline(devID, 60);
   
  if (m_pcServiceGSoap->getDeviceAvailableActions(devID, resp)== SOAP_OK){      
    numacciones = resp.return_->__size;
    cout << "There are "<< numacciones << " actions:" << endl;    //Show the number of actions
    for (int i = 0; i < numacciones; i++)       
      cout << *(resp.return_->__ptr+i) << endl;                 //Each action in the screen.     
  }else
    m_pcServiceGSoap->soap_stream_fault(cerr);  //Connection error.   
  
  return;
};
/****************************************************************/
/* FUNCTION STATUS ( void )                                     */
/* Shows the value of the variables of an appliance the it is   */
/* requested                                                    */
/****************************************************************/
void CtestgSoap::Status ( void ) {

  ns1__getDeviceStateVariablesResponse resp; //Data for the server
  ArrayOfString varent;                      //Variables to show
  int numdisp;       
  char devID[50];    

  //ID of the appliance;
  std::cout << "ID of the appliance to show:"<<std::endl;       
  cin.getline(devID, 50);    
  cout << devID <<endl;


  //Variables to check.
  cout << "Variables to check:"<<endl;
  array(varent);

  for (int j = 0; j < varent.__size; j++)
    cout << "pointers:  "<< &varent.__ptr <<"   "<< (varent.__ptr + j) <<"    "<<*(varent.__ptr + j) <<endl;

  //Send the request to the server.
  if (m_pcServiceGSoap->getDeviceStateVariables( devID, &varent, resp)== SOAP_OK){ 
    numdisp = resp.return_->__size;
    cout << numdisp <<endl;
    for (int i = 0; i < numdisp; i++){             
      cout << (*(resp.return_->__ptr + i))->variablename << endl;                  
      cout << (*(resp.return_->__ptr + i))->value        << endl;
    }
  }
  else
    m_pcServiceGSoap->soap_stream_fault(std::cerr);
  
  return; 
};
/****************************************************************/
/* FUNCTION STATUS APPLIANCE ( void )                           */
/* Shows the status of the indicated appliance                  */
/* Available status of the appliances:                          */
/* 0 -> offline                                                 */
/* 1 -> initializing                                            */
/* 2 -> failure with @ mode activated                           */
/* 3 -> failure                                                 */
/* 4 -> online with @ mode activated                            */
/* 5 -> online                                                  */
/* 6 -> standby with @ mode activated                           */
/* 7 -> standby                                                 */
/****************************************************************/
void CtestgSoap::StatusAppliance ( void ) {

  ns1__getDeviceOverviewDataResponse resp;  //Structure to receive the data of the function getDeviceOverviewData.
  char devID[60];                           //ID of the appliance

  cout << "ID of the appliance to check:"<<endl; 
  cin.getline(devID, 60);

  if (m_pcServiceGSoap->getDeviceOverviewData( devID, "en", resp)== SOAP_OK){  
    cout << resp.return_->id       << endl; //Appliance ID
    cout << resp.return_->name     << endl; //Appliance Type
    cout << resp.return_->username << endl; //
    cout << resp.return_->status   << endl; //Actual status of the appliance
    cout << resp.return_->text     << endl; //Additional text
    cout << resp.return_->state    << endl; //Numeric value of the appliance status
  } else
    m_pcServiceGSoap->soap_stream_fault(cerr); 
  
  return;    
};
/****************************************************************/
/* FUNCTION STATUS APPLIANCE EXTENDED ( void )                  */
/* Shows the status of the selected appliance together with its */
/* actions[]                                                    */
/* Available status of the appliances:                          */
/* 0 -> offline                                                 */
/* 1 -> initializing                                            */
/* 2 -> failure with @ mode activated                           */
/* 3 -> failure                                                 */
/* 4 -> online with @ mode activated                            */
/* 5 -> online                                                  */
/* 6 -> standby with @ mode activated                           */
/* 7 -> standby                                                 */
/****************************************************************/
void CtestgSoap::StatusApplianceExtended ( void ) {

  ns1__getDeviceOverviewExtendedDataResponse resp;  //Structure to receive the data of the function getDeviceOverviewExtendedData.
  char devID[60];                                   //ID of the appliance
  int numacciones;

  cout << "ID of the appliance to check:"<<endl; 
  cin.getline(devID, 60);

  if (m_pcServiceGSoap->getDeviceOverviewExtendedData( devID, "en", resp)== SOAP_OK){  
    cout << resp.return_->id       << endl; //Appliance ID
    cout << resp.return_->name     << endl; //Appliance Type
    cout << resp.return_->username << endl; //
    cout << resp.return_->status   << endl; //Actual status of the appliance
    cout << resp.return_->text     << endl; //Additional text
    cout << resp.return_->state    << endl; //Numeric value of the appliance status
    numacciones = resp.return_->actions->__size;
    cout << "There are "<< numacciones << " actions:" << endl; //Show the available actions for the appliance
    for (int i = 0; i < numacciones; i++)       
      cout << *(resp.return_->actions->__ptr+i) << endl;
  } 
  else
    m_pcServiceGSoap->soap_stream_fault(cerr); 
  return;    
};
/****************************************************************/
/* FUNCTION EVENTS ( void )                                     */
/* Shows the events of the system                               */
/****************************************************************/
void CtestgSoap::Events ( void ) {
  
  ns1__getLastDevicesEventsResponse resp; //Structure to receive the data of the function getLastDevicesEvents. 
  int numdisp;
  tm date;
  time_t from;

  // Date of the initial event
  date.tm_year  = 105; //Becareful with the server date
  date.tm_mon   = 0;
  date.tm_mday  = 1;
  date.tm_hour  = 0;
  date.tm_min   = 0;
  date.tm_sec   = 0;
  date.tm_isdst = 0;
  from = mktime(&date);
  cout << from << endl;

  if (m_pcServiceGSoap->getLastDevicesEvents( from, "en", resp)== SOAP_OK){ 
    numdisp = resp.return_->__size;
    cout << "There are "<< numdisp << " messages." << endl;  //Shows the number of events.
    for (int i = 0; i < numdisp; i++){             
      cout << (*(resp.return_->__ptr + i))->id        << endl; //Event ID
      cout << (*(resp.return_->__ptr + i))->sender    << endl; //Appliance of the evento
      cout << (*(resp.return_->__ptr + i))->text      << endl; //Message of the event
      cout << (*(resp.return_->__ptr + i))->timestamp << endl; //Moment at which the event happened
      cout << (*(resp.return_->__ptr + i))->type      << endl; //Event type: 1-INFO 2-WARNING
    }        
  }    
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return;    
};
/****************************************************************/
/* FUNCTION SERVER DATE ( void )                                */
/* Shows the date of the server                                 */
/****************************************************************/
void CtestgSoap::ServerDate ( void ) {

  time_t resp;

  if (m_pcServiceGSoap->getServerTimestamp(resp)== SOAP_OK){ 
    cout << "Current server date:" << endl;
    cout << resp << endl;    
  } else
    m_pcServiceGSoap->soap_stream_fault(cerr); 
  
  return;
};
/****************************************************************/
/* FUNCTION APPLIANCE INFORMATION ( void )                      */
/* Information of all the appliances connected to the server    */
/****************************************************************/
void CtestgSoap::ApplianceInfo ( void ) {
  ns1__getAllDevicesOverviewDataResponse resp;   //Structure to receive the data of the function  getAllDevicesOverviewData.
  int numdisp;

  if (m_pcServiceGSoap->getAllDevicesOverviewData("en", resp)== SOAP_OK){       
    numdisp = resp.return_->__size;
    cout << "There are "<< numdisp << " elements." << endl;   //Shows the number of available appliances
    for (int i = 0; i < numdisp; i++){             
      cout << (*(resp.return_->__ptr + i))->id       << endl;   //Appliance ID
      cout << (*(resp.return_->__ptr + i))->name     << endl;   //Appliance Type
      cout << (*(resp.return_->__ptr + i))->username << endl;   //
      cout << (*(resp.return_->__ptr + i))->status   << endl;   //Current status of the appliance
      cout << (*(resp.return_->__ptr + i))->text     << endl;   //Aditional text
      cout << (*(resp.return_->__ptr + i))->state    << endl;   //Numeric value of the appliance status
    }    
  }                   
  else
    m_pcServiceGSoap->soap_stream_fault(std::cerr);

  return;
};
/****************************************************************/
/* FUNCTION EXTENDED APPLIANCE INFORMATION ( void )             */
/* Information of all the appliances connected to the server    */
/* plus the available actions                                   */
/****************************************************************/
void CtestgSoap::ExtendedApplianceInfo ( void ) {

  ns1__getAllDevicesOverviewExtendedDataResponse resp; //Structure to receive the data of the function getAllDevicesOverviewExtendedData.
  int numdisp;
  int numacciones;

  if (m_pcServiceGSoap->getAllDevicesOverviewExtendedData("en", resp)== SOAP_OK){     //En caso de ningún problema en la comunicación.
    numdisp = resp.return_->__size;
    cout << "There are "<< numdisp << " elements." << endl;   //Shows the number of available appliances
    for (int i = 0; i < numdisp; i++){             
      cout << (*(resp.return_->__ptr + i))->id       << endl;   //Appliance ID
      cout << (*(resp.return_->__ptr + i))->name     << endl;   //Appliance Type
      cout << (*(resp.return_->__ptr + i))->username << endl;   //
      cout << (*(resp.return_->__ptr + i))->status   << endl;   //Current status of the appliance
      cout << (*(resp.return_->__ptr + i))->text     << endl;   //Aditional text
      cout << (*(resp.return_->__ptr + i))->state    << endl;   //Numeric value of the appliance status
      numacciones = (*(resp.return_->__ptr + i))->actions->__size;
      cout << "There are "<< numacciones << " actions:" << endl; //Show the available actions for the appliance
      for (int j = 0; j < numacciones; j++)       
        cout << *((*(resp.return_->__ptr + i))->actions->__ptr+j) << endl; 
    }    
  }                   
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return;
};
/****************************************************************/
/* FUNCTION LOAD COMMUNICATION ( void )                         */
/* Sends commands to the loads to change their status           */
/****************************************************************/
bool CtestgSoap::LoadComm ( void ) {

  int nSelect;
  bool bEnd = false;
  cout << " Insert the appliance to actuate : "<< endl;
  cout << "   1 - Fridge/freezer"  << endl;
  cout << "   2 - Washing machine" << endl;
  cout << "   3 - Dishwasher"      << endl;
  cout << "   4 - Dryer"           << endl;
  cout << "   5 - Oven"            << endl;
  cout << "   6 - Hood"            << endl;
  cout << "   7 - Exit"            << endl;
  cin  >> nSelect;
  switch (nSelect){
    case 1:
      m_pcComm->FridgeMenu();
      break;
    case 2:
      m_pcComm->WMMenu();
      break;
    case 3:
      m_pcComm->DWMenu();
      break;
    case 4:
      m_pcComm->DryerMenu();
      break;
    case 5:
      m_pcComm->OvenMenu();
      break;
    case 6:
      m_pcComm->HoodMenu();
      break;
    case 7:
      bEnd = true;
      break;
    default:
      bEnd = true;
      break;
  }   
  return bEnd;    
};
