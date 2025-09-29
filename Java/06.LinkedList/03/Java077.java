// reverse LL

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

public class Java077 {
    static Node reverse(Node head){
        if(head==null || head.next==null) return head;

        Node curr=head, prev=null, nxt=null;

        while(curr!=null){
            nxt=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }

    public static void main(String[] args) {
        
    }
}