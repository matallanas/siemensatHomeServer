/* soapSAHBindingProxy.cpp
   Generated by gSOAP 2.7.12 from webserver.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/
#ifndef SOAPSAHBBINDIGNPROXY_H_
#define SOAPSAHBBINDIGNPROXY_H_
#include "soapSAHBindingProxy.h"

SAHBindingProxy::SAHBindingProxy()
{	SAHBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

SAHBindingProxy::SAHBindingProxy(const struct soap &soap)
{	soap_copy_context(this, &soap);
	SAHBindingProxy_init(soap.imode, soap.omode);
}

SAHBindingProxy::SAHBindingProxy(soap_mode iomode)
{	SAHBindingProxy_init(iomode, iomode);
}

SAHBindingProxy::SAHBindingProxy(soap_mode imode, soap_mode omode)
{	SAHBindingProxy_init(imode, omode);
}

void SAHBindingProxy::SAHBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
  soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "urn:sah", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	if (!this->namespaces)
		this->namespaces = namespaces;
}

SAHBindingProxy::~SAHBindingProxy()
{ }

void SAHBindingProxy::soap_noheader()
{	header = NULL;
}

const SOAP_ENV__Fault *SAHBindingProxy::soap_fault()
{	return this->fault;
}

const char *SAHBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *SAHBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int SAHBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

void SAHBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void SAHBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *SAHBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int SAHBindingProxy::echo(std::string str, std::string &return_)
{	struct soap *soap = this;
	struct ns1__echo soap_tmp_ns1__echo;
	struct ns1__echoResponse *soap_tmp_ns1__echoResponse;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__echo.str = str;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__echo(soap, &soap_tmp_ns1__echo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__echo(soap, &soap_tmp_ns1__echo, "ns1:echo", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__echo(soap, &soap_tmp_ns1__echo, "ns1:echo", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&return_)
		return soap_closesock(soap);
	soap_default_std__string(soap, &return_);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns1__echoResponse = soap_get_ns1__echoResponse(soap, NULL, "ns1:echoResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return_ = soap_tmp_ns1__echoResponse->return_;
	return soap_closesock(soap);
}

int SAHBindingProxy::getServerTimestamp(time_t &return_)
{	struct soap *soap = this;
	struct ns1__getServerTimestamp soap_tmp_ns1__getServerTimestamp;
	struct ns1__getServerTimestampResponse *soap_tmp_ns1__getServerTimestampResponse;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getServerTimestamp(soap, &soap_tmp_ns1__getServerTimestamp);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getServerTimestamp(soap, &soap_tmp_ns1__getServerTimestamp, "ns1:getServerTimestamp", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getServerTimestamp(soap, &soap_tmp_ns1__getServerTimestamp, "ns1:getServerTimestamp", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&return_)
		return soap_closesock(soap);
	soap_default_time(soap, &return_);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns1__getServerTimestampResponse = soap_get_ns1__getServerTimestampResponse(soap, NULL, "ns1:getServerTimestampResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return_ = soap_tmp_ns1__getServerTimestampResponse->return_;
	return soap_closesock(soap);
}

int SAHBindingProxy::getAvailableDevicesIDs(struct ns1__getAvailableDevicesIDsResponse &_param_1)
{	struct soap *soap = this;
	struct ns1__getAvailableDevicesIDs soap_tmp_ns1__getAvailableDevicesIDs;
	const char *soap_action = NULL;
  if (!soap_endpoint)
    //soap_endpoint = "http://192.168.1.210:8080/sah-ws";
    soap_endpoint = "http://138.4.46.63:8021/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getAvailableDevicesIDs(soap, &soap_tmp_ns1__getAvailableDevicesIDs);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getAvailableDevicesIDs(soap, &soap_tmp_ns1__getAvailableDevicesIDs, "ns1:getAvailableDevicesIDs", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getAvailableDevicesIDs(soap, &soap_tmp_ns1__getAvailableDevicesIDs, "ns1:getAvailableDevicesIDs", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_1)
		return soap_closesock(soap);
	soap_default_ns1__getAvailableDevicesIDsResponse(soap, &_param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getAvailableDevicesIDsResponse(soap, &_param_1, "ns1:getAvailableDevicesIDsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getDeviceOverviewData(std::string deviceID, std::string locale, struct ns1__getDeviceOverviewDataResponse &_param_2)
{	struct soap *soap = this;
	struct ns1__getDeviceOverviewData soap_tmp_ns1__getDeviceOverviewData;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getDeviceOverviewData.deviceID = deviceID;
	soap_tmp_ns1__getDeviceOverviewData.locale = locale;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getDeviceOverviewData(soap, &soap_tmp_ns1__getDeviceOverviewData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getDeviceOverviewData(soap, &soap_tmp_ns1__getDeviceOverviewData, "ns1:getDeviceOverviewData", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getDeviceOverviewData(soap, &soap_tmp_ns1__getDeviceOverviewData, "ns1:getDeviceOverviewData", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_2)
		return soap_closesock(soap);
	soap_default_ns1__getDeviceOverviewDataResponse(soap, &_param_2);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getDeviceOverviewDataResponse(soap, &_param_2, "ns1:getDeviceOverviewDataResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getDeviceOverviewExtendedData(std::string deviceID, std::string locale, struct ns1__getDeviceOverviewExtendedDataResponse &_param_3)
{	struct soap *soap = this;
	struct ns1__getDeviceOverviewExtendedData soap_tmp_ns1__getDeviceOverviewExtendedData;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getDeviceOverviewExtendedData.deviceID = deviceID;
	soap_tmp_ns1__getDeviceOverviewExtendedData.locale = locale;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getDeviceOverviewExtendedData(soap, &soap_tmp_ns1__getDeviceOverviewExtendedData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getDeviceOverviewExtendedData(soap, &soap_tmp_ns1__getDeviceOverviewExtendedData, "ns1:getDeviceOverviewExtendedData", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getDeviceOverviewExtendedData(soap, &soap_tmp_ns1__getDeviceOverviewExtendedData, "ns1:getDeviceOverviewExtendedData", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_3)
		return soap_closesock(soap);
	soap_default_ns1__getDeviceOverviewExtendedDataResponse(soap, &_param_3);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getDeviceOverviewExtendedDataResponse(soap, &_param_3, "ns1:getDeviceOverviewExtendedDataResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getAllDevicesOverviewData(std::string locale, struct ns1__getAllDevicesOverviewDataResponse &_param_4)
{	struct soap *soap = this;
	struct ns1__getAllDevicesOverviewData soap_tmp_ns1__getAllDevicesOverviewData;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getAllDevicesOverviewData.locale = locale;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getAllDevicesOverviewData(soap, &soap_tmp_ns1__getAllDevicesOverviewData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getAllDevicesOverviewData(soap, &soap_tmp_ns1__getAllDevicesOverviewData, "ns1:getAllDevicesOverviewData", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getAllDevicesOverviewData(soap, &soap_tmp_ns1__getAllDevicesOverviewData, "ns1:getAllDevicesOverviewData", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_4)
		return soap_closesock(soap);
	soap_default_ns1__getAllDevicesOverviewDataResponse(soap, &_param_4);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getAllDevicesOverviewDataResponse(soap, &_param_4, "ns1:getAllDevicesOverviewDataResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getAllDevicesOverviewExtendedData(std::string locale, struct ns1__getAllDevicesOverviewExtendedDataResponse &_param_5)
{	struct soap *soap = this;
	struct ns1__getAllDevicesOverviewExtendedData soap_tmp_ns1__getAllDevicesOverviewExtendedData;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getAllDevicesOverviewExtendedData.locale = locale;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getAllDevicesOverviewExtendedData(soap, &soap_tmp_ns1__getAllDevicesOverviewExtendedData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getAllDevicesOverviewExtendedData(soap, &soap_tmp_ns1__getAllDevicesOverviewExtendedData, "ns1:getAllDevicesOverviewExtendedData", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getAllDevicesOverviewExtendedData(soap, &soap_tmp_ns1__getAllDevicesOverviewExtendedData, "ns1:getAllDevicesOverviewExtendedData", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_5)
		return soap_closesock(soap);
	soap_default_ns1__getAllDevicesOverviewExtendedDataResponse(soap, &_param_5);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getAllDevicesOverviewExtendedDataResponse(soap, &_param_5, "ns1:getAllDevicesOverviewExtendedDataResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::invokeAction(std::string deviceID, std::string actionName, ArrayOfString *parameters, struct ns1__invokeActionResponse &_param_6)
{	struct soap *soap = this;
	struct ns1__invokeAction soap_tmp_ns1__invokeAction;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__invokeAction.deviceID = deviceID;
	soap_tmp_ns1__invokeAction.actionName = actionName;
	soap_tmp_ns1__invokeAction.parameters = parameters;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__invokeAction(soap, &soap_tmp_ns1__invokeAction);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__invokeAction(soap, &soap_tmp_ns1__invokeAction, "ns1:invokeAction", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__invokeAction(soap, &soap_tmp_ns1__invokeAction, "ns1:invokeAction", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_6)
		return soap_closesock(soap);
	soap_default_ns1__invokeActionResponse(soap, &_param_6);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__invokeActionResponse(soap, &_param_6, "ns1:invokeActionResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getLastDevicesEvents(time_t since, std::string lang, struct ns1__getLastDevicesEventsResponse &_param_7)
{	struct soap *soap = this;
	struct ns1__getLastDevicesEvents soap_tmp_ns1__getLastDevicesEvents;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getLastDevicesEvents.since = since;
	soap_tmp_ns1__getLastDevicesEvents.lang = lang;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getLastDevicesEvents(soap, &soap_tmp_ns1__getLastDevicesEvents);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getLastDevicesEvents(soap, &soap_tmp_ns1__getLastDevicesEvents, "ns1:getLastDevicesEvents", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getLastDevicesEvents(soap, &soap_tmp_ns1__getLastDevicesEvents, "ns1:getLastDevicesEvents", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_7)
		return soap_closesock(soap);
	soap_default_ns1__getLastDevicesEventsResponse(soap, &_param_7);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getLastDevicesEventsResponse(soap, &_param_7, "ns1:getLastDevicesEventsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getDeviceStateVariables(std::string deviceID, ArrayOfString *variableNames, struct ns1__getDeviceStateVariablesResponse &_param_8)
{	struct soap *soap = this;
	struct ns1__getDeviceStateVariables soap_tmp_ns1__getDeviceStateVariables;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getDeviceStateVariables.deviceID = deviceID;
	soap_tmp_ns1__getDeviceStateVariables.variableNames = variableNames;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getDeviceStateVariables(soap, &soap_tmp_ns1__getDeviceStateVariables);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getDeviceStateVariables(soap, &soap_tmp_ns1__getDeviceStateVariables, "ns1:getDeviceStateVariables", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getDeviceStateVariables(soap, &soap_tmp_ns1__getDeviceStateVariables, "ns1:getDeviceStateVariables", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_8)
		return soap_closesock(soap);
	soap_default_ns1__getDeviceStateVariablesResponse(soap, &_param_8);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getDeviceStateVariablesResponse(soap, &_param_8, "ns1:getDeviceStateVariablesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SAHBindingProxy::getDeviceAvailableActions(std::string deviceID, struct ns1__getDeviceAvailableActionsResponse &_param_9)
{	struct soap *soap = this;
	struct ns1__getDeviceAvailableActions soap_tmp_ns1__getDeviceAvailableActions;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.210:8080/sah-ws";
	soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns1__getDeviceAvailableActions.deviceID = deviceID;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns1__getDeviceAvailableActions(soap, &soap_tmp_ns1__getDeviceAvailableActions);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__getDeviceAvailableActions(soap, &soap_tmp_ns1__getDeviceAvailableActions, "ns1:getDeviceAvailableActions", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__getDeviceAvailableActions(soap, &soap_tmp_ns1__getDeviceAvailableActions, "ns1:getDeviceAvailableActions", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_9)
		return soap_closesock(soap);
	soap_default_ns1__getDeviceAvailableActionsResponse(soap, &_param_9);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__getDeviceAvailableActionsResponse(soap, &_param_9, "ns1:getDeviceAvailableActionsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
#endif
