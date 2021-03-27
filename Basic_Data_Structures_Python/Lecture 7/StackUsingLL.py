class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def push(head, data):
	if head == None:
		return Node(data)
		 
	new_node = Node(data)
	new_node.next = head
	head = new_node
	return head

def pop(head):
	if head == None:
		return None
	temp = head
	head = head.next
	temp.next = None
	return head	

n = int(input())
head1 = None
while n > 0:
	n -= 1
	x = int(input())
	head1 = push(head1, x)



