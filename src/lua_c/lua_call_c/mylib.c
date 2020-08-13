//mylib.c
#include <stdio.h>
#include <math.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int myadd(lua_State *L)
{
    int a = luaL_checknumber(L, 1);
    int b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a+b);
    return 1;
}

static const struct luaL_Reg mylib [] =
{
    {"add", myadd},
    {NULL, NULL}
};

int luaopen_mylib(lua_State *L)
{
    //luaL_newlib(L, mylib); //lua > 5.2
	luaL_register(L, "mylib", mylib);  

    return 1;
}
