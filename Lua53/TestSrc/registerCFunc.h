#include "lstate.h"

#ifndef __REGISTER_C_FUNC__
#define __REGISTER_C_FUNC__

static int l_sin(lua_State *L);
void testRegisterCFunc(lua_State *L);
int luaopen_mylib(lua_State *L);

#endif
