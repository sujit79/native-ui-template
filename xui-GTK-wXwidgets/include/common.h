#ifndef common_h
#define common_h

#ifdef __cplusplus
#define NULL 0
#include <iostream>
#include <memory>
#include <new>
#include <vector>
#else
#define NULL ((void *) 0)
#endif

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifndef GTK_LIBRARY
#define GTK_LIBRARY
#include<gtk/gtk.h>
#endif

#ifndef GTK_MM
#define GTK_MM
#include "glibmm.h"
#include "glibmm/ustring.h"
#endif


#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

#ifndef LIBXML
#define LIBXML
#include <libxml++/libxml++.h>
#endif

#ifndef STRING_H
#define STRING_H
#include<string.h>
#endif

#endif
