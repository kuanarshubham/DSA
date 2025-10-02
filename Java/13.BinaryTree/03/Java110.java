// LCA

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

public class Java110 {
    static Node lca(Node root, int n1, int n2){
        if(root==null) return null;

        if(n1==root.data || n2==root.data) return root;

        Node left = lca(root.left, n1, n2), right = lca(root.right, n1, n2);

        if(left==null) return right;
        
        if(right==null) return left;

        if(left!=null && right!=null) return root;

        return null;
    }
}