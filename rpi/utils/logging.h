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


/**
 * Initialize logging interface.
 *
 * Sets GPIO 14 and 15 to TXD0 and RXD0
 */
void LOG_init();

/**
 * Print str to console
 */
void LOG_print(char* str);


#endif /* ifndef LOGGING_H */
