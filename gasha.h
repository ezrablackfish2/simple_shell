#ifndef GASHA_H
#define GASHA_H

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
#include <stdbool.h>


#define MAX_LINE_LENGTH 10000
#define MAX_ALIASES 100

/**
 * struct praperty - this is the file describing ezra aman structure
 * @descriptor: is the file open or not teller
 * @linecount_flag: is the flag to tell us that the line is inputted or not
 * @allinput: the readed thing by the mimicer
 * @argv: the argument values
 */

typedef struct praperty
{
	int descriptor;
	int linecount_flag;
	char *allinput;
	char **argv;
} property;

/**
 * struct segmentedline - for our custom mimicer getline we wanted to make it
 * @descriptor: tells us if a file has been open or not
 * @readingplace: the buffer where an input is taken to
 * @index: is the place of the input that stopped in mimic
 * @length: the length of the line
 */

typedef struct segmentedline
{
	int descriptor;
	char readingplace[MAX_LINE_LENGTH];
	int index;
	int length;
} sline;

/**
 * struct informasion - after a line has been read it is inserted in here so as
 * @path: the first argument value 0
 * @arg: is the total argument read
 * @linecount: the line we counted
 * @argc: the argument counted
 * @argv: the arguments divided into sections
 * @pipefd: is the descriptor teller if there is a pipe
 * @status: condition of an execution or file
 * @left_redirect_from_fd: tells that a redirection whther the left pipe is
 * @shell: the counting shell what to do tell it
 */

typedef struct informasion
{
	char *path;
	char *arg;
	int argc;
	int linecount;
	char **argv;
	int pipefd[2];
	int status;
	int left_redirect_from_fd;
	char *shell;
} info_t;

/**
 * struct table - is the coangaction of type with function
 * @type: the type of command
 * @func: the function to be called after this
 */

typedef struct table
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/**
 * struct entry_alias - wanted to get the entries of aliases
 * @alias: the alias we want the whole array
 * @command: the command the alias next is
 */

typedef struct entry_alias
{
	char alias[256];
	char command[256];
} alias_entry;


ssize_t mesmeranbabi(char **lineptr, size_t *n, int descriptor);
ssize_t mesmeranbib(int descriptor, char *buffer, ssize_t max_length);
ssize_t ikaanbib(int descriptor, char **buffer);
off_t lfelagi(int descriptor, off_t offset, int whence);
int afsash(FILE *stream);
int qalatrizmet(const char *str);
int qalatwididir(char *str1, char *str2);
char *fideagni(char *str, char *character);
char *qalatagenagn(char *dest, const char *src);
char *qalatqegni(char *destination, char *source);
char *qalatabzi(char *str);
char *qalatagnimecheresha(char *s, char c);
void teiyineyatami(void);
void tizazshuka(info_t *info);
void antshi(info_t *info, int exit_status);
void chigiratami(info_t *info, const char *message);
char **inagignakababi(void);
int siraagigni(info_t *info);
int mewicha(info_t *info);
int akababy(info_t *info);
int argakababy(info_t *info);
int akababyatfa(info_t *info);
int akababyatfa(info_t *info);
int kefai(info_t *inform);
char **qorach(char *str, char *d);
int aqimlik(char c, char *delim);
void agignaqtacha(info_t *info);
char *aqtachagni(info_t *info, char *pathstr, char *cmd);
void tabcoherash(char *line);
char *get_word(char *line, int index);
int zuret(int descriptor, int argc, char **argv, char *line,
		size_t line_length, property file, info_t info,
		int built_in_ret);
char *qutirwedeqal(long int num, int base, int flags);
void atim(char *str);
int qalatwididirrizmet(const char *str1, const char *str2, size_t n);
char *akababiagni(const char *variable);
void casqemach(char c, FILE *stream);
int botaqeyary(info_t *info);
int commander(info_t *data, char *path);
char *duplicationsyndrome(char *pathstr, int start, int stop);
int tizaznew(info_t *info, char *path);
char *fidelbizet(char *pathstr, int start, int stop);
extern char **environ;
void nibabanesash(sline *reader, int descriptor);
ssize_t kegelashanbabi(int descriptor, sline *reader);
int gimashanbabi(sline *reader, ssize_t *line_length, char **line);
void siket(char *line, size_t line_length, info_t *info,
		int argc, char **argv, property *file);
int megenagna(property *file);
void fayle(property file, char *line, size_t line_length);
void anesash(info_t *info, int argc, char **argv, char *line);
void netsaawchi(info_t *info, char *line);
char *tiwistaaragi(char *s, char b, unsigned int n);
void milikit(__attribute__((unused))int qutirmilikit);


#endif
