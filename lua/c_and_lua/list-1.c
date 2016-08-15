#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main()
{
	lua_State *L;
	double a, b, c, s;
	L = lua_open();
	luaL_openlibs(L);

	if(luaL_dofile(L, "script-1.lua"))
	{
		printf("load error\n");
		return -1;
	}

	printf("enter a,b,c => ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	lua_getglobal(L, "Heron");
	
	lua_pushnumber(L, a);
	lua_pushnumber(L, b);
	lua_pushnumber(L, c);

	if(lua_pcall(L, 3, 1, 0)) {
		printf("%s\n", lua_tostring(L, -1));
		lua_pop(L, 1);
	}

	s = lua_tonumber(L, 1);
	
	if(s >= 0)
	{
		printf("area=%f\n", s);
	} else {
		printf("input data error\n");
	}
	lua_close(L);
}
