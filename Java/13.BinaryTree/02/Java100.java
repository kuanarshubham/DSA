// maximum path sum

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

public class Java100 {
    static int maxiPath = 0;
    static int heightPath(Node root){
        if(root==null) return 0;

        int left = Math.max(0, heightPath(root.left));
        int right = Math.max(0, heightPath(root.right));

        maxiPath = Math.max(maxiPath, root.data+left+right);

        return root.data + Math.max(left, right);
    }

    static int maxiPathSum(Node root){
        if(root==null) return 0;

        heightPath(root);

        return maxiPath;
    }
}