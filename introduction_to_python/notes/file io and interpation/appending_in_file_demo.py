f1 = open('input.txt', 'a+')

print(f1.tell())
f1.seek(0)
print(f1.read(5))
f1.write('Punjab engineering college')