class Stack:
	__arr = []
	__top = -1

	def __init__(self, n):
		self.__arr = [0]*n

	def push(self, element):
		if self.__top >= len(self.__arr) - 1:
			print("Overflow error, No more space in the stack")
			return
		self.__top += 1
		self.__arr[self.__top] = element

	def pop(self):
		if self.__top < 0:
			print("Underflow error, Stack is empty")
			return
		temp = self.__arr[self.__top]
		self.__top -= 1
		return temp


	def peek(self):
		if self.__top < 0:
			print("Underflow error, Stack is empty")
			return
		return self.__arr[self.__top]


st = Stack(5)
st.push(10)
st.push(20)
st.push(30)
print(st.peek())
st.push(40)
st.push(50)
st.push(60)
st.pop()
print(st.peek())
st.pop()
print(st.peek())
st.pop()
print(st.peek())
st.pop()
print(st.peek())
st.pop()
print(st.peek())
st.pop()

