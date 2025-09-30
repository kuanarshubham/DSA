// post order

import java.util.ArrayList;
import java.util.List;

class Node{
    public int data;
    public Node left;
    public Node right;

    public Node(int data){
        this.data=data;
        this.left=null;
        this.right=null;
    }

    public Node(int data, Node left, Node right){
        this.data=data;
        this.left=left;
        this.right=right;
    }
}

public class Java91 {
    static void helper(Node root, List<Integer>traversal){
        if(root==null) return;

        helper(root.left, traversal);
        helper(root.right, traversal);
        traversal.add(root.data);
    }

    static List<Integer> postorder(Node root){
        List<Integer>traversal = new ArrayList<>();

        helper(root, traversal);

        return traversal;
    }
}