# siemensatHomeServer

## Description
This piece of code is able to connect the Siemens@Home appliances with a database to iupdate the status of the appliances and actuate over them through different scheduling programs introduced in the database.

## Installation
This code is used on linux distribution.

####Dependences:
Debian based distribution:
apt-get install g++ make automake autotools-dev libtool libgsl0-dev libxml2-dev libmysqld-dev libmysqlclient-dev libmysql++-dev 

####Compilation:
mkdir build
./appCom.sh install
./appCom.sh make

####Execution:
./mysql_soft [-p <files_path>] [rest of the options]

####Usage:
Parameter file:
-p  Configuration file for the program
Options:
-a  Check the programs of the appliances and actuate over them.
-c  Create a table in the database
-D  Drop a table in the databas
-d  Delete the values of a table
-u  Update the status of the different appliances
-h  Shows the help of the program
