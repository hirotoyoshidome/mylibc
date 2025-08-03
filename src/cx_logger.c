#include "cx_logger.h"
#include <stdio.h>
#include <time.h>

// Loggerの作成
void cx_init_logger(Logger *logger, char *_log_paht, LogLevel _level) {
    logger->log_path = _log_paht;
    logger->level = _level;
}

int _write_log(Logger *logger, char *msg, LogLevel _level) {
    FILE *f = fopen(logger->log_path, "a");
    if (f == NULL) {
        return 0;
    }

    // 出力判定
    if (logger->level > _level) {
        return 0;
    }

    // ログレベルの文字列取得
    char *level_str;
    switch (_level) {
    case DEBUG:
        level_str = "DEBUG";
        break;
    case INFO:
        level_str = "INFO";
        break;
    case WARN:
        level_str = "WARN";
        break;
    case ERROR:
        level_str = "ERROR";
        break;
    case FETAL:
        level_str = "FETAL";
        break;
    }

    // 現在の時間(JST)
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    // 出力
    fprintf(f, "[%s] [%s] %s\n", level_str, time_str, msg);

    fclose(f);

    return 1;
}

void cx_fetal(Logger *logger, char *msg) {
    int res = _write_log(logger, msg, FETAL);
    if (res != 1) {
        return;
    }
}

void cx_error(Logger *logger, char *msg) {
    int res = _write_log(logger, msg, ERROR);
    if (res != 1) {
        return;
    }
}

void cx_warn(Logger *logger, char *msg) {
    int res = _write_log(logger, msg, WARN);
    if (res != 1) {
        return;
    }
}

void cx_info(Logger *logger, char *msg) {
    int res = _write_log(logger, msg, INFO);
    if (res != 1) {
        return;
    }
}

void cx_debug(Logger *logger, char *msg) {
    int res = _write_log(logger, msg, DEBUG);
    if (res != 1) {
        return;
    }
}
