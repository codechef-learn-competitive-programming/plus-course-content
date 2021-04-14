class Node:
	data = -1
	left = None
	right = None

	def __init__(self, data):
		self.data = data

def insert(root, data):
	if root == None:
		return Node(data)

	if data < root.data:
		root.left = insert(root.left, data)
	else:
		root.right = insert(root.right, data)

	return root

def preorder(root):
	if(root == None):
		return

	print(root.data, end = ", ")
	preorder(root.left)
	preorder(root.right)


def inorder(root):
	if(root == None):
		return

	inorder(root.left)
	print(root.data, end = ", ")
	inorder(root.right)


def postorder(root):
	if(root == None):
		return

	postorder(root.left)
	postorder(root.right)
	print(root.data, end = ", ")


def buildBSTRec():
	d = int(input())
	root = None
	while d != -1:
		root = insert(root, d)
		d = int(input())
	return root


root = buildBSTRec()
print()
preorder(root)
print()
inorder(root)
print()
"""
10
5
1
8
20
30
15
6
9
7
-1
"""