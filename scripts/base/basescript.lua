obj = ...

this = {
  __index=obj,
}

BaseObject = {
  transform = {
    translation = {
      x = 0,
      y = 0,
      z = 0
    },
    rotation = {
      x = 0,
      y = 0,
      z = 0
    },
    scale = {
      x = 0,
      y = 0,
      z = 0
    },
  },
  script = ""
}

ObjectMetatable = {__index = BaseObject}

-- setmetatable(this, ObjectMetatable)

-- print(num.transform.x)

print(this)
