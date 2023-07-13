#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 10000

typedef struct {
    int descriptor;
    int linecount_flag;
    char* allinput;
    char** argv;
} property;


typedef struct {
    int descriptor;
    char readingplace[MAX_LINE_LENGTH];
    int index;
    int length;
} sline;

typedef struct {
    char* path;
    char *arg;
    int argc;
    int linecount;
    char** argv;
    int pipefd[2];
    int status;
    int left_redirect_from_fd;
    char *shell;
} info_t;

typedef struct {
    char* type;
    int (*func)(info_t*);
} builtin_table;


ssize_t linereader(char** lineptr, size_t* n, int descriptor);
ssize_t read_line(int descriptor, char* buffer, ssize_t max_length);
ssize_t read_file_contents(int descriptor, char** buffer);
off_t lseeker(int descriptor, off_t offset, int whence);
int flusher(FILE* stream);
int _strlen(char *str);
int _strcmp(char* str1, char* str2);
char *get_char(char *str, char *character);
char* _strcat(char* dest, char* src);
char* _strcpy(char* destination, char* source);
char* _strdup(char* str);
void _puts(char *str);
int _putchar(char c);
char *_strchrlast(char *s, char c);
void print_prompt(int );
void fork_cmd(info_t *info);
void free_info(info_t *info, int exit_status);
void print_error(info_t *info, const char* message);
char** get_environ();
int find_builtin(info_t *info);
int ourexit(info_t *info);
int ourenv(info_t *info);
int oursetenv(info_t *info);
int ourunsetenv(info_t *info);
int ouralias(info_t *info);
int divider(info_t *inform);
char **strtow(char *str, char *d);
int is_delim(char c, char *delim);
void find_path(info_t *info);
char *pathfinder(info_t *info, char *pathstr, char *cmd);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
void tabcompleter(char* line);
char* get_word(char* line, int index);
int interactive(property *file);
int looper(int descriptor, int argc, char **argv, int );
char *convert_number(long int num, int base, int flags);
void _print(char *str);

#endif
