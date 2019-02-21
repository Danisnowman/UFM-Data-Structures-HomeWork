class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:

    def __init__(self):
        self.head = None

        def push(self, new_value):
            new_node = Node(new_value)
            new_node.next = self.head
            if self.head is not None:
                self.head.prev = new_node
            self.head = new_node

        def print_list(self, node):
            while node is not None:
                print(node.data)
                last = node
                node = node.next
