#include <stdio.h>
#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>
#include <lautoc.h>

#include <object.h>
#include <object_l.h>

// Global Object
Object obj1;

void initObjects()
{
  SetScript(&obj1, "scripts/script_1.lua");
}

int main()
{
  initObjects();

  lua_State *state = luaL_newstate();
  luaA_open(state);

  Register_Vec3_Lua(state);
  Register_Transform_Lua(state);
  Register_Object_Lua(state);

  luaL_openlibs(state);

  objectFunction_L(&obj1, state, "onStart");

  /* for(int i = 0; i < 10; ++i) */
  /*   objectFunction_L(&obj1, state, "onUpdate"); */

  luaA_close(state);
  lua_close(state);

  return 0;
}
