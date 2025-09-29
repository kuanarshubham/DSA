//Deleting a node in LinkedList

class Node{
    public int data;
    public Node next;

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class Java071 {
    public static Node delete(Node head, int place){
        if(head.next==null) return null;
        if(place==1) return head.next;

        int i=1;
        Node temp = head;

        while(temp.next!=null){
            if(i+1==place){
                Node tempNextNext = temp.next.next;
                temp.next=tempNextNext;
                break;
            }

            i++;
            temp=temp.next;
        }

        return head;
    }    
}
