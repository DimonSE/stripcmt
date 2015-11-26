/*
  show_commandline_help()
  --
  As the name says, this shows everything necessary for the "-h --help"
  commandline option.  Nothing more, nothing less.  Oh yeah, it exits after
  being called.
*/

void
show_commandline_help (const char *argv0)
{
  printf ("\n%s %s (%s)    by %s <%s>\n", NAME, VER, DATE, AUTHOR, EMAIL);
  printf ("  %s\n", DESC);
  printf ("  %s\n\n", PAGE);
  printf ("usage: %s %s\n\n", argv0, USAGE);
  puts   (
          "  -h --help       Show this commandline help screen and exit\n"
          "     --version    Display version information and exit\n"
          "  infile(s)       Files to remove comments from (wildcards okay)\n"
          "  outfile         File to write to (defaults to stdout)\n"
  );

  exit (0);
}




/*
  Show_Version()
  --
  Even less interesting than Show_Commandline_Help(), this will merely print
  the program name followed by the version and exit.
*/

void
show_version (void)
{
  printf ("%s %s\n", NAME, VER);
  exit (0);
}

/*EOF*/
