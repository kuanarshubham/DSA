// lenght of cycle

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

public class Java081 {
    static int lenghtOfCycle(Node head){
        if(head==null || head.next==null) return 0;

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

        if(!isCyclic) return 0;

        slow=head;

        while(slow==fast){
            slow=slow.next;
            fast=fast.next;
        }

        int len=1;

        slow=slow.next;

        while(slow!=fast){
            slow=slow.next;
            len++;
        }

        return len;
    }
}