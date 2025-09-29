// reverse a LL using recurssion

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

public class Java078 {
    static Node helperReccursionFn(Node curr, Node prev){
        if(curr==null) return prev;

        Node nxt=curr.next;
        curr.next=prev;

        return helperReccursionFn(nxt, curr);
    }

    static Node reverse(Node head){
        if(head==null || head.next==null) return head;

        Node prev=null;
        return helperReccursionFn(head, prev);
    }
}