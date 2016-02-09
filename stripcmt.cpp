/*
  stripcmt - Strips C, C++, and Java comments from a file
  Based on https://github.com/jiayuehua/stripcmt

  --
  From https://github.com/jiayuehua/stripcmt :
    All code by Ben Canning <bdc@bdc.cx>
    http://www.bdc.cx/stripcmt/
    (C)1998, 1999 under that wacky GPL thingy.
    I'm not a responsible person, so please don't sue me.
*/

#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <string.h>


/* Vanity strings */
const char NAME[] = "StripCmt";
const char VER[] = "0.1.2";
const char DATE[] = "Aug 16 2000";
const char AUTHOR[] = "Ben Canning";
const char EMAIL[] = "bdc@bdc.cx";
const char PAGE[] = "http://www.bdc.cx/software/stripcmt/";
const char DESC[] = "Remove comments from C, C++, and Java source code";
const char USAGE[] = "[infile] > [outfile]";

/*
  show_commandline_help()
  --
  As the name says, this shows everything necessary for the "-h --help" commandline option.
  Nothing more, nothing less.  Oh yeah, it exits after being called.
*/

void show_commandline_help(const char *arg0) {
    std::cout << std::endl;
    std::cout << NAME << " " << VER << " (" << DATE << ")    by " << AUTHOR << " " << "<" << EMAIL << ">" << std::endl;
    std::cout << "  " << DESC << std::endl;
    std::cout << "  " << PAGE << std::endl << std::endl;
    std::cout << "usage: " << arg0 << " " << USAGE << std::endl << std::endl;
    std::cout
    << "  -h --help       Show this commandline help screen and exit" << std::endl
    << "     --version    Display version information and exit" << std::endl
    << "  infile(s)       Files to remove comments from (wildcards okay)" << std::endl
    << "  outfile         File to write to (defaults to stdout)" << std::endl;
}

/*
  Show_Version()
  --
  Even less interesting than Show_Commandline_Help(), this will merely print
  the program name followed by the version and exit.
*/

void show_version() {
    std::cout << NAME << " " << VER << std::endl;
}


void stripcmt(FILE *infile, FILE *outfile) {
    char buffer[BUFSIZ];
    char quote = 0, comment = 0;

    while (fgets(buffer, sizeof(buffer), infile)) {
        for (int i = 0; buffer[i]; i++) {
            switch (buffer[i]) {
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
                    else if (buffer[i + 1] == '/') {
                        fputc('\n', outfile);
                        memset(buffer, 0, sizeof buffer);
                    }
                    else if (buffer[i + 1] == '*') {
                        comment = 1;
                        i++;
                    }
                    else if (!comment)
                        fputc(buffer[i], outfile);
                    break;

                    /* This handles closing C style comments */
                case '*':
                    if (quote) {
                        fputc(buffer[i], outfile);
                        break;
                    }
                    else if (comment && buffer[i + 1] == '/') {
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
            }
        }
    }
    return;
}


int main(int argc, char **argv) {

    /* If there's no commandline arguments, just act as a FIFO filter */
    if (1 == argc) {
        stripcmt(stdin, stdout);
        return 0;
    }

    std::vector<std::string> _argv;
    for (int i = 1; i < argc; ++i)
        _argv.push_back(argv[i]);

    /* Otherwise, strip comments from each file and send 'em to stdout */
    for (const std::string &arg : _argv) {
        if (arg == "-h" || arg == "--help") {
            show_commandline_help(argv[0]);
            exit(0);
        }
        else if (arg == "--version") {
            show_version();
            exit(0);
        }
        else {
            FILE *infile = fopen(arg.c_str(), "rt");

            if (!infile) {
                perror(arg.c_str());
                return 1;
            }

            stripcmt(infile, stdout);
            fclose(infile);
        }
    }

    return 0;
}

