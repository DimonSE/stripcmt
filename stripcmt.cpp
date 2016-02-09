/*
  stripcmt - Strips C, C++, and Java comments from a file
  --
  All code by Ben Canning <bdc@bdc.cx>
  http://www.bdc.cx/stripcmt/
  (C)1998, 1999 under that wacky GPL thingy.
  I'm not a responsible person, so please don't sue me.
*/


/* Include our header file that includes everything else */
  #include "stripcmt.h"




int
main (int argc, char **argv)
{
  int   loop1 = 1;
  FILE *infile;


  /* If there's no commandline arguments, just act as a FIFO filter */
  if (1 == argc)
  {
      stripcmt (stdin, stdout);
      return 0;
  }


  /* Otherwise, strip comments from each file and send 'em to stdout */
  for (loop1 = 1; loop1 < argc; loop1++)
  {
      if (STREQ (argv[loop1], "-h") || STREQ (argv[loop1], "--help"))
          show_commandline_help (argv[0]);

      else
      if (STREQ(argv[loop1], "--version"))
          show_version();

      else
      {
          infile = fopen (argv[loop1], "rt");

          if (!infile)
          {
              perror (argv[loop1]);
              return 1;
          }

          stripcmt (infile, stdout);
          fclose (infile);
      }
  }

  return 0;
}

/*EOF*/
