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
/* LIBRARY COMMON 							                                 /
/* It contains common data types and structures				           /
/****************************************************************/
#ifndef COMMON_H_
#define COMMON_H_

/****************************************************************/
/* MACROS */
/****************************************************************/
/* LIBRARIES */
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <string>

#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

/****************************************************************/
/* VECTOR DATA TYPES */

/*String vector*/
typedef vector<string> TSV;
typedef vector<string>::iterator TSVite;

void writeLogFile ( string cLogFile, int R_CODE, string TEXT ); 

#endif
