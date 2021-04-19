class ComplexNumber:
	real = 0 # class variables
	img = 0

	def __init__(self, real, img):
		self.real = real
		self.img = img

	def display(self):
		print(self.real, f"+ i{self.img}")

	def add(self, c):
		return ComplexNumber(self.real+c.real, self.img+c.img)


c1 = ComplexNumber(5, 3) # this calls the class contructor
c2 = ComplexNumber(4, 4)

c1.display()
c2.display()
c3 = c1.add(c2)
c3.display()