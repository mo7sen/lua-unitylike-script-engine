#ifndef OBJECT_LUA_HEADER
#define OBJECT_LUA_HEADER

#include <object.h>
#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>

#define BASE_SCRIPT "./scripts/base/basescript.lua"

static int SetTransform_L(lua_State *L);
static int GetTransform_L(lua_State *L);

static int SetPosition_L(lua_State *L);
static int SetRotation_L(lua_State *L);
static int SetScale_L(lua_State *L);

static int GetPosition_L(lua_State *L);
static int GetRotation_L(lua_State *L);
static int GetScale_L(lua_State *L);

static int Translate_L(lua_State *L);
static int Rotate_L(lua_State *L);
static int Scale_L(lua_State *L);

void objectFunction_L(Object *obj, lua_State *L, const char* fn);

void Register_Vec3_Lua(lua_State *L);
void Register_Transform_Lua(lua_State *L);
void Register_Object_Lua(lua_State *L);

int vec3_index(lua_State *L);
int vec3_newindex(lua_State *L);

#endif
