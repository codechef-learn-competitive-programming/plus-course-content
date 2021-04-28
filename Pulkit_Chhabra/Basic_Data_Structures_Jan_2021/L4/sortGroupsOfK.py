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

    def SinglyReverseK(self, cur_head, k):
        if not cur_head:
            return None

        cur = cur_head
        prev = None

        cnt = 0

        while (cur and cnt < k):
            next_node = cur.next

            cur.next = prev

            prev = cur
            cur = next_node
            cnt += 1

        cur_head.next = self.SinglyReverseK(cur, k)

        return prev


def main():
    l = LinkedList()

    for i in range(1, 3):
        l.push_back(i)

    new_head = l.SinglyReverseK(l.head, 2)
    l.head = new_head

    l.print_iter()


if __name__ == '__main__':
    main()
