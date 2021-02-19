f1 = open('download.jpeg', 'rb')
f2 = open('input.txt', 'r+')

print(f2.read(10)) # reads the file 
print(f2.tell())
print(f2.seek(2))
print(f2.read(5)) # reads the first 5 bytes of the text file
print(f2.tell())

f2.seek(0)
print(f2.readline())
print(f2.tell())
f2.seek(0)

for i in range(0, 2):
	print(f2.readline())
"""
read function takes argument -> s -> it reads s bytes of the file
"""

"""
tell function -> get the current file pointer/cursor position
"""
"""
seek(p) function -> to bring the cursor at any custom position p
"""

print(f1.read())
















