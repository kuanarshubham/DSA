//insert into the LL

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

public class Java070{
    public static Node insert(Node head, int value, int place){
        if(place==1 || place==0){
            Node newHead = new Node(value, head);
            return newHead;  
        }

        Node temp = head;
        int i=1;

        while(temp.next!=null){
            if(i+1==place){
                Node newNode = new Node(value, temp.next);
                temp.next = newNode;
                break;
            }

            temp=temp.next;
            i++;
        }

        return head;
    }
}