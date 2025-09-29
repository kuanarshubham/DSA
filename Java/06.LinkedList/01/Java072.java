// len of LL

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

public class Java072 {
    public static int len(Node head){
        if(head==null) return 0;

        int lenght=1;

        while(head.next!=null){
            lenght++;
            head=head.next;
        }

        return lenght;
    }

    public static void main(String[] args) {
        Node head = new Node(1, new Node(2, new Node(3)));

        System.err.println(len(head));
    }
}
