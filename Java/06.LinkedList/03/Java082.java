// check if LL is palindrome

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

public class Java082 {
    static Node reverse(Node head){
        Node curr=head, prev=null;
        
        while(curr!=null){
            Node nxt = curr.next;
            curr.next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }

    static bool isPalindrome(Node head){
        if(head==null || head.next==null) return true;

        Node fast=head, slow=head;

        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }

        Node reverseHead = reverse(slow.next);

        slow.next=reverseHead;

        Node firstPointer=head, lastPointer=slow.next;

        boolean ans=true;

        while(firstPointer!=null && lastPointer!=null){
            if(firstPointer.data!=lastPointer.data){
                ans=false;
                break;
            }
            firstPointer=firstPointer.next;
            lastPointer=lastPointer.next;
        }

        reverseHead = reverse(slow.next);
        slow.next=reverseHead;

        return ans;
    }
}