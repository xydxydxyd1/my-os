/******************************************************************************
* File:             logging.h
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Prefix:           LOG
*                   Logging functions for debugging
*****************************************************************************/

#ifndef LOGGING_H
#define LOGGING_H


#include "utils/err.h"          // Error handled returns


/**
 * Print str to console
 */
RET_Void LOG_print(char* str);


#endif /* ifndef LOGGING_H */
