#include "terminal.h"

int main(int argc, char* argv[]) {
    int descriptor = 0;
    int linecount = 0;

    if (argc > 1) {
        descriptor = open(argv[1], O_RDONLY);
        if (descriptor < 0) {
            perror(argv[1]);
            return 1;
        }
    }

    int result = looper(descriptor, argc, argv, linecount);

    return result;
}
