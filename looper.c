#include "terminal.h"

int looper(int descriptor, int argc, char **argv, int linecount) {
    char* line = NULL;
    size_t line_length;
    property file;
    file.descriptor = descriptor;
    file.linecount_flag = 0;
    info_t info;
    info.linecount = 0;


    while (1) {
	    info.linecount++;
        if (file.descriptor != 0 && file.linecount_flag == 0) {
            while (linereader(&line, &line_length, file.descriptor) != -1) {
                if (line_length > 0) {
                    free(line);
                } else {
                    break;
                }
            }
            file.linecount_flag = 1;
        } else {
            print_prompt(linecount);
            fflush(stdout);
            if (linereader(&line, &line_length, 0) == -1) {
                break;
            }
            if (line_length > 0) {

                // Prepare info_t structure for fork_cmd
                info.path = line;  // Assuming line contains the path
                info.argv = NULL;  // Assuming argv is not used in this example
                info.pipefd[0] = -1;  // Assuming pipefd is not used in this example
                info.pipefd[1] = -1;  // Assuming pipefd is not used in this example
                info.status = -1;  // Assuming status is not used in this example
                info.left_redirect_from_fd = -1;  // Assuming left_redirect_from_fd is not used in this example
		info.argc = argc;
		info.arg = _strdup(line);
                info.argv = malloc(sizeof(argc));
                info.argv[0] = NULL; // Assuming command name is fixed
                info.argv[1] = NULL;
		info.shell = argv[0];


		divider(&info);

                int built_in_ret = find_builtin(&info);
                if (built_in_ret == -2) {
                    // Builtin signals exit
                    free(line);
                    free(info.argv[0]);
                    free(info.argv);
                    break;
                } else if (built_in_ret == -1) {
			info.path = info.argv[0];
			find_path(&info);
                }

                free(line);
                free(info.argv[0]);
                free(info.argv);
            }
        }
    }

    if (descriptor != 0) {
        close(descriptor);
    }

    return 0;
}
