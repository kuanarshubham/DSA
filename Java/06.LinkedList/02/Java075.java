// delete node

class Node{
    public int data;
    public Node next;
    public Node prev;

    public Node(int data, Node next, Node prev){
        this.data=data;
        this.next=next;
        this.prev=prev;
    }

    public Node(int data){
        this.data=data;
        this.next=null;
        this.prev=null;
    }
}

public class Java075 {
    static Node delete(Node head, int place){
        if(head==null) return null;
        if(head.next==null && place==1) return null;

        if(place==1) return head.next;

        int i=2;

        Node temp=head;

        while(temp!=null){
            if(place==i){
                Node tempNextNext = temp.next.next;
                tempNextNext.prev=temp;
                temp.next=tempNextNext;
                break;
            }

            i++;
            temp=temp.next;
        }

        return head;
    }

    public static void main(String[] args) {
        
    }
}