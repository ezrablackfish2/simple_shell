#include "terminal.h"

void print_prompt(int linecount) {
    char cwd[1024];
    char hostname[1024];
    char username[1024];
    time_t rawtime;
    struct tm *info;
    char time_buffer[80];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }

    if (getlogin_r(username, sizeof(username)) != 0) {
        perror("getlogin_r");
        exit(EXIT_FAILURE);
    }

    time(&rawtime);
    info = localtime(&rawtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y/%m/%d", info);

    _print("ezra shell and aman");

    if (strcmp(cwd, "/") == 0) {
        _print("$ ");
    } else {
        _print(":~");
        _print(cwd);
        _print("$ ");
    }
}
