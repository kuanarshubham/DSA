// add 2 LL

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

public class Java084 {
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

    static Node add2Num(Node head1, Node head2){
        if(head1==null || head2==null) return null;

        int carry=0;

        Node reverseHead1=reverse(head1), reverseHead2=reverse(head2);

        Node temp1=reverseHead1, temp2=reverseHead2, head=new Node(-1), temp=head;

        while(temp1!=null && temp2!=null){
            int sum = temp1.data+temp2.data+carry;
            carry=sum/10;

            temp.next=new Node(sum%10);

            temp=temp.next;
            temp1=temp1.next;
            temp2=temp2.next;
        }

        while(temp1!=null){
            int sum = temp1.data+carry;
            carry=sum/10;

            temp.next=new Node(sum%10);

            temp=temp.next;
            temp1=temp1.next;
        }

        while(temp2!=null){
            int sum = temp2.data+carry;
            carry=sum/10;

            temp.next=new Node(sum%10);

            temp=temp.next;
            temp2=temp2.next;
        }

        Node newHead = reverse(head.next);

        head1 = reverse(reverseHead1);
        head2 = reverse(reverseHead2);

        return newHead;
    }
}