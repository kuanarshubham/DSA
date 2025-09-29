// add 1 to the number 

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

public class Java083 {
    static Node reverse(Node head){
        Node prev=null, curr=head;

        while(curr!=null){
            Node temp=curr.next;
            curr.next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    static Node add1(Node head){
        if(head==null) return head;
        
        Node reverseHead = reverse(head);

        int carry=1;

        Node temp=reverseHead, prev=null;

        while(temp!=null){
            carry=(temp.data+carry) == 10 ? 1 : 0;
            temp.data=(temp.data+carry)%10;

            prev=temp;
            temp=temp.next;
        }

        if(carry){
            prev.next=new Node(1);
        }

        Node forwardHead=reverse(reverseHead);

        return forwardHead;
    }
}