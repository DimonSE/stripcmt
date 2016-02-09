# Makefile for StripCmt
# --
# Excuse me for this ugly thing.

CC = g++
# CFLAGS = -s -O3 -Wall -ansi -pedantic -ffast-math -fexpensive-optimizations
CFLAGS =  -std=c++11 -s -Wall -pedantic
INSTALL = `which install`

stripcmt: stripcmt.cpp
	$(CC) $(CFLAGS) \
	  stripcmt.cpp  -o stripcmt

install: stripcmt stripcmt.1
	$(INSTALL) ./stripcmt /usr/local/bin/stripcmt
	$(INSTALL) ./stripcmt.1 /usr/local/man/man1/stripcmt.1

clean:
	rm stripcmt
