function onStart()
  print("onStart")
  i = 0
end

function onUpdate()
  print(string.format("onUpdate: Iteration Count = %d", i))
  i = i + 1
end

