
#ifdef _DBG

#include "log.h"


std::string log_path;
unsigned int log_level = LOG_ALL;

//=========================================================================
/**
	Log the string
*/
void SetLogPath(std::string log_path_param ) {
	log_path.assign(log_path_param);
}

//=========================================================================
/**
	Set the log level
*/
void SetLogLevel(unsigned int log_level_arg) {
	log_level = log_level_arg;
}

//=========================================================================
/**
	Get the log level
*/
unsigned int GetLogLevel() {
	return log_level;
}

//=========================================================================
/**
	Log the string
*/
void Log(char* format, ...) {
	va_list args;
	va_start(args, format);
	Log(LOG_GENERAL, format, args);
	va_end(args);
}

//=========================================================================
/**
	Log the string
*/
void Log(unsigned int log_level_arg, char* format, ...) {
	va_list args;
	va_start(args, format);
	Log(log_level_arg, format, args);
	va_end(args);
}

//=========================================================================
/**
	Log the string
*/
void Log(unsigned int log_level_arg, char* format, va_list ap) {

	if (log_level_arg & log_level) {

		char dateStr[9], timeStr[9];
		errno_t err;

		//Check if log path is set
		if (log_path.empty())
			return;

		_strdate_s(dateStr, sizeof(dateStr));
		_strtime_s(timeStr, sizeof(timeStr));

		// write error or other information into log file
		FILE* pFile = 0;
		//va_list ap;
		if ((err = fopen_s(&pFile, log_path.c_str(), "a")) != 0) {
			return;
		}

		if (pFile != 0) {
			//va_start(ap, format);
			fprintf(pFile, "[%s]", timeStr);
			fprintf(pFile, "[%s] ", dateStr);
			vfprintf(pFile, format, ap);
			//va_end(ap);
			fclose(pFile);
		}
	}
	
}
#endif