/**
 * @file DebugLogger.h
 * @brief Header file for Debug Logger Module
 *
 * This module provides logging utilities for different debug levels.
 * Messages are printed to the serial console only if their level is
 * equal to or higher than the current system log level.
 */

#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include <asf.h>
#include <stdarg.h>

/**
 * @enum eDebugLogLevels
 * @brief Different levels of logging severity.
 */
enum eDebugLogLevels {
    LOG_INFO_LVL    = 0, /**< Informational message */
    LOG_DEBUG_LVL   = 1, /**< Debug-level message */
    LOG_WARNING_LVL = 2, /**< Warning-level message */
    LOG_ERROR_LVL   = 3, /**< Error-level message */
    LOG_FATAL_LVL   = 4, /**< Fatal error message */
    LOG_OFF_LVL     = 5, /**< Disable all logging */
    N_DEBUG_LEVELS  = 6  /**< Total number of levels */
};

/**
 * @brief Sets the system-wide debug log level.
 * @param debugLevel The new log level to be set.
 */
void setLogLevel(enum eDebugLogLevels debugLevel);

/**
 * @brief Gets the current debug log level.
 * @return The current log level.
 */
enum eDebugLogLevels getLogLevel(void);

/**
 * @brief Logs a formatted message to the serial console based on the debug level.
 * @param level The severity level of the log message.
 * @param format The format string, similar to printf.
 * @param ... Additional arguments for formatting.
 */
void LogMessage(enum eDebugLogLevels level, const char *format, ...);

#endif // DEBUG_LOGGER_H
