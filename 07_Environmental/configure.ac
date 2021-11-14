#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [0.0.1], [aleksa300798@gmail.com])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash], [rhash_library_init], [], [AC_MSG_ERROR([Rhash is needed])])
AC_CHECK_LIB([optional], [readline])

AC_ARG_WITH([readline], 
	[AS_HELP_STRING([--without-readline], 
	[disable support for readline])], 
	[], 
	[with_readline=yes]
)
          
LIBREADLINE=AS_IF([test "x$with_readline" != xno], 
	[AC_CHECK_LIB([readline], [readline]) AC_CHECK_HEADERS([readline/readline.h readline/history.h])]
)

# Checks for header files.
AC_CHECK_HEADER([rhash.h], [], [], [AC_MSG_ERROR([rhash.h is missing])])
AC_CHECK_HEADER([string.h stdio.h ctype.h errno.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strerror])


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
