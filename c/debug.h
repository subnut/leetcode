#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#if DEBUG
#define dprintf printf
#define DPRINTF printf
#else
#define dprintf(...) {;}
#endif

#endif /* DEBUG_H */

