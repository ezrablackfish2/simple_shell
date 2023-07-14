#include "terminal.h"

void find_path(info_t *info)
{
    char *p = NULL;
    int r = 0, place = 0;

    while (info->arg[r])
    {
        if (!is_delim(info->arg[r], " \t\n"))
        {
            place++;
        }
        r++;
    }
    if (!place)
    {
        return;
    }
    p = pathfinder(info, envget("PATH"), info->argv[0]);
    if (p)
    {
        info->path = p;
        fork_cmd(info);
    }
    else
    {
        if ((envget("PATH") || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
        {
            fork_cmd(info);
        }
        else if (*(info->arg) != '\n')
        {
            print_error(info, "not found\n");
        }
    }
}

char *pathfinder(info_t *info, char *placestr, char *cmd)
{
    int r = 0, posi = 0;
    char *place;

    if (!placestr)
        return NULL;
    if ((_strlen(cmd) > 2) && get_char(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return cmd;
    }
    while (1)
    {
        if (!placestr[r] || placestr[r] == ':')
        {
            place = dup_chars(placestr, posi, r);
            if (!*place)
                _strcat(place, cmd);
            else
            {
                _strcat(place, "/");
                _strcat(place, cmd);
            }
            if (is_cmd(info, place))
                return place;
            if (!placestr[r])
                break;
            posi = r;
        }
        r++;
    }
    return NULL;
}

int is_cmd(info_t *info, char *place)
{
    struct stat st;

    (void)info;
    if (!place || stat(place, &st))
        return 0;

    if (st.st_mode & S_IFREG)
    {
        return 1;
    }
    return 0;
}

char *dup_chars(char *placestr, int start, int stop)
{
    static char place[1024];
    int m = 0, u = 0;

    for (u = 0, m = start; m < stop; m++)
        if (placestr[m] != ':')
            place[u++] = placestr[m];
    place[u] = 0;
    return place;
}
