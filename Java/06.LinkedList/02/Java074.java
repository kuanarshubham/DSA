// insert in DLL

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

public class Java074 {
    public static Node insert(Node head, int value, int place){
        if(place==0 || place==1) return new Node(value, head, null);

        int i=2;

        Node temp=head;

        while(temp!=null){
            if(i+1==place){
                Node tempNext = temp.next;
                Node newNode = new Node(value, tempNext, temp);
                temp.next=newNode;
                tempNext.prev=newNode;

                break;
            }

            temp=temp.next;
            i++;
        }

        return head;
    }
}