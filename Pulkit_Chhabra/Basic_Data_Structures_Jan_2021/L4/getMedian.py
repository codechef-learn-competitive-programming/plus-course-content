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

    def getMedianForSorted(self):
        if not self.head:
            return -1

        fast = slow = self.head
        prev_slow = None

        while fast and fast.next:
            prev_slow = slow
            slow = slow.next
            fast = fast.next.next

        if not fast:
            return (prev_slow.data + slow.data) / 2.0

        return slow.data


def main():
    l = LinkedList()
	
    l.push_back(1)

    print(l.getMedianForSorted())


if __name__ == '__main__':
    main()
