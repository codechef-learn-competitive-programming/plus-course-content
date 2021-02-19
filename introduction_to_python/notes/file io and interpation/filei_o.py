f = open("input.txt", "a+")
f.write("Hy there")
f.seek(0)
print(f.read())
# s = f.read(50) # read expects an argument as count -> which denotes the number of bytes to be counted
# print(s)