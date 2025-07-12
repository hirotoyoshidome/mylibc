#ifndef CUSTOM_EXTENDED_LOGGER_H
#define CUSTOM_EXTENDED_LOGGER_H

typedef enum LogLevel {
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FETAL = 5
}LogLevel;

typedef struct Logger {
    char* log_path;
    LogLevel level;
}Logger;



void cx_init_logger(Logger* logger, char* _log_paht, LogLevel _level);
void cx_fetal(Logger* logger, char* msg);
void cx_error(Logger* logger, char* msg);
void cx_warn(Logger* logger, char* msg);
void cx_info(Logger* logger, char* msg);
void cx_debug(Logger* logger, char* msg);

#endif // CUSTOM_EXTENDED_LOGGER_H
