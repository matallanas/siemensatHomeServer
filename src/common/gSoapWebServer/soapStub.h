/* soapStub.h
   Generated by gSOAP 2.7.12 from webserver.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#include <vector>
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not redeclare here */

#endif

#ifndef SOAP_TYPE_xsd__anyType
#define SOAP_TYPE_xsd__anyType (8)
/* Primitive xsd:anyType schema type: */
class SOAP_CMAC xsd__anyType
{
public:
	char *__item;
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 8; } /* = unique id SOAP_TYPE_xsd__anyType */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__anyType() : __item(NULL), soap(NULL) { }
	virtual ~xsd__anyType() { }
};
#endif

#ifndef SOAP_TYPE_xsd__dateTime
#define SOAP_TYPE_xsd__dateTime (10)
/* Primitive xsd:dateTime schema type: */
class SOAP_CMAC xsd__dateTime : public xsd__anyType
{
public:
	time_t __item;
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE_xsd__dateTime */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__dateTime() : __item(0) { }
	virtual ~xsd__dateTime() { }
};
#endif

#ifndef SOAP_TYPE_xsd__int
#define SOAP_TYPE_xsd__int (12)
/* Primitive xsd:int schema type: */
class SOAP_CMAC xsd__int : public xsd__anyType
{
public:
	int __item;
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE_xsd__int */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__int() : __item(0) { }
	virtual ~xsd__int() { }
};
#endif

#ifndef SOAP_TYPE_xsd__long
#define SOAP_TYPE_xsd__long (13)
/* Primitive xsd:long schema type: */
class SOAP_CMAC xsd__long : public xsd__anyType
{
public:
	LONG64 __item;
public:
	virtual int soap_type() const { return 13; } /* = unique id SOAP_TYPE_xsd__long */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__long() : __item(0) { }
	virtual ~xsd__long() { }
};
#endif

#if 0 /* volatile type: do not redeclare here */

#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (15)
/* Primitive xsd:string schema type: */
class SOAP_CMAC xsd__string : public xsd__anyType
{
public:
	std::string __item;
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE_xsd__string */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__string()  { }
	virtual ~xsd__string() { }
};
#endif

#ifndef SOAP_TYPE_ns1__DeviceState
#define SOAP_TYPE_ns1__DeviceState (17)
/* ns1:DeviceState */
class SOAP_CMAC ns1__DeviceState : public xsd__anyType
{
public:
	std::string id;	/* required element of type xsd:string */
	std::string name;	/* required element of type xsd:string */
	std::string username;	/* required element of type xsd:string */
	std::string status;	/* required element of type xsd:string */
	std::string text;	/* required element of type xsd:string */
	int state;	/* required element of type xsd:int */
public:
	virtual int soap_type() const { return 17; } /* = unique id SOAP_TYPE_ns1__DeviceState */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__DeviceState() : state(0) { }
	virtual ~ns1__DeviceState() { }
};
#endif

#ifndef SOAP_TYPE_ns1__MessageEvent
#define SOAP_TYPE_ns1__MessageEvent (18)
/* ns1:MessageEvent */
class SOAP_CMAC ns1__MessageEvent : public xsd__anyType
{
public:
	LONG64 id;	/* required element of type xsd:long */
	std::string sender;	/* required element of type xsd:string */
	std::string text;	/* required element of type xsd:string */
	time_t timestamp;	/* required element of type xsd:dateTime */
	int type;	/* required element of type xsd:int */
public:
	virtual int soap_type() const { return 18; } /* = unique id SOAP_TYPE_ns1__MessageEvent */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__MessageEvent() : id(0), timestamp(0), type(0) { }
	virtual ~ns1__MessageEvent() { }
};
#endif

#ifndef SOAP_TYPE_ns1__DeviceStateVariable
#define SOAP_TYPE_ns1__DeviceStateVariable (19)
/* ns1:DeviceStateVariable */
class SOAP_CMAC ns1__DeviceStateVariable : public xsd__anyType
{
public:
	std::string variablename;	/* required element of type xsd:string */
	std::string value;	/* required element of type xsd:string */
public:
	virtual int soap_type() const { return 19; } /* = unique id SOAP_TYPE_ns1__DeviceStateVariable */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__DeviceStateVariable()  { }
	virtual ~ns1__DeviceStateVariable() { }
};
#endif

#ifndef SOAP_TYPE_ns1__DeviceStateEx
#define SOAP_TYPE_ns1__DeviceStateEx (25)
/* ns1:DeviceStateEx */
class SOAP_CMAC ns1__DeviceStateEx : public xsd__anyType
{
public:
	std::string id;	/* required element of type xsd:string */
	std::string name;	/* required element of type xsd:string */
	std::string username;	/* required element of type xsd:string */
	std::string status;	/* required element of type xsd:string */
	std::string text;	/* required element of type xsd:string */
	int state;	/* required element of type xsd:int */
	class ArrayOfString *actions;	/* required element of type ArrayOfstring */
public:
	virtual int soap_type() const { return 25; } /* = unique id SOAP_TYPE_ns1__DeviceStateEx */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__DeviceStateEx() : state(0), actions(NULL) { }
	virtual ~ns1__DeviceStateEx() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfDeviceStates
#define SOAP_TYPE_ArrayOfDeviceStates (20)
/* SOAP encoded array of ns1:DeviceState schema type: */
class SOAP_CMAC ArrayOfDeviceStates : public xsd__anyType
{
public:
	ns1__DeviceState **__ptr;
	int __size;
public:
	virtual int soap_type() const { return 20; } /* = unique id SOAP_TYPE_ArrayOfDeviceStates */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfDeviceStates() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfDeviceStates() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfMessageEvent
#define SOAP_TYPE_ArrayOfMessageEvent (21)
/* SOAP encoded array of ns1:MessageEvent schema type: */
class SOAP_CMAC ArrayOfMessageEvent : public xsd__anyType
{
public:
	ns1__MessageEvent **__ptr;
	int __size;
public:
	virtual int soap_type() const { return 21; } /* = unique id SOAP_TYPE_ArrayOfMessageEvent */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfMessageEvent() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfMessageEvent() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfDeviceStateVariable
#define SOAP_TYPE_ArrayOfDeviceStateVariable (22)
/* SOAP encoded array of ns1:DeviceStateVariable schema type: */
class SOAP_CMAC ArrayOfDeviceStateVariable : public xsd__anyType
{
public:
	ns1__DeviceStateVariable **__ptr;
	int __size;
public:
	virtual int soap_type() const { return 22; } /* = unique id SOAP_TYPE_ArrayOfDeviceStateVariable */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfDeviceStateVariable() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfDeviceStateVariable() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfString
#define SOAP_TYPE_ArrayOfString (23)
/* SOAP encoded array of xsd:string schema type: */
class SOAP_CMAC ArrayOfString : public xsd__anyType
{
public:
	std::string *__ptr;
	int __size;
public:
	virtual int soap_type() const { return 23; } /* = unique id SOAP_TYPE_ArrayOfString */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfString() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfString() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfAnyType
#define SOAP_TYPE_ArrayOfAnyType (24)
/* SOAP encoded array of xsd:anyType schema type: */
class SOAP_CMAC ArrayOfAnyType : public xsd__anyType
{
public:
	xsd__anyType **__ptr;
	int __size;
public:
	virtual int soap_type() const { return 24; } /* = unique id SOAP_TYPE_ArrayOfAnyType */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfAnyType() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfAnyType() { }
};
#endif

#ifndef SOAP_TYPE_ArrayOfDeviceStatesEx
#define SOAP_TYPE_ArrayOfDeviceStatesEx (26)
/* SOAP encoded array of ns1:DeviceStateEx schema type: */
class SOAP_CMAC ArrayOfDeviceStatesEx : public xsd__anyType
{
public:
	ns1__DeviceStateEx **__ptr;
	int __size;
public:
	virtual int soap_type() const { return 26; } /* = unique id SOAP_TYPE_ArrayOfDeviceStatesEx */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ArrayOfDeviceStatesEx() : __ptr(NULL), __size(0) { }
	virtual ~ArrayOfDeviceStatesEx() { }
};
#endif

#ifndef SOAP_TYPE_ns1__echoResponse
#define SOAP_TYPE_ns1__echoResponse (41)
/* ns1:echoResponse */
struct ns1__echoResponse
{
public:
	std::string return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__echo
#define SOAP_TYPE_ns1__echo (42)
/* ns1:echo */
struct ns1__echo
{
public:
	std::string str;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__getServerTimestampResponse
#define SOAP_TYPE_ns1__getServerTimestampResponse (45)
/* ns1:getServerTimestampResponse */
struct ns1__getServerTimestampResponse
{
public:
	time_t return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:dateTime */
};
#endif

#ifndef SOAP_TYPE_ns1__getServerTimestamp
#define SOAP_TYPE_ns1__getServerTimestamp (46)
/* ns1:getServerTimestamp */
struct ns1__getServerTimestamp
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ns1__getAvailableDevicesIDsResponse
#define SOAP_TYPE_ns1__getAvailableDevicesIDsResponse (47)
/* ns1:getAvailableDevicesIDsResponse */
struct ns1__getAvailableDevicesIDsResponse
{
public:
	ArrayOfString *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns1__getAvailableDevicesIDs
#define SOAP_TYPE_ns1__getAvailableDevicesIDs (50)
/* ns1:getAvailableDevicesIDs */
struct ns1__getAvailableDevicesIDs
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceOverviewDataResponse
#define SOAP_TYPE_ns1__getDeviceOverviewDataResponse (51)
/* ns1:getDeviceOverviewDataResponse */
struct ns1__getDeviceOverviewDataResponse
{
public:
	ns1__DeviceState *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns1:DeviceState */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceOverviewData
#define SOAP_TYPE_ns1__getDeviceOverviewData (54)
/* ns1:getDeviceOverviewData */
struct ns1__getDeviceOverviewData
{
public:
	std::string deviceID;	/* required element of type xsd:string */
	std::string locale;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceOverviewExtendedDataResponse
#define SOAP_TYPE_ns1__getDeviceOverviewExtendedDataResponse (55)
/* ns1:getDeviceOverviewExtendedDataResponse */
struct ns1__getDeviceOverviewExtendedDataResponse
{
public:
	ns1__DeviceStateEx *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns1:DeviceStateEx */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceOverviewExtendedData
#define SOAP_TYPE_ns1__getDeviceOverviewExtendedData (58)
/* ns1:getDeviceOverviewExtendedData */
struct ns1__getDeviceOverviewExtendedData
{
public:
	std::string deviceID;	/* required element of type xsd:string */
	std::string locale;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__getAllDevicesOverviewDataResponse
#define SOAP_TYPE_ns1__getAllDevicesOverviewDataResponse (59)
/* ns1:getAllDevicesOverviewDataResponse */
struct ns1__getAllDevicesOverviewDataResponse
{
public:
	ArrayOfDeviceStates *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfDeviceState */
};
#endif

#ifndef SOAP_TYPE_ns1__getAllDevicesOverviewData
#define SOAP_TYPE_ns1__getAllDevicesOverviewData (63)
/* ns1:getAllDevicesOverviewData */
struct ns1__getAllDevicesOverviewData
{
public:
	std::string locale;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__getAllDevicesOverviewExtendedDataResponse
#define SOAP_TYPE_ns1__getAllDevicesOverviewExtendedDataResponse (64)
/* ns1:getAllDevicesOverviewExtendedDataResponse */
struct ns1__getAllDevicesOverviewExtendedDataResponse
{
public:
	ArrayOfDeviceStatesEx *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfDeviceStateEx */
};
#endif

#ifndef SOAP_TYPE_ns1__getAllDevicesOverviewExtendedData
#define SOAP_TYPE_ns1__getAllDevicesOverviewExtendedData (68)
/* ns1:getAllDevicesOverviewExtendedData */
struct ns1__getAllDevicesOverviewExtendedData
{
public:
	std::string locale;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__invokeActionResponse
#define SOAP_TYPE_ns1__invokeActionResponse (69)
/* ns1:invokeActionResponse */
struct ns1__invokeActionResponse
{
public:
	ArrayOfAnyType *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfanyType */
};
#endif

#ifndef SOAP_TYPE_ns1__invokeAction
#define SOAP_TYPE_ns1__invokeAction (73)
/* ns1:invokeAction */
struct ns1__invokeAction
{
public:
	std::string deviceID;	/* required element of type xsd:string */
	std::string actionName;	/* required element of type xsd:string */
	ArrayOfString *parameters;	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns1__getLastDevicesEventsResponse
#define SOAP_TYPE_ns1__getLastDevicesEventsResponse (74)
/* ns1:getLastDevicesEventsResponse */
struct ns1__getLastDevicesEventsResponse
{
public:
	ArrayOfMessageEvent *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfMessageEvent */
};
#endif

#ifndef SOAP_TYPE_ns1__getLastDevicesEvents
#define SOAP_TYPE_ns1__getLastDevicesEvents (78)
/* ns1:getLastDevicesEvents */
struct ns1__getLastDevicesEvents
{
public:
	time_t since;	/* required element of type xsd:dateTime */
	std::string lang;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceStateVariablesResponse
#define SOAP_TYPE_ns1__getDeviceStateVariablesResponse (79)
/* ns1:getDeviceStateVariablesResponse */
struct ns1__getDeviceStateVariablesResponse
{
public:
	ArrayOfDeviceStateVariable *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfDeviceStateVariable */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceStateVariables
#define SOAP_TYPE_ns1__getDeviceStateVariables (83)
/* ns1:getDeviceStateVariables */
struct ns1__getDeviceStateVariables
{
public:
	std::string deviceID;	/* required element of type xsd:string */
	ArrayOfString *variableNames;	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceAvailableActionsResponse
#define SOAP_TYPE_ns1__getDeviceAvailableActionsResponse (84)
/* ns1:getDeviceAvailableActionsResponse */
struct ns1__getDeviceAvailableActionsResponse
{
public:
	ArrayOfString *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns1__getDeviceAvailableActions
#define SOAP_TYPE_ns1__getDeviceAvailableActions (87)
/* ns1:getDeviceAvailableActions */
struct ns1__getDeviceAvailableActions
{
public:
	std::string deviceID;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (88)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (89)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (91)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (94)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (95)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
