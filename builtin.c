#include "terminal.h"

int find_builtin(info_t *info) {
    int i, built_in_ret = -1;
    builtin_table builtintbl[] = {
    {"exit", ourexit},
    {"env", ourenv},
    {"cd", ourcd},
    {"setenv", oursetenv},
    {"unsetenv", ourunsetenv},
    {"alias", ouralias},
    {NULL, NULL}
};

    for (i = 0; builtintbl[i].type; i++) {
        if (_strcmp(info->argv[0], builtintbl[i].type) == 0) {
            built_in_ret = builtintbl[i].func(info);
            break;
        }
    }

    return built_in_ret;
}
