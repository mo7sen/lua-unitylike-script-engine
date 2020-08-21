#include <object_l.h>
#include <lautoc.h>

Vec3 v = {1.0, 2.0, 3.0};
Transform tr = {
  .position = {
    1.0, 2.0, 3.0
  },
  .rotation = {
    4.0, 5.0, 6.0
  },
  .scale = {
    7.0, 8.0, 9.0
  }
};

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

  /* luaA_push(L, Object, obj); */

//  luaA_push(L, Vec3, &v);

  void **tr_pp = lua_newuserdata(L, sizeof(&tr));
  *tr_pp = &tr;

  void **vec_pp = lua_newuserdata(L, sizeof(&v));
  *vec_pp = &v;

  lua_call(L, 2, 0);

  printf("C: Vec3(%f, %f, %f)\n", v.x, v.y, v.z);

  luaL_loadfile(L, obj->script);
  lua_call(L, 0, 0);

  lua_getglobal(L, fn);
  lua_call(L, 0, 0);
}

void Register_Vec3_Lua(lua_State *L)
{
  luaA_struct(L, Vec3);
  luaA_struct_member(L, Vec3, x, real);
  luaA_struct_member(L, Vec3, y, real);
  luaA_struct_member(L, Vec3, z, real);

  lua_register(L, "vec3_index", vec3_index);
  lua_register(L, "vec3_newindex", vec3_newindex);
}

void Register_Transform_Lua(lua_State *L)
{
  luaA_struct(L, Transform);
  luaA_struct_member(L, Transform, position, Vec3);
  luaA_struct_member(L, Transform, rotation, Vec3);
  luaA_struct_member(L, Transform, scale, Vec3);
}

void Register_Object_Lua(lua_State *L)
{
  luaA_struct(L, Object);
  luaA_struct_member(L, Object, transform, Transform);
}

void* get_instance_ptr(lua_State *L, int table_index)
{
  assert(lua_istable(L, table_index));
  lua_getfield(L, table_index, "ref");
  void** vec_pp = (void**)lua_touserdata(L, -1);
  lua_pop(L, 1);
  return *vec_pp;
}

int vec3_index(lua_State *L)
{
  const char* membername = lua_tostring(L, -1);
  Vec3* self = (Vec3*) get_instance_ptr(L, -2);
  return luaA_struct_push_member_name(L, Vec3, membername, self);
}

int vec3_newindex(lua_State *L)
{
  const char* membername = lua_tostring(L, -2);
  Vec3* self = (Vec3*) get_instance_ptr(L, -3);
  luaA_struct_to_member_name(L, Vec3, membername, self, -1);
  return 0;
}

int transform_index(lua_State *L)
{
  const char* membername = lua_tostring(L, -1);
  Transform* self = (Transform*) get_instance_ptr(L, -2);
  return luaA_struct_push_member_name(L, Transform, membername, self);
}

int transform_newindex(lua_State *L)
{
  const char* membername = lua_tostring(L, -2);
  Transform* self = (Transform*) get_instance_ptr(L, -3);
  luaA_struct_to_member_name(L, Transform, membername, self, -1);
  return 0;
}
