package doublylinkedlist;

public class DoublyLinkedList {
  
    public static void main(String[] args) {

        DoublyLinkedList d = new DoublyLinkedList();

        d.add(3);
        d.add(5);
        d.add(8);
        d.add(7);
        d.add(1);
        d.display();
    }

    class Node {

        int data;
        Node previous;
        Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    Node head = null;
    Node tail = null;

    public void add(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = tail = newNode;
            head.previous = null;
            tail.next = null;
        } else {
            tail.next = newNode;
            newNode.previous = tail;
            tail = newNode;
            tail.next = null;
        }
    }

    public void display() {

        Node current = head;
        if (head == null) {
            System.out.println("List is empty.Nothing to print.");
            return;
        }
        System.out.println("Nodes are: ");
        while (current != null) {

            System.out.print(current.data + " ");
            current = current.next;
        }
    }
}
