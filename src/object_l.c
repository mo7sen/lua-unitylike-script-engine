#include <object_l.h>
#include <stdlib.h>

static int SetTransform_L(lua_State *L) 
{
  // (Object, Transform)->()
  return 0;
}

static int GetTransform_L(lua_State *L) 
{
  // (Object) -> (Transform)
  return 1;
}

static int SetPosition_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

static int SetRotation_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

static int SetScale_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

static int GetPosition_L(lua_State *L) 
{
  // (Object) -> (Vec3)
  return 1;
}

static int GetRotation_L(lua_State *L) 
{
  // (Object) -> (Vec3)
  return 1;
}

static int GetScale_L(lua_State *L) 
{
  // (Object) -> (Vec3)
  return 1;
}

static int Translate_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

static int Rotate_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

static int Scale_L(lua_State *L) 
{
  // (Object, Vec3) -> ()
  return 0;
}

void PushObjectToRegistry(lua_State *L, Object *obj)
{
  lua_pushlightuserdata(L, (void*)obj);
  lua_gettable(L, LUA_REGISTRYINDEX);
  if(lua_isnil(L, -1))
  {
    lua_pop(L, 1);
    Object ** new_wrapped_ptr = (Object **) lua_newuserdata(L, sizeof(Object*));
    *new_wrapped_ptr = obj;
    printf("new_wrapped_ptr: %llx\n", (unsigned long long) new_wrapped_ptr);
    printf("*new_wrapped_ptr: %llx\n", (unsigned long long) *new_wrapped_ptr);
    lua_pushlightuserdata(L, (void*) obj);
    lua_pushvalue(L, -2);
    lua_settable(L, LUA_REGISTRYINDEX);
  }
}

void objectFunction_L(Object *obj, lua_State *L, const char* fn) 
{

  printf("obj pointer: %llx\n", (unsigned long long) obj);
  luaL_loadfile(L, BASE_SCRIPT);
  lua_rawgetp(L, LUA_REGISTRYINDEX, (void*)obj);
  lua_pcall(L, 1, 0, 0);

  luaL_loadfile(L, obj->script);
  lua_call(L, 0, 0);

  lua_getglobal(L, fn);
  lua_call(L, 0, 0);
}

