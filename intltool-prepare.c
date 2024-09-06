#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 2 && (!memcmp(argv[1], "-v", sizeof("-v") - 1) || !memcmp(argv[1], "--version", sizeof("--version") - 1))) {
        printf("%s (intltool) 0.51.0\n", argv[0]);
    }
    return 0;
}
