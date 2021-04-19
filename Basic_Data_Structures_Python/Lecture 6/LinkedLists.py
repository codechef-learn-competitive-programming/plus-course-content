class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data


def display_LL(head):
	temp = head
	while temp != None:
		print(temp.data, end = "->")
		temp = temp.next

	print()
	return

def length_of_LL(head):
	temp = head
	sz = 0
	while temp != None:
		sz += 1
		temp = temp.next

	return sz

def insert_at_head(head, data):
	if head == None:
		return Node(data)
		 
	new_node = Node(data)
	new_node.next = head
	head = new_node
	return head

def insert_at_tail(head, data):
	if head == None:
		return Node(data)
	temp = head
	while temp.next != None:
		temp = temp.next

	new_node = Node(data)
	temp.next = new_node
	return head


def insert_at(head, data, pos = 0):
	if pos == 0:
		return insert_at_head(head, data)
	if pos >= length_of_LL(head):
		return insert_at_tail(head, data)

	temp = head
	while pos != 1:
		pos -= 1
		temp = temp.next

	new_node = Node(data)
	new_node.next = temp.next
	temp.next = new_node
	return head

def delete_at_head(head):
	if head == None:
		return None
	temp = head
	head = head.next
	temp.next = None
	return head	

def delete_at_tail(head):
	temp = head
	prev = None
	while(temp.next != None):
		prev = temp
		temp = temp.next

	# when this loop ends temp points at the tail and prev at the prev node to the tail
	prev.next = None
	return head

def delete_At(head, pos = 0):
	if pos == 0:
		return delete_at_head(head)
	if pos >= length_of_LL(head):
		return delete_at_tail(head)

	temp = head
	while pos != 1:
		pos -= 1
		temp = temp.next

	tobedeleted = temp.next
	temp.next = temp.next.next
	tobedeleted.next = None
	return head

def find_mid_node(head):
	if head == None:
		return head
	fast, slow = head.next, head
	while fast != None and fast.next != None:
		fast = fast.next.next
		slow = slow.next

	return slow


def sum_LL_same_size(head1, head2):
	if head1 == None or head2 == None:
		return (None, 0)
	result = Node(0)
	returned_node, carry = sum_LL_same_size(head1.next, head2.next)
	result.next = returned_node
	sum_ = head1.data + head2.data + carry
	carry = sum_//10
	result.data = sum_%10
	return (result, carry)

def sum_LL(head1, head2):
	result, carry = sum_LL_same_size(head1, head2)
	if carry == 0:
		return result
	n = Node(carry)
	n.next = result
	return n


def check_palindrome(left, right):
	if right != None:
		result = check_palindrome(left, right.next)
		left = result[1]
		if not result[0]:
			return (False, left)
		if left.data != right.data:
			return (False, left)

		left = left.next

	return (True, left)

def palindrome(head1, head2):
	result = check_palindrome(head1, head2)
	return result[0]

def merge_sorted_ll(left, right):
	if left == None:
		return right
	if right == None:
		return left
	result = None
	if left.data < right.data:
		result = left
		result.next = merge_sorted_ll(left.next, right)
	else:
		result = right
		result.next = merge_sorted_ll(left, right.next)
	return result

def mergesort(head):
	if head == None or head.next == None:
		return head
	mid = find_mid_node(head)
	left = head
	right = mid.next
	mid.next = None
	left = mergesort(left)
	right = mergesort(right)
	result = merge_sorted_ll(left, right)
	return result

def reversePI(head):
	if head == None:
		return head
	prev_, curr_, next_ = None, head, head.next
	while next_ != None:
		curr_.next = prev_
		prev_ = curr_
		curr_ = next_
		next_ = next_.next

	# update the last node
	curr_.next = prev_
	# change the head
	return curr_

def reversePR(head):
	if head == None or head.next == None:
		# base case
		return head
	# recursive intuition
	tail = reversePR(head.next)
	head.next.next = head
	head.next = None
	return tail


def fold_helper(left, right):
	if right == None:
		return left

	left = fold_helper(left, right.next)
	if left == None:
		return left

	if left != right and left.next != right:
		temp = left.next
		left.next = right
		right.next = temp
		left = temp
	else:
		right.next = None
		left = None

	return left




def fold(head):
	fold_helper(head, head)
	return head


n = int(input())
# m = int(input())
head1 = None
# head2 = None
while n > 0:
	n -= 1
	x = int(input())
	head1 = insert_at_tail(head1, x)

# while m > 0:
# 	m -= 1
# 	x = int(input())
# 	head2 = insert_at_tail(head2, x)


# head1 = insert_at(head, 67)
display_LL(head1)
# display_LL(head2)

# sum_= sum_LL(head1, head2)
# display_LL(sum_)
# head = delete_At(head, 4)
# display_LL(head)
# mid = find_mid_node(head)
# print("middle node is", mid.data)

# print(palindrome(head1, head1))
# head1 = mergesort(head1)
head1 = fold(head1)
display_LL(head1)

