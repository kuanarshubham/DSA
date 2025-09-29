// search in LL

class Node{
    public int data;
    public Node next;

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class Java073 {
    public static int serach(Node head, int value){
        int i=1;

        Node temp=head;

        while(temp!=null){
            if(temp.data==value) break;
            i++;
            temp=temp.next;
        }

        return i;
    }
    public static void main(String[] args) {
        Node head = new Node(1, new Node(2, new Node(3, null)));

        System.err.println(head.data);
        System.err.println(serach(head, 2));
    }
}
