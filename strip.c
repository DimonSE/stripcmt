/*
 * stripcmt()
 *
 * This is the core of the program.  It reads from file 'infile' and outputs
 * the code (minus comments) to 'outfile'.  It does this inefficiently since
 * it outputs byte by byte instead of in blocks, but I'm too lazy to fix that
 * right now.  Maybe later.
 */

void
stripcmt (FILE *infile, FILE *outfile)
{
  char buffer [BUFSIZ];
  char quote = 0, comment = 0;
  int  i;


  while (fgets(buffer, sizeof buffer, infile))
  {
      for (i = 0; buffer[i]; i++)
      {
          switch (buffer[i])
          {
              /* Take care of control characters starting with '\' */
              case '\\':
                  if (comment)    /* If we're in a comment, don't bother */
                      break;
                  fputc(buffer[i], outfile);
                  fputc(buffer[++i], outfile);
                  break;

              /* Handle either type of quotes (' or "). */
              case '\"':
              case '\'':
                  if (comment)
                      break;
                  fputc(buffer[i], outfile);
                  if (!quote)
                      quote = buffer[i];
                  else if (quote == buffer[i])
                      quote = 0;
                  break;

              /* This handles both C++ comments and opening C comments */
              case '/':
                  if (quote)
                       fputc(buffer[i], outfile);
                  else if (buffer[i+1] == '/')
                  {
                      fputc('\n', outfile);
                      memset(buffer, 0, sizeof buffer);
                  }
                  else if (buffer[i+1] == '*')
                  {
                      comment = 1;
                      i++;
                  }
                  else if (!comment)
                      fputc(buffer[i], outfile);
                  break;

              /* This handles closing C style comments */
              case '*':
                  if (quote)
		  {
                       fputc(buffer[i], outfile);
		       break;
		  }
                  else if (comment && buffer[i+1] == '/')
                  {
                      comment = 0;
                      i++;
                      break;
                  }
                  else if (comment)
                      break;
                  fputc(buffer[i], outfile);
                  break;

              /* Anything else?  Show it if necessary. */
              default:
                  if (!comment)
                      fputc(buffer[i], outfile);
                  break;
          }  /* End of switch */
      }  /* End of for() */
  }  /* End of while() */
  return;
}
