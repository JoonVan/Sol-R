#pragma once

#ifdef LOGGING
#include <ETWLoggingModule.h>
#include <ETWResources.h>
#else
#include <sstream>
#include <windows.h>

static int gLogLevel = 3;

#define SET_LOG_LEVEL( __level) \
   { \
      gLogLevel = __level; \
   }  

#define LOG_INFO( __level, __msg ) \
   { \
      if( __level <= gLogLevel ) \
      { \
         std::stringstream __s; \
         __s << "[INFO]  " << __msg; \
         std::cout << __s.str() << std::endl; \
         OutputDebugString(__s.str().c_str()); \
      } \
   }

#define LOG_ERROR( __msg ) \
   { \
      std::stringstream __s; \
      __s << "[ERROR] " << __msg; \
      std::cerr << __s.str() << std::endl; \
      OutputDebugString(__s.str().c_str()); \
   }
#endif
