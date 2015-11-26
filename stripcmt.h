/*
  stripcmt.h
  --
  As you can probably guess, this contains compile-time stuff.  No actual
  code is in here.
*/


/* System includes */
  #include <stdio.h>
  #include <string.h>


/* Vanity strings */
  const char NAME  [] = "StripCmt";
  const char VER   [] = "0.1.2";
  const char DATE  [] = "Aug 16 2000";
  const char AUTHOR[] = "Ben Canning";
  const char EMAIL [] = "bdc@bdc.cx";
  const char PAGE  [] = "http://www.bdc.cx/software/stripcmt/";
  const char DESC  [] = "Remove comments from C, C++, and Java source code";
  const char USAGE [] = "[infile] > [outfile]";


/* Function defines.  These should probably be left alone. */
  #define PUTCHAR    putc       /* use fputc if you're a dweeb */
  #define STREQ      !strcmp


/* Our little files we need to include */
  #include "misc.c"     /* Commandline help and version information */
  #include "strip.c"    /* The code to actually strip comments */


/*EOF*/
