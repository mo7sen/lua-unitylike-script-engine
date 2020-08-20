#include <object_l.h>

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

void objectFunction_L(Object *obj, lua_State *L, const char* fn) 
{
  luaL_loadfile(L, BASE_SCRIPT);
  lua_call(L, 0, 0);

  luaL_loadfile(L, obj->script);
  lua_call(L, 0, 0);

  lua_getglobal(L, fn);
  lua_call(L, 0, 0);
}

