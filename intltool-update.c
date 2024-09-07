#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && !memcmp(argv[1], "--version", sizeof("--version") - 1)) {
        printf("%s (intltool) 0.51.0\n", argv[0]);
        return 0;
    }

    for(char **p = argv; *p; p++) {
        if (!memcmp(*p, "-o", sizeof("-o") - 1)) {
            p++;
            fopen(*p, "w");
            return 0;
        }

        if (!memcmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            fopen(*p + sizeof("--output-file=") - 1, "w");
            return 0;
        }
    }
    fopen(argv[argc - 1], "w");
    return 0;
}
