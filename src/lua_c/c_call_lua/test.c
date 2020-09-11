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


static int test_call_lua_func()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if(luaL_loadfile(L, "test.lua") || lua_pcall(L, 0,0,0))
    {
        printf("error %s\n", lua_tostring(L,-1));
        return -1;
    }


	//call test.lua add function
    lua_getglobal(L,"add");
    lua_pushnumber(L, 10); //1
    lua_pushnumber(L, 20); //2

    if(lua_pcall(L, 2, 1, 0) != 0)
    {
        printf("error %s\n", lua_tostring(L,-1));
        return -1;
    }

    double z = lua_tonumber(L, -1);
    printf("%s: call lua add z = %f \n", __func__, z);
    
	lua_close(L);

	return 0;
}

static int test_call_lua_var()
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
    printf("%s: width = %d\n", __func__, lua_tointeger(L,-2)); //-2
    printf("%s: length = %d\n", __func__, lua_tointeger(L,-1)); //-1

    lua_close(L);

	return 0;
}

int main()
{
	test_call_lua_var();

	test_call_lua_func();

	return 0;
}

