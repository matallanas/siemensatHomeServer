CPPFLAGS = -I../src -I../src/common -I../src/common/gSoapWebServer -I../src/elements -I../src/elements/appliances -I/usr/include -I/usr/include/gsl -I/usr/include/mysql 
SUBDIRS = common/gSoapWebServer common elements/appliances elements
bin_PROGRAMS  = appCom
appCom_SOURCES = ../src/main.cpp 
appCom_LDADD   = -Lelements -lelements
appCom_LDFLAGS = -static 
