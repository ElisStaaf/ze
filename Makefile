SHELL=sh
SOURCE=ze.c
BINARY=/usr/bin/ze

install:
	$(CC) -o ${BINARY} ${SOURCE}
