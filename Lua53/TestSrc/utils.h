#include "lstate.h"

#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

void stackDump(lua_State *L);

void error(lua_State* L, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
