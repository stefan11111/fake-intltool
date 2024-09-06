#ifndef MINIMAL
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && (!memcmp(argv[1], "-v", sizeof("-v") - 1) || !memcmp(argv[1], "--version", sizeof("--version") - 1))) {
        printf("%s (intltool) 0.51.0\n", argv[0]);
        return 0;
    }
#ifndef MINIMAL
    FILE *f = fopen(argv[argc - 2], "r");
    FILE *g = fopen(argv[argc - 1], "w");
    int ifd = fileno(f);
    int ofd = fileno(g);
    char buf[8192];
    for(;;) {
        int nread = read(ifd, buf, sizeof(buf));
        if (nread <= 0) {
            return 0;
        }
        unsigned int i;
        for (i = 0; i < nread; i++) {
            if (buf[i] == '_') {
                nread--;
                int j;
                for (j = i; j < nread; j++) {
                    buf[j] = buf[j + 1];
                }
                i--;
            }
        }
        (void)!write(ofd, buf, nread);
    }
#else
    (void)!fopen(argv[argc - 1], "w");
    return 0;
#endif
}
