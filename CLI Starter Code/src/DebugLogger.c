/**
 * @file DebugLogger.c
 * @brief Implementation file for the Debug Logger Module
 *
 * This module prints debug messages to the serial console
 * if their severity is equal to or above the current log level.
 */

#include "DebugLogger.h"
#include "SerialConsole.h"  // For SerialConsoleWriteString
#include <stdio.h>
#include <string.h>

#define LOGGER_BUFFER_SIZE 128  ///< Buffer size for formatted log messages

// Current debug level
static enum eDebugLogLevels currentDebugLevel = LOG_INFO_LVL;

void setLogLevel(enum eDebugLogLevels debugLevel)
{
    currentDebugLevel = debugLevel;
}

enum eDebugLogLevels getLogLevel(void)
{
    return currentDebugLevel;
}

void LogMessage(enum eDebugLogLevels level, const char *format, ...)
{
    if (level < currentDebugLevel || level >= N_DEBUG_LEVELS)
    {
        return;
    }

    char buffer[LOGGER_BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, LOGGER_BUFFER_SIZE, format, args);
    va_end(args);

    SerialConsoleWriteString(buffer);
}
