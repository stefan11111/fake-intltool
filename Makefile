.POSIX:

all:
	${CC} ${CFLAGS} intltool-prepare.c -o intltool-prepare
	${CC} ${CFLAGS} intltool-update.c -o intltool-update
	${CC} ${CFLAGS} intltool-merge.c -o intltool-merge
	${CC} ${CFLAGS} intltool-extract.c -o intltool-extract
	${CC} ${CFLAGS} intltoolize.c -o intltoolize

minimal:
	${CC} ${CFLAGS} intltool-prepare.c -o intltool-prepare
	${CC} ${CFLAGS} intltool-update.c -o intltool-update
	${CC} ${CFLAGS} -DMINIMAL intltool-merge.c -o intltool-merge
	${CC} ${CFLAGS} intltool-extract.c -o intltool-extract
	${CC} ${CFLAGS} intltoolize.c -o intltoolize

install:
	mkdir -p ${DESTDIR}/usr/bin
	cp -f intltool-prepare ${DESTDIR}/usr/bin/intltool-prepare
	cp -f intltool-update ${DESTDIR}/usr/bin/intltool-update
	cp -f intltool-merge ${DESTDIR}/usr/bin/intltool-merge
	cp -f intltool-extract ${DESTDIR}/usr/bin/intltool-extract
	cp -f intltoolize ${DESTDIR}/usr/bin/intltoolize
	mkdir -p ${DESTDIR}/usr/share/aclocal
	cp -f intltool.m4 ${DESTDIR}/usr/share/aclocal/intltool.m4

uninstall:
	rm -f ${DESTDIR}/usr/bin/intltool-prepare
	rm -f ${DESTDIR}/usr/bin/intltool-update
	rm -f ${DESTDIR}/usr/bin/intltool-merge
	rm -f ${DESTDIR}/usr/bin/intltool-extract
	rm -f ${DESTDIR}/usr/bin/intltoolize
	rm -f ${DESTDIR}/usr/share/aclocal/intltool.m4

clean:
	rm -f intltool-prepare intltool-update intltool-merge intltool-extract intltoolize

.PHONY: all clean install uninstall
