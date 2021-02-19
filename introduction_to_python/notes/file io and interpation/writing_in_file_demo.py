f1 = open('input.txt', 'w+')
f2 = open('output.txt', 'w')
f3 = open('download.jpeg', 'w+b')
f1.write('Sanket singh is teaching on unacademy\n')
f1.write('Codechef and Unacademy')
f1.seek(0)
# print(f1.read())
b_ = b"0x410x42"
print(f1.tell())
f3.write(b_)
f3.seek(0)
print(f3.read())

f3.close()
# below this there is some other logic where u dont want to do openrations on file