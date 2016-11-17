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

#include "common.h"
/******************************************************************************/
/******************************************************************************/                         
/* WRITE LOG FILE FUNCTION                                                    */                         
/*                                                                            */                         
/* Write the errors in the log file.                                          */                         
/*                                                                            */                         
/******************************************************************************/                         
void writeLogFile ( string cLogFile, int R_CODE, string TEXT ){                                          
  time_t log_comp_time;                                                                                  
  tm     *log_time;                                                                                      
  time(&log_comp_time);                                                                                  
  log_time = localtime(&log_comp_time);                                                                  
  ofstream logFile (cLogFile.c_str(), ios::app);                                                         
  logFile << (log_time->tm_year + 1900) << "/"<< (log_time->tm_mon + 1) << "/"<< log_time->tm_mday << " " << log_time->tm_hour << ":" << log_time->tm_min << ":" << log_time->tm_sec << " " << " C-" << R_CODE << " " << TEXT << endl; 
  logFile.close();
  return;
};
