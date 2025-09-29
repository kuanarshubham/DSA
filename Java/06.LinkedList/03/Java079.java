// detect a loop

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

public class Java079 {
    static bool isCyclic(Node head){
        if(head==null || head.next==null) return head;

        Node slow=head, fast=head;

        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;

            if(fast==slow) return true;
        }

        return false;
    }
}