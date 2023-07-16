#include "terminal.h"

int main(int argc, char* argv[]) {
    int descriptor;
    int linecount;
    int result;

    linecount = 0;
    descriptor = 0;

    if (argc > 1) {
        descriptor = open(argv[1], O_RDONLY);
        if (descriptor < 0) {
            perror(argv[1]);
            return 1;
        }
    }

    result = looper(descriptor, argc, argv, linecount);

    return result;
}
