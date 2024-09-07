#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define PATH_MAX 4096
#define MASK 00755

int main(int argc, char **argv)
{
    if (argc < 2) {
        return 0;
    }

    if (argc == 2 && (!memcmp(argv[1], "-v", sizeof("-v") - 1) || !memcmp(argv[1], "--version", sizeof("--version") - 1))) {
        printf("%s (intltool) 0.51.0\n", argv[0]);
        return 0;
    }

    char path[PATH_MAX + sizeof("tmp/") + sizeof(".h") + 1];
    char offset = 0;

    int len = strlen(argv[argc - 1]);

    if (len > PATH_MAX) {
        len = PATH_MAX;
    }

    for (char **p = argv; *p; p++) {
        if (!memcmp(*p, "-l", sizeof("-l") - 1) || !memcmp(*p, "--local", sizeof("--local") - 1)) {
            offset = sizeof("tmp/") - 1;
            memcpy(path, "tmp/", sizeof("tmp/") - 1);
            mkdir("tmp/", MASK);
            break;
        }
    }

    memcpy(path + offset, argv[argc - 1], len); /* don't copy the '\0' here */
    memcpy(path + offset + len, ".h", sizeof(".h")); /* this copies the '\0' */
    fopen(path, "w");
    return 0;
}
