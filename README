StripCmt    by Ben Canning <bdc@bdc.cx>
http://www.bdc.cx/software/stripcmt/

--

  StripCmt is a utility for removing comments from C, C++, and Java source
  code.  It was programmed in ANSI-compliant C and has been tested on
  Linux.  StripCmt is free for use and modification under the GNU General
  Public License (http://www.fsf.org/copyleft/gpl.html).

  A note: since 0.1.X is a complete rewrite of the parser, there might well
  still be some cases that it can't handle.  That's why this is still a
  pre-release.  I try to test as many esoteric (and common) cases as
  possible, but I obviously can't get them all.  If you find one, please
  email me immediately.

  0.1.2 is another bugfix release.  See CHANGES for info.
  
  0.1.1 is a bugfix (thanks to Kristoffer Nyberg) so StripCmt no longer leaves
  asterisks inside comments.  It's a good thing I declared 0.1.0 a
  pre-release, huh?

  0.1.0 is a complete rewrite of the parser that will make my life a lot
  easier.  It also fixes a few major bugs in the old parse code.  A man
  page has also been added.
  
  Read the file 'CHANGES' for more information.

  This file is the only documentation for StripCmt.  Sorry.

--

  Installing StripCmt is easy.  Assuming you're under a normal Unix
  variant, here's the basic steps:

      % gzip -d stripcmt-X.Y.Z.tar.gz
      % tar xf stripcmt-X.Y.Z.tar
      % cd stripcmt-X.Y.Z
      % make

  Optionally, you can become root and do a "make install".  StripCmt will
  install itself into /usr/local/bin in that case.
      
  (The 'X', 'Y', and 'Z' are meta-characters for the current version since I'm
  too lazy to update this file).

--

  StripCmt is designed as a utility.  Thus, it will work in multiple ways.
  Note that as of version 0.0.5, StripCmt's commandline handling is
  somewhat incompatible with older versions.

  If there are no commandline arguments, StripCmt will read from stdin and
  output to stdout.  This makes it act as a FIFO (First In, First Out)
  filter.

  If there are parameters passed, StripCmt will treat them as filenames
  (unless they are one of the ones listed below) and process each of them
  (by which I mean it will remove the comments).  Normal operation is to
  put one filename on the commandline and use redirection to write it to a
  file.  If there are multiple filenames, StripCmt will go through each of
  them and show the results to stdout, which will result in the files being
  concatenated together.

  The only special commandline parameters that StripCmt understands are:

    -h --help       Show a commandline help screen and exit
       --version    Show current version and exit

--

  Java comments are the exact same as C and C++ comments except they have
  added a "/** ... */" block.  Luckily, our C comment parsing code will
  catch that, so I am able to say this removes Java comments without
  actually having to code anything more.

--

  As you can see from the version number, StripCmt still hasn't had a full
  release.  This is a fully functional program with no bugs that I'm aware
  of, but it's not complete.  I don't have any specific plans to add
  features, so this might well be the final release (although I have a
  tendency to say that and then add useless features).

--

  As noted, this program is available at no cost.  I'd really like it if you
  told me what you thought of it, though.

      bdc@bdc.cx
      http://www.bdc.cx/

--
EOF
