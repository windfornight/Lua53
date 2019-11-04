#include "registerCFunc.h"
#include "lstate.h"
#include <math.h>
#include <stdlib.h>
#include "lua.h"

static int l_sin(lua_State *L) {
	double d = lua_tonumber(L, 1); /* get argument */
	lua_pushnumber(L, sin(d)); /* push result */
	return 1; /* number of results */
}

void testRegisterCFunc()
{
	
}