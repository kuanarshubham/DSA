// revsere a DLL

class Node{
    public int data;
    public Node next;
    public Node prev;

    public Node(int data, Node next, Node prev){
        this.data=data;
        this.next=next;
        this.prev=prev;
    }

    public Node(int data){
        this.data=data;
        this.next=null;
        this.prev=null;
    }
}

public class Java076 {
    static Node reverse(Node head){
        if(head==null || head.next==null) return head;

        Node next=head, prev=null;

        while(next!=null){
            Node temp=next.next;
            next.next=next.prev;
            next.prev=temp;

            prev=next;
            next=temp;
        }

        return prev;
    }

    static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
         Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);

        head.next = second;
        second.prev = head;
        second.next = third;
        third.prev = second;
        third.next = fourth;
        fourth.prev = third;


        System.out.println("Original DLL:");
        printList(head);

        head = reverse(head);

        System.out.println("Reversed DLL:");
        printList(head);
    }
}