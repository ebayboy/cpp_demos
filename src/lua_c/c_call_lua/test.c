//test.lua
/*
width = 10
height = 20
*/

//test.c
#include <stdio.h>


#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main()
{

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if(luaL_loadfile(L, "test.lua") || lua_pcall(L, 0,0,0))
    {
        printf("error %s\n", lua_tostring(L,-1));
        return -1;
    }

    //push stack
    lua_getglobal(L,"width"); //2
    lua_getglobal(L,"length"); //1

    //pop stack
    printf("width = %d\n", lua_tointeger(L,-2)); //-2
    printf("length = %d\n", lua_tointeger(L,-1)); //-1

    lua_close(L);

    return 0;
}

