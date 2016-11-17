#!/bin/bash

ROOT_DIR=$HOME/siemensatHomeServer

#Compilation Folder Name
COMPILE_FOLDER=build
SRC_FOLDER=src
PROGRAM_BIN=appCom
PARAM_FILE=cnf/configuration.xml
#Structure Folders
softFolders=(common
             common/gSoapWebServer
             elements
             elements/appliances)

#INSTALLING 
if  [ $1 = "install" ]; then
	#Create folders if needed 
	#Copy the autotools to the new folder
	#Check if compiling folder exists
	if [ -d "$COMPILE_FOLDER" ]; then
		#Copy the configure.ac if it does not exist
		if [ ! -e $COMPILE_FOLDER/configure.ac ]; then
			cp $SRC_FOLDER/configure.ac $COMPILE_FOLDER
		fi
		#Copy the Makefile.am if it does not exist
		if [ ! -e $COMPILE_FOLDER/Makefile.am ]; then
			cp $SRC_FOLDER/Makefile.am $COMPILE_FOLDER
		fi
		#Check if the subfolder of compilation exist
		for item in ${softFolders[*]}
		do
			#If the folder does not exist, it creates the folder and add the Makefile.am
			if [ ! -d $COMPILE_FOLDER/$item ]; then
				mkdir $COMPILE_FOLDER/$item
				cp $SRC_FOLDER/$item/Makefile.am $COMPILE_FOLDER/$item
			#If folder exists, only check if the Makefile.am exists
			elif [ ! -e $COMPILE_FOLDER/$item/Makefile.am ]; then
				cp $SRC_FOLDER/$item/Makefile.am $COMPILE_FOLDER/$item
			fi
		done
	#If the folder does not exist create all the folder and subfolders
	# Also add the autotools needed to install the program
	else

		mkdir $COMPILE_FOLDER
		cp $SRC_FOLDER/configure.ac $COMPILE_FOLDER
		cp $SRC_FOLDER/Makefile.am $COMPILE_FOLDER
		
		for item in ${softFolders[*]}
		do
			mkdir $COMPILE_FOLDER/$item
			cp $SRC_FOLDER/$item/Makefile.am $COMPILE_FOLDER/$item
		done
	fi
	#First installation
	cd $COMPILE_FOLDER
	if [[ ! -e configure ]]; then
		autoreconf -i
	fi
	if [[ ! -e Makefile.in ]]; then
		automake --include-deps --add-missing --foreign
	fi
	if [[ ! -e Makefile ]]; then
		./configure
	fi
elif [ $1 = "make" ]; then
	cd $COMPILE_FOLDER
  rm $PROGRAM_BIN
	if [[ ! -e configure ]]; then
		autoreconf -i
	fi
	if [[ ! -e Makefile.in ]]; then
		automake --include-deps --add-missing --foreign
	fi
	if [[ ! -e Makefile ]]; then
		./configure
	fi
	make
elif [ $1 = "exe" ]; then
	$COMPILE_FOLDER/$PROGRAM_BIN -p $PARAM_FILE
elif [ $1 = "clean" ]; then
	cd $COMPILE_FOLDER
	make clean
elif [ $1 = "distclean" ]; then
	cd $COMPILE_FOLDER
	make distclean
elif [ $1 = "uninstall" ]; then
	rm -r $COMPILE_FOLDER
elif [ $1 = "doc" ]; then
  doxygen $DOC_FOLDER/$PROGRAM_BIN
elif [ $1 = "rmdoc" ]; then
	rm -r $DOC_FOLDER/html
	rm -r $DOC_FOLDER/latex
else
	echo ERROR: NO OPTION RECOGNIZED;
	echo "  install   - Install the code";
	echo "  make      - Compile the code";
	echo "  exe       - Execute the code";
	echo "  clean     - Clean the code";
	echo "  distclean - DistClean the code";
	echo "  uninstall - Uninstall the code";
	echo "  doc       - Make the doxygen documentation";
	echo "  rmdoc     - Remove the documentation";
fi
