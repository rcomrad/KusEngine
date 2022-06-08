#ifndef DOMAIN_FLAGS_HPP
#define DOMAIN_FLAGS_HPP

//------------------------------------------------------------
//						PROJECT SETTINGS
//------------------------------------------------------------

/*
LOGS_DEFAULT_OUTPUT     = 0
LOGS_TO_COUT_OUTPUT     = 1
LOGS_TO_FILE_OUTPUT     = 2

DEFAULT = LOGS_TO_COUT_OUTPUT
*/
//#define LOGS_OUTPUT_TYPE 1

/*
ERRORS_DEFAULT_OUTPUT    = 0
ERRORS_TO_COUT_OUTPUT    = 1
ERRORS_TO_FILE_OUTPUT    = 2
ERRORS_TO_LOG_OUTPU      = 4

DEFAULT = ERRORS_TO_COUT_OUTPUT
*/
//#define ERRORS_OUTPUT_TYPE 4

//------------------------------------------------------------

#if     LOGS_OUTPUT_TYPE == 0
    #define LOGS_DEFAULT_OUTPUT
#elif   LOGS_OUTPUT_TYPE == 1
    #define LOGS_TO_COUT_OUTPUT
#elif   LOGS_OUTPUT_TYPE == 2
    #define LOGS_TO_FILE_OUTPUT
#else
    #define LOG_DEFAULT_OUTPUT
#endif

//------------------------------------------------------------

#if     ERRORS_OUTPUT_TYPE == 0
    #define ERRORS_DEFAULT_OUTPUT
#elif   ERRORS_OUTPUT_TYPE == 1
    #define ERRORS_TO_COUT_OUTPUT
#elif   ERRORS_OUTPUT_TYPE == 2
    #define ERRORS_TO_FILE_OUTPUT
#elif   ERRORS_OUTPUT_TYPE == 4
    #define ERRORS_TO_LOG_OUTPU
#else
    #define ERROR_DEFAULT_OUTPUT
#endif


//------------------------------------------------------------
//							DEBUG FLAGS
//------------------------------------------------------------

#ifdef _DEBUG
#define _DBG_
#endif

//------------------------------------------------------------

//#define BILL_WINDOWS

//------------------------------------------------------------

#endif // !DOMAIN_FLAGS_HPP