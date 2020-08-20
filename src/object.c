#include <object.h>

void SetScript(Object *object, const char* script) 
{
  strcpy(object->script, script);
}

void SetTransform(Object *object, Transform transform) 
{
  object->transform = transform;
}

Transform GetTransform(Object *object)
{
  return object->transform;
}

void SetPosition(Object *object, Vec3 position) 
{
  object->transform.position = position;
}
void SetRotation(Object *object, Vec3 rotation) 
{
  object->transform.rotation = rotation;
}
void SetScale(Object *object, Vec3 scale) 
{
  object->transform.scale = scale;
}

Vec3 GetPosition(Object *object) 
{
  return object->transform.position;
}
Vec3 GetRotation(Object *object) 
{
  return object->transform.rotation;
}
Vec3 GetScale(Object *object) 
{
  return object->transform.scale;
}

void Translate(Object *object, Vec3 translation) 
{
  object->transform.position.x += translation.x;
  object->transform.position.y += translation.y;
  object->transform.position.z += translation.z;
}

void Rotate(Object *object, Vec3 rotation) 
{
  object->transform.rotation.x += rotation.x;
  object->transform.rotation.y += rotation.y;
  object->transform.rotation.z += rotation.z;
}

void Scale(Object *object, Vec3 scale) 
{
  object->transform.scale.x += scale.x;
  object->transform.scale.y += scale.y;
  object->transform.scale.z += scale.z;
}
