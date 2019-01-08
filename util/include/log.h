#ifndef _LDRLOG_
#define _LDRLOG_


#ifdef _DBG

#include <stdio.h>
#include <time.h>
#include <direct.h>
#include <stdarg.h>
#include <string>


#define LOG_ALL -1
#define LOG_GENERAL 1

void SetLogPath(std::string log_path_param ) ;
void SetLogLevel(unsigned int log_level_arg);
unsigned int GetLogLevel();
void Log(char* format, ...);
void Log(unsigned int log_level_arg, char* format, ...);
void Log(unsigned int log_level_arg, char* format, va_list ap);

#endif

#endif