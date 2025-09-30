// height of the tree

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

public class Java097 {
    static int height(Node root){
        if(root==null) return 0;

        int left = 1+height(root.left);
        int right = 1+height(root.right);

        return Integer.max(left, right);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(4);
        Node n5 = new Node(5);
        Node n6 = new Node(6);

        root.left=n2;
        root.right=n6;
        n2.left=n3;
        n2.right=n4;
        n4.right=n5;

        System.err.println(height(root))
        ;
    }
}