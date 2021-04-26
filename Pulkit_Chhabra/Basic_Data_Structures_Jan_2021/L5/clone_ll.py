class node:
    def __init__(self, d):
        self.data = d
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def push_back(self, val):
        new_tail = node(val)
        if not self.tail:
            self.head = self.tail = new_tail
        else:
            self.tail.next = new_tail
            new_tail.prev = self.tail
            self.tail = new_tail

        self.size += 1

    def print_iter(self):
        cur = self.head
        while cur:
            print(cur.data, end=' ')
            cur = cur.next

        print()


def cloneLL(head: node):
    newHead = node(head.data)

    cur = head
    newCur = newHead

    while (cur.next):
        newNext = node(cur.next.data)

        newCur.next = newNext

        cur = cur.next
        newCur = newCur.next

    return newHead


def main():
    l = LinkedList()

    l.push_back(1)
    l.push_back(2)
    l.push_back(3)

    cloned = cloneLL(l.head)
    while (cloned):
        print(cloned.data, end=' ')
        cloned = cloned.next


if __name__ == '__main__':
    main()
