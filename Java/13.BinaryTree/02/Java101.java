// check if 2 trees are idemntical or not

class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    public Node(int data, Node left, Node right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

public class Java101 {
    static boolean isSame = true;

    static void traverse(Node head1, Node head2){
        if(head1==null && head2==null) return;

        if(!isSame) return;

        if(head1==null || head2==null){
            isSame=false;
            return;
        }

        if(head1.data!=head2.data){
            isSame=false;
            return;
        }

        traverse(head1.left, head2.left);
        traverse(head1.right, head2.right);
    }

    static boolean checkSame(Node head1, Node head2){
        isSame=true;
        traverse(head1, head2);
        return isSame;
    }
}