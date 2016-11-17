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
/* APPLIANCE METHODS						                                */
/****************************************************************/
#include "appliance.h"

/****************************************************************/
/* CONSTRUCTOR 							                                    */
/****************************************************************/
CAppliance::CAppliance( SAHBindingProxy* pc_service_gsoap, sApp s_app_params ){

  m_pcServiceGSoap = pc_service_gsoap;
  m_sAppParams = s_app_params;

};
/****************************************************************/
/* DESTRUCTOR 							                                    */
/****************************************************************/
CAppliance::~CAppliance(){
};
/****************************************************************/
/* UPDATE FUNCTION                                              */
/* We ask to the server for new datas                           */
/****************************************************************/
TSV CAppliance::Update( void ){

  ns1__getDeviceStateVariablesResponse resp;
  ArrayOfString parameters;    
  string sAux[m_sAppParams.vsVariables.size()];
  TSV vStatus; 

  for(int s=0; s<m_sAppParams.vsVariables.size(); s++)
    sAux[s]=m_sAppParams.vsVariables[s];

  parameters.__size = m_sAppParams.vsVariables.size(); 
  parameters.__ptr  = sAux;
  
  if (m_pcServiceGSoap->getDeviceStateVariables( m_sAppParams.sSoapID, &parameters, resp)== SOAP_OK ){
    for(int i=0; i<resp.return_->__size; i++){
      vStatus.push_back((*(resp.return_->__ptr+i))->value);
      /* DEBUG */
      //cout<<m_sAppParams.sSoapID<<"\t ==> \t"<<m_sAppParams.vsVariables[i]<<"\t ==> \t"<<(*(resp.return_->__ptr+i))->value<<endl;
      /* DEBUG */
    }
  }else
    m_pcServiceGSoap->soap_stream_fault(cerr);
  
  return vStatus;
  
};
/****************************************************************/
/* INVOKE ACTION FUNCTION                                       */
/* We ask to the server for new datas                           */
/****************************************************************/
int CAppliance::Action( string s_action ){

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  string sAux[1];
  int nResult = 0;
  
  sAux[0] = "Structure (defaultTokenUniqueID, 10)";

  parameters.__size = 1;
  parameters.__ptr = sAux;

  if (m_pcServiceGSoap->invokeAction( m_sAppParams.sSoapID, s_action, &parameters, resp)== SOAP_OK) 
    nResult = 1;
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return nResult;
};
/****************************************************************/
/* INVOKE ACTION FUNCTION                                       */
/* We ask to the server for new datas                           */
/****************************************************************/
int CAppliance::Action( string s_action, int n_input ){

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  char cAux[32];
  string sAux[2];
  int nResult = 0;

  sprintf(cAux,"%d",n_input);
  
  sAux[0] = &cAux[0];
  sAux[1] = "Structure (defaultTokenUniqueID, 10)";

  parameters.__size = 2;
  parameters.__ptr = sAux;

  if (m_pcServiceGSoap->invokeAction( m_sAppParams.sSoapID, s_action, &parameters, resp)== SOAP_OK) 
    nResult = 1;
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return nResult;
};
/****************************************************************/
/* INVOKE ACTION FUNCTION                                       */
/* We ask to the server for new datas                           */
/****************************************************************/
int CAppliance::Action( string s_action, string s_input ){

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  string sAux[2];
  int nResult = 0;
  
  sAux[0] = s_input.c_str();
  sAux[1] = "Structure (defaultTokenUniqueID, 10)";

  parameters.__size = 2;
  parameters.__ptr = sAux;

  if (m_pcServiceGSoap->invokeAction( m_sAppParams.sSoapID, s_action, &parameters, resp)== SOAP_OK) 
    nResult = 1;
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return nResult;
};
/****************************************************************/
/* INVOKE ACTION FUNCTION                                       */
/* We ask to the server for new datas                           */
/****************************************************************/
int CAppliance::Action( string s_action, TSV vs_input ){

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  string sAux[vs_input.size()+1];
  int nResult = 0;
  
  for(int s=0; s<vs_input.size(); s++)
    sAux[s] = vs_input[s].c_str();

  sAux[vs_input.size()] = "Structure (defaultTokenUniqueID, 10)";

  parameters.__size = vs_input.size()+1;
  parameters.__ptr = sAux;

  if (m_pcServiceGSoap->invokeAction( m_sAppParams.sSoapID, s_action, &parameters, resp)== SOAP_OK) 
    nResult = 1;
  else
    m_pcServiceGSoap->soap_stream_fault(cerr);

  return nResult;
};
/****************************************************************/
/* INVOKE ACTION OF THE USER FUNCTION                           */
/* We ask to the server for new datas                           */
/****************************************************************/
int CAppliance::UserAction( string s_action ){

  ns1__invokeActionResponse resp;
  ArrayOfString parameters;
  string sAux[1];
  int nResult = 0;
  
  sAux[0] = "(user, 10)";

  parameters.__size = 1;
  parameters.__ptr = sAux;

  if (m_pcServiceGSoap->invokeAction( m_sAppParams.sSoapID, s_action, &parameters, resp)== SOAP_OK) 
    nResult = 1;
  else
    m_pcServiceGSoap->soap_stream_fault(std::cerr);

  return nResult;
};
/****************************************************************/
/* PROGRAM APPLIANCES FROM DB FUNCTION                          */
/* We program the appliances with data from the db              */
/****************************************************************/
int CAppliance::DBProgram( int n_app, TSV vs_input ){

  int nResult;
  /* Send the appliances the program */
  if ( n_app != OVEN && n_app != HOOD ){
    for(int action = 0; action < vs_input.size(); action++)
      nResult = Action(m_sAppParams.vsActions[action],vs_input[action]);
    if ( n_app != FRIDGE ) 
      nResult = UserAction(m_sAppParams.vsActions[m_sAppParams.vsActions.size()-1]);
  /* Send the program to the oven */
  }else if( n_app == OVEN ){
    nResult = UserAction(m_sAppParams.vsActions[0]);
    for(int action = 0; action < vs_input.size(); action++)
      nResult = Action(m_sAppParams.vsActions[action],vs_input[action]);
    nResult = UserAction(m_sAppParams.vsActions[m_sAppParams.vsActions.size()-1]);
  /* Send the program to the hood */
  }else if( n_app == HOOD ){
    TSV vParameters;
    vParameters.push_back("0");
    vParameters.push_back(vs_input[0]);
    nResult = Action(m_sAppParams.vsActions[0],vParameters);
    nResult = Action(m_sAppParams.vsActions[1],vs_input[1]);
  }

  return nResult;
};
