transform = {ref=...}
vec = {ref=...}

Vec3Metatable = {}
Vec3Metatable.__index = vec3_index
Vec3Metatable.__newindex = vec3_newindex

TransformMetatable = {}
TransformMetatable.__index = transform_index
TransformMetatable.__newindex = transform_newindex

setmetatable(vec, Vec3Metatable)
setmetatable(transform, TransformMetatable)

print(vec.x, vec.y, vec.z)
vec.x = 9.0
print(vec.x, vec.y, vec.z)

print("Entering Transform Territory")
print(transform)

function tprint(tb1, indent)
  if not indent then indent = 0 end
  for k, v in pairs(tb1) do
    formatting = string.rep("  ", indent) .. k .. ": "
    if type(v) == "table" then
      print(formatting)
      tprint(v, indent + 1)
    elseif type(v) == "userdata" then
      print(formatting .. tostring(v))
    else
      print(formatting .. v)
    end
  end
end

-- tprint(transform)

-- tprint(vec)

-- tprint(this)
