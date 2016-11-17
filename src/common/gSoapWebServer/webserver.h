/* webserver.h
   Generated by wsdl2h 1.2.12 from http://192.168.1.210:8080/sah-ws and typemap.dat
   2009-01-20 19:00:39 GMT
   Copyright (C) 2001-2008 Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/* NOTE:

 - Compile this file with soapcpp2 to complete the code generation process.
 - Use soapcpp2 option -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
 - Use wsdl2h options -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) to browse this file.
 - Use wsdl2h option -l to view the software license terms.

   DO NOT include this file directly into your project.
   Include only the soapcpp2-generated headers and source code files.
*/

//gsoapopt w

/******************************************************************************\
 *                                                                            *
 * urn:sah                                                                    *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


// STL vector containers (use option -s to disable)
#import "stlvector.h"

/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

ns1 = "urn:sah"

*/

//gsoap ns1   schema namespace:	urn:sah
//gsoap ns1   schema form:	unqualified

/******************************************************************************\
 *                                                                            *
 * Schema Types                                                               *
 *                                                                            *
\******************************************************************************/

class xsd__anyType { _XML __item; struct soap *soap; };

/// Class wrapper for built-in type "xs:dateTime" derived from xsd__anyType
class xsd__dateTime : public xsd__anyType
{ public:
    time_t                               __item;                       
};

/// Class wrapper for built-in type "xs:int" derived from xsd__anyType
class xsd__int : public xsd__anyType
{ public:
    int                                  __item;                       
};

/// Class wrapper for built-in type "xs:long" derived from xsd__anyType
class xsd__long : public xsd__anyType
{ public:
    LONG64                               __item;                       
};

/// Class wrapper for built-in type "xs:string" derived from xsd__anyType
class xsd__string : public xsd__anyType
{ public:
    std::string                          __item;                       
};


//  Forward declaration of class ns1__DeviceState.
class ns1__DeviceState;

//  Forward declaration of class ns1__MessageEvent.
class ns1__MessageEvent;

//  Forward declaration of class ns1__DeviceStateVariable.
class ns1__DeviceStateVariable;

//  Forward declaration of class ArrayOfDeviceStates.
class ArrayOfDeviceStates;

//  Forward declaration of class ArrayOfMessageEvent.
class ArrayOfMessageEvent;

//  Forward declaration of class ArrayOfDeviceStateVariable.
class ArrayOfDeviceStateVariable;

//  Forward declaration of class ArrayOfString.
class ArrayOfString;

//  Forward declaration of class ArrayOfAnyType.
class ArrayOfAnyType;

//  Forward declaration of class ns1__DeviceStateEx.
class ns1__DeviceStateEx;

//  Forward declaration of class ArrayOfDeviceStatesEx.
class ArrayOfDeviceStatesEx;

/// "urn:sah":DeviceState is a complexType.
class ns1__DeviceState : public xsd__anyType
{ public:
/// Element id of type xs:string.
    std::string                          id                             1;	///< Required element.
/// Element name of type xs:string.
    std::string                          name                           1;	///< Required element.
/// Element username of type xs:string.
    std::string                          username                       1;	///< Required element.
/// Element status of type xs:string.
    std::string                          status                         1;	///< Required element.
/// Element text of type xs:string.
    std::string                          text                           1;	///< Required element.
/// Element state of type xs:int.
    int                                  state                          1;	///< Required element.
};

/// "urn:sah":MessageEvent is a complexType.
class ns1__MessageEvent : public xsd__anyType
{ public:
/// Element id of type xs:long.
    LONG64                               id                             1;	///< Required element.
/// Element sender of type xs:string.
    std::string                          sender                         1;	///< Required element.
/// Element text of type xs:string.
    std::string                          text                           1;	///< Required element.
/// Element timestamp of type xs:dateTime.
    time_t                               timestamp                      1;	///< Required element.
/// Element type of type xs:int.
    int                                  type                           1;	///< Required element.
};

/// "urn:sah":DeviceStateVariable is a complexType.
class ns1__DeviceStateVariable : public xsd__anyType
{ public:
/// Element variablename of type xs:string.
    std::string                          variablename                   1;	///< Required element.
/// Element value of type xs:anyType.
    std::string                          value                          1;	///< Required element.
};

/// "urn:sah":DeviceStateEx is a complexType.
class ns1__DeviceStateEx : public xsd__anyType
{ public:
/// Element id of type xs:string.
    std::string                          id                             1;	///< Required element.
/// Element name of type xs:string.
    std::string                          name                           1;	///< Required element.
/// Element username of type xs:string.
    std::string                          username                       1;	///< Required element.
/// Element status of type xs:string.
    std::string                          status                         1;	///< Required element.
/// Element text of type xs:string.
    std::string                          text                           1;	///< Required element.
/// Element state of type xs:int.
    int                                  state                          1;	///< Required element.
/// Element actions of type "urn:sah":ArrayOfString.
    ArrayOfString*                       actions                        1;	///< Required element.
};

/// "urn:sah":ArrayOfDeviceStates is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of "urn:sah":DeviceState
class ArrayOfDeviceStates : public xsd__anyType
{ public:
/// Pointer to array of ns1__DeviceState*.
    ns1__DeviceState*                   *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/// "urn:sah":ArrayOfMessageEvent is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of "urn:sah":MessageEvent
class ArrayOfMessageEvent : public xsd__anyType
{ public:
/// Pointer to array of ns1__MessageEvent*.
    ns1__MessageEvent*                  *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/// "urn:sah":ArrayOfDeviceStateVariable is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of "urn:sah":DeviceStateVariable
class ArrayOfDeviceStateVariable : public xsd__anyType
{ public:
/// Pointer to array of ns1__DeviceStateVariable*.
    ns1__DeviceStateVariable*           *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/// "urn:sah":ArrayOfString is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of xs:string
class ArrayOfString : public xsd__anyType
{ public:
/// Pointer to array of std::string.
    std::string                         *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/// "urn:sah":ArrayOfAnyType is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of xs:anyType
class ArrayOfAnyType : public xsd__anyType
{ public:
/// Pointer to array of xsd__anyType*.
    xsd__anyType*                       *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/// "urn:sah":ArrayOfDeviceStatesEx is a complexType with complexContent restriction of SOAP-ENC:Array.
/// SOAP encoded array of "urn:sah":DeviceStateEx
class ArrayOfDeviceStatesEx : public xsd__anyType
{ public:
/// Pointer to array of ns1__DeviceStateEx*.
    ns1__DeviceStateEx*                 *__ptr                         ;
/// Size of the dynamic array.
    int                                  __size                        ;
/// Offset for partially transmitted arrays (uncomment only when required).
//  int                                  __offset                      ;
};

/******************************************************************************\
 *                                                                            *
 * Services                                                                   *
 *                                                                            *
\******************************************************************************/


//gsoap ns1  service name:	SAHBinding 
//gsoap ns1  service type:	SAHPortType 
//gsoap ns1  service port:	http://192.168.1.210:8080/sah-ws 
//gsoap ns1  service namespace:	urn:sah 
//gsoap ns1  service transport:	http://schemas.xmlsoap.org/soap/http 

/** @mainpage Service Definitions

@section Service_bindings Bindings
  - @ref SAHBinding

*/

/**

@page SAHBinding Binding "SAHBinding"

@section SAHBinding_operations Operations of Binding  "SAHBinding"
  - @ref ns1__echo
  - @ref ns1__getServerTimestamp
  - @ref ns1__getAvailableDevicesIDs
  - @ref ns1__getDeviceOverviewData
  - @ref ns1__getDeviceOverviewExtendedData
  - @ref ns1__getAllDevicesOverviewData
  - @ref ns1__getAllDevicesOverviewExtendedData
  - @ref ns1__invokeAction
  - @ref ns1__getLastDevicesEvents
  - @ref ns1__getDeviceStateVariables
  - @ref ns1__getDeviceAvailableActions

@section SAHBinding_ports Endpoints of Binding  "SAHBinding"
  - http://192.168.1.210:8080/sah-ws

Note: use wsdl2h option -N to change the service binding prefix name

*/

/******************************************************************************\
 *                                                                            *
 * SAHBinding                                                                 *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * ns1__echo                                                                  *
 *                                                                            *
\******************************************************************************/


/// Operation "ns1__echo" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__echo(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         str,
    // response parameters:
    std::string                        &return_
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__echo(
    struct soap *soap,
    // request parameters:
    std::string                         str,
    // response parameters:
    std::string                        &return_
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	echo rpc
//gsoap ns1  service method-encoding:	echo http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	echo ""
int ns1__echo(
    std::string                         str,	///< Request parameter
    std::string                        &return_	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getServerTimestamp                                                    *
 *                                                                            *
\******************************************************************************/


/// Operation "ns1__getServerTimestamp" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getServerTimestamp(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    time_t                             &return_
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getServerTimestamp(
    struct soap *soap,
    // request parameters:
    // response parameters:
    time_t                             &return_
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getServerTimestamp rpc
//gsoap ns1  service method-encoding:	getServerTimestamp http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getServerTimestamp ""
int ns1__getServerTimestamp(
    time_t                             &return_	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getAvailableDevicesIDs                                                *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getAvailableDevicesIDsResponse" of service binding "SAHBinding" operation "ns1__getAvailableDevicesIDs"
struct ns1__getAvailableDevicesIDsResponse
{
    ArrayOfString*                      return_;
};

/// Operation "ns1__getAvailableDevicesIDs" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getAvailableDevicesIDs(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    struct ns1__getAvailableDevicesIDsResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getAvailableDevicesIDs(
    struct soap *soap,
    // request parameters:
    // response parameters:
    struct ns1__getAvailableDevicesIDsResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getAvailableDevicesIDs rpc
//gsoap ns1  service method-encoding:	getAvailableDevicesIDs http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getAvailableDevicesIDs ""
int ns1__getAvailableDevicesIDs(
    struct ns1__getAvailableDevicesIDsResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getDeviceOverviewData                                                 *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getDeviceOverviewDataResponse" of service binding "SAHBinding" operation "ns1__getDeviceOverviewData"
struct ns1__getDeviceOverviewDataResponse
{
    ns1__DeviceState*                   return_;
};

/// Operation "ns1__getDeviceOverviewData" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getDeviceOverviewData(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         deviceID,
    std::string                         locale,
    // response parameters:
    struct ns1__getDeviceOverviewDataResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getDeviceOverviewData(
    struct soap *soap,
    // request parameters:
    std::string                         deviceID,
    std::string                         locale,
    // response parameters:
    struct ns1__getDeviceOverviewDataResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getDeviceOverviewData rpc
//gsoap ns1  service method-encoding:	getDeviceOverviewData http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getDeviceOverviewData ""
int ns1__getDeviceOverviewData(
    std::string                         deviceID,	///< Request parameter
    std::string                         locale,	///< Request parameter
    struct ns1__getDeviceOverviewDataResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getDeviceOverviewExtendedData                                         *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getDeviceOverviewExtendedDataResponse" of service binding "SAHBinding" operation "ns1__getDeviceOverviewExtendedData"
struct ns1__getDeviceOverviewExtendedDataResponse
{
    ns1__DeviceStateEx*                 return_;
};

/// Operation "ns1__getDeviceOverviewExtendedData" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getDeviceOverviewExtendedData(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         deviceID,
    std::string                         locale,
    // response parameters:
    struct ns1__getDeviceOverviewExtendedDataResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getDeviceOverviewExtendedData(
    struct soap *soap,
    // request parameters:
    std::string                         deviceID,
    std::string                         locale,
    // response parameters:
    struct ns1__getDeviceOverviewExtendedDataResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getDeviceOverviewExtendedData rpc
//gsoap ns1  service method-encoding:	getDeviceOverviewExtendedData http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getDeviceOverviewExtendedData ""
int ns1__getDeviceOverviewExtendedData(
    std::string                         deviceID,	///< Request parameter
    std::string                         locale,	///< Request parameter
    struct ns1__getDeviceOverviewExtendedDataResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getAllDevicesOverviewData                                             *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getAllDevicesOverviewDataResponse" of service binding "SAHBinding" operation "ns1__getAllDevicesOverviewData"
struct ns1__getAllDevicesOverviewDataResponse
{
    ArrayOfDeviceStates*                return_;
};

/// Operation "ns1__getAllDevicesOverviewData" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getAllDevicesOverviewData(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         locale,
    // response parameters:
    struct ns1__getAllDevicesOverviewDataResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getAllDevicesOverviewData(
    struct soap *soap,
    // request parameters:
    std::string                         locale,
    // response parameters:
    struct ns1__getAllDevicesOverviewDataResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getAllDevicesOverviewData rpc
//gsoap ns1  service method-encoding:	getAllDevicesOverviewData http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getAllDevicesOverviewData ""
int ns1__getAllDevicesOverviewData(
    std::string                         locale,	///< Request parameter
    struct ns1__getAllDevicesOverviewDataResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getAllDevicesOverviewExtendedData                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getAllDevicesOverviewExtendedDataResponse" of service binding "SAHBinding" operation "ns1__getAllDevicesOverviewExtendedData"
struct ns1__getAllDevicesOverviewExtendedDataResponse
{
    ArrayOfDeviceStatesEx*              return_;
};

/// Operation "ns1__getAllDevicesOverviewExtendedData" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getAllDevicesOverviewExtendedData(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         locale,
    // response parameters:
    struct ns1__getAllDevicesOverviewExtendedDataResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getAllDevicesOverviewExtendedData(
    struct soap *soap,
    // request parameters:
    std::string                         locale,
    // response parameters:
    struct ns1__getAllDevicesOverviewExtendedDataResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getAllDevicesOverviewExtendedData rpc
//gsoap ns1  service method-encoding:	getAllDevicesOverviewExtendedData http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getAllDevicesOverviewExtendedData ""
int ns1__getAllDevicesOverviewExtendedData(
    std::string                         locale,	///< Request parameter
    struct ns1__getAllDevicesOverviewExtendedDataResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__invokeAction                                                          *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__invokeActionResponse" of service binding "SAHBinding" operation "ns1__invokeAction"
struct ns1__invokeActionResponse
{
    ArrayOfAnyType*                     return_;
};

/// Operation "ns1__invokeAction" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__invokeAction(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         deviceID,
    std::string                         actionName,
    ArrayOfString*                      parameters,
    // response parameters:
    struct ns1__invokeActionResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__invokeAction(
    struct soap *soap,
    // request parameters:
    std::string                         deviceID,
    std::string                         actionName,
    ArrayOfString*                      parameters,
    // response parameters:
    struct ns1__invokeActionResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	invokeAction rpc
//gsoap ns1  service method-encoding:	invokeAction http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	invokeAction ""
int ns1__invokeAction(
    std::string                         deviceID,	///< Request parameter
    std::string                         actionName,	///< Request parameter
    ArrayOfString*                      parameters,	///< Request parameter
    struct ns1__invokeActionResponse   &	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getLastDevicesEvents                                                  *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getLastDevicesEventsResponse" of service binding "SAHBinding" operation "ns1__getLastDevicesEvents"
struct ns1__getLastDevicesEventsResponse
{
    ArrayOfMessageEvent*                return_;
};

/// Operation "ns1__getLastDevicesEvents" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getLastDevicesEvents(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    time_t                              since,
    std::string                         lang,
    // response parameters:
    struct ns1__getLastDevicesEventsResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getLastDevicesEvents(
    struct soap *soap,
    // request parameters:
    time_t                              since,
    std::string                         lang,
    // response parameters:
    struct ns1__getLastDevicesEventsResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getLastDevicesEvents rpc
//gsoap ns1  service method-encoding:	getLastDevicesEvents http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getLastDevicesEvents ""
int ns1__getLastDevicesEvents(
    time_t                              since,	///< Request parameter
    std::string                         lang,	///< Request parameter
    struct ns1__getLastDevicesEventsResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getDeviceStateVariables                                               *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getDeviceStateVariablesResponse" of service binding "SAHBinding" operation "ns1__getDeviceStateVariables"
struct ns1__getDeviceStateVariablesResponse
{
    ArrayOfDeviceStateVariable*         return_;
};

/// Operation "ns1__getDeviceStateVariables" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getDeviceStateVariables(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         deviceID,
    ArrayOfString*                      variableNames,
    // response parameters:
    struct ns1__getDeviceStateVariablesResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getDeviceStateVariables(
    struct soap *soap,
    // request parameters:
    std::string                         deviceID,
    ArrayOfString*                      variableNames,
    // response parameters:
    struct ns1__getDeviceStateVariablesResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getDeviceStateVariables rpc
//gsoap ns1  service method-encoding:	getDeviceStateVariables http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getDeviceStateVariables ""
int ns1__getDeviceStateVariables(
    std::string                         deviceID,	///< Request parameter
    ArrayOfString*                      variableNames,	///< Request parameter
    struct ns1__getDeviceStateVariablesResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * ns1__getDeviceAvailableActions                                             *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__getDeviceAvailableActionsResponse" of service binding "SAHBinding" operation "ns1__getDeviceAvailableActions"
struct ns1__getDeviceAvailableActionsResponse
{
    ArrayOfString*                      return_;
};

/// Operation "ns1__getDeviceAvailableActions" of service binding "SAHBinding"

/**

Operation details:

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__getDeviceAvailableActions(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         deviceID,
    // response parameters:
    struct ns1__getDeviceAvailableActionsResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__getDeviceAvailableActions(
    struct soap *soap,
    // request parameters:
    std::string                         deviceID,
    // response parameters:
    struct ns1__getDeviceAvailableActionsResponse&
  );
@endcode

C++ proxy class (defined in soapSAHBindingProxy.h):
  class SAHBinding;

Note: use soapcpp2 option '-i' to generate improved proxy and service classes;

*/

//gsoap ns1  service method-style:	getDeviceAvailableActions rpc
//gsoap ns1  service method-encoding:	getDeviceAvailableActions http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	getDeviceAvailableActions ""
int ns1__getDeviceAvailableActions(
    std::string                         deviceID,	///< Request parameter
    struct ns1__getDeviceAvailableActionsResponse&	///< Response struct parameter
);

/* End of webserver.h */