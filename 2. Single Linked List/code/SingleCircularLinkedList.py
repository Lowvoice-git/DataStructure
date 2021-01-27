class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class List:
    def __init__(self):
        self.head = None
        self.__size = 0

    def empty(self):
        return self.head is None if True else False

    def size(self):
        return self.__size

    def push_back(self, value):
        new_node = Node(value)
        if not self.empty():
            node = self.head
            while node.next is not self.head:
                node = node.next
            new_node.next = node.next
            node.next = new_node
        else:
            self.head = new_node
            self.head.next = self.head
        self.__size += 1

    def pop_back(self):
        if self.size() is 0:
            return
        elif self.size() is 1:
            self.head = None
            self.__size -= 1
        else:
            node = self.head
            while node.next.next is not self.head:
                node = node.next
            node.next = self.head
            self.__size -= 1

    def insert(self, index, value):
        new_node = Node(value)
        if index is 0:
            new_node.next = self.head
            self.head = new_node
            self.__size += 1
        elif self.size() - 1 >= index:
            node = self.head
            while index - 1 is not 0:
                node = node.next
                index -= 1
            new_node.next = node.next
            node.next = new_node
            self.__size += 1
        elif self.size() is index:
            self.push_back(value)

    def erase(self, index):
        if not self.empty():
            if index is 0:
                temp = self.head
                self.head = temp.next
                self.__size -= 1
            elif self.size() - 1 > index:
                node = self.head
                while index - 1 is not 0:
                    node = node.next
                    index -= 1
                temp = node.next.next
                node.next = None
                node.next = temp
                self.__size -= 1
            elif self.size() - 1 is index:
                self.pop_back()

    def reverse(self, node):
        data = node.data
        if node.next is self.head:
            self.head.data = data
            return self.head.next
        temp = self.reverse(node.next)
        temp.data = data
        return temp.next


if __name__ == "__main__":
    _list = List()

    _list.push_back(0)
    _list.push_back(1)
    _list.push_back(2)
    _list.push_back(3)
    _list.push_back(4)
    _list.push_back(5)
    _list.push_back(6)
    _list.push_back(7)

    _list.pop_back()
    _list.pop_back()

    _list.insert(0, 100)
    _list.erase(0)

    _list.insert(6, 200)
    _list.erase(6)

    _list.insert(2, 300)
    _list.erase(2)

    _list.reverse(_list.head)