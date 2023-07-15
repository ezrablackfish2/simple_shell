#include "terminal.h"

void fork_cmd(info_t *info) {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1) {
        print_error(info, "Fork failed");
        free_info(info, 1);
    }
    if (child_pid == 0) {
        if (execve(info->path, info->argv, get_environ()) == -1) {
            switch (errno) {
                case ENOENT:
                    print_error(info, "Command not found");
                    break;
                case EACCES:
                    print_error(info, "Permission denied");
                    break;
                case EIO:
                    print_error(info, "I/O error");
                    break;
                case ENOMEM:
                    print_error(info, "Out of memory");
                    break;
                default:
                    print_error(info, "Unknown error occurred");
                    break;
            }
            free_info(info, 1);
        }
    } else {
        wait(&(info->status));
        if (info->pipefd[1] > 2) {
            close(info->pipefd[1]);
            info->pipefd[1] = 0;
        }

        info->left_redirect_from_fd = -1;
        if (WIFEXITED(info->status)) {
            info->status = WEXITSTATUS(info->status);
        }
    }
}
