//find the starting point of loop

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

public class Java080 {
    static Node loopStart(Node head){
        if(head==null || head.next==null) return null;

        bool isCyclic=false;

        Node slow=head, fast=head;

        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;

            if(slow==fast){
                isCyclic=true;
                break;
            }
        }

        if(!isCyclic) return null;

        slow=head;

        while(slow==fast){
            slow=slow.next;
            fast=fast.next;
        }

        return slow;
    }
    
}