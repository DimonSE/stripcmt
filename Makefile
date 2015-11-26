# Makefile for StripCmt
# --
# Excuse me for this ugly thing.

CC = gcc
# CFLAGS = -s -O3 -Wall -ansi -pedantic -ffast-math -fexpensive-optimizations
CFLAGS = -s -Wall -ansi -pedantic
INSTALL = `which install`

stripcmt: stripcmt.c strip.c misc.c stripcmt.h
	$(CC) $(CFLAGS) \
	  stripcmt.c  -o stripcmt

install: stripcmt stripcmt.1
	$(INSTALL) ./stripcmt /usr/local/bin/stripcmt
	$(INSTALL) ./stripcmt.1 /usr/local/man/man1/stripcmt.1

clean:
	rm stripcmt
