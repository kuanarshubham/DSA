// middle of LL

class Node{
    public int data;
    public Node next;

    public Node(int data, Node next){
        this.data=data;
        this.next=next;
    }
    
    public Node(int data){
        this.data=data;
        this.next=null;
    }
}

public class Java076 {
    static Node middle(Node head){
        if(head==null || head.next==null) return head;

        Node slow=head, fast=head;

        while(head.next!=null && head.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }

        return slow;
    }

    public static void main(String[] args) {
        
    }
}