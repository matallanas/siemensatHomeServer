AM_CPPFLAGS          = -I../../src -I../../src/common -I../../src/common/gSoapWebServer -I/usr/include/mysql
lib_LTLIBRARIES      = libcommon.la
libcommon_la_SOURCES = ../../src/common/common.cpp\
											 ../../src/common/tinyxml2.cpp\
											 ../../src/common/mysqldb.cpp
libcommon_la_LIBADD  = gSoapWebServer/libgsoap.la -lgsl -lgslcblas -lX11 -L/usr/X11R6/lib -lpthread -lmysqlclient
libcommon_la_LDFLAGS = `mysql_config --cflags` `mysql_config --libs` 
