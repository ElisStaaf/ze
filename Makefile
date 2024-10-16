SHELL=sh
SOURCE=src/ze.c
BINARY=/usr/bin/ze

install:
	$(CC) -o ${BINARY} ${SOURCE}

uninstall:
	rm ${SOURCE} && rm ${BINARY}
