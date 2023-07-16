#include "terminal.h"

int looper(int descriptor, int argc, char **argv, int linecount) {
    char* line;
    size_t line_length;
    property file;
    info_t info;
    int built_in_ret;


    line = NULL;
    info.linecount = 0;
    file.linecount_flag = 0;
    file.descriptor = descriptor;
    while (1) {
	    info.linecount++;
	    linecount++;
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
            print_prompt();
            fflush(stdout);
            if (linereader(&line, &line_length, 0) == -1) {
                break;
            }
            if (line_length > 0) {

                info.path = line;  
                info.argv = NULL;  
                info.pipefd[0] = -1;  
                info.pipefd[1] = -1;  
                info.status = -1;  
                info.left_redirect_from_fd = -1; 
		info.argc = argc;
		info.arg = _strdup(line);
                info.argv = malloc(sizeof(argc));
                info.argv[0] = NULL; 
                info.argv[1] = NULL;
		info.shell = argv[0];


		divider(&info);

                built_in_ret = find_builtin(&info);
                if (built_in_ret == -2) {
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
