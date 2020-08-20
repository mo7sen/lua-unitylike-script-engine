#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#include <string.h>

#define real float

typedef struct 
{
  real x;
  real y;
  real z;
} Vec3;

typedef struct 
{
  Vec3 position;
  Vec3 rotation;
  Vec3 scale;
} Transform;

typedef struct 
{
  Transform transform;
  char script[256];
} Object;

void SetScript(Object *object, const char* script);

void SetTransform(Object *object, Transform transform);

Transform GetTransform(Object *object);

void SetPosition(Object *object, Vec3 position);
void SetRotation(Object *object, Vec3 rotation);
void SetScale(Object *object, Vec3 scale);

Vec3 GetPosition(Object *object);
Vec3 GetRotation(Object *object);
Vec3 GetScale(Object *object);

void Translate(Object *object, Vec3 translation);
void Rotate(Object *object, Vec3 rotation);
void Scale(Object *object, Vec3 scale);

#endif
