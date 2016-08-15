#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

#define DBGPRT(...) { fprintf(stderr, __VA_ARGS__); }

#endif /* __DEBUG_H__ */
