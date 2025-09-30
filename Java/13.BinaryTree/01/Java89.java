// preorder

import java.util.ArrayList;

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

public class Java89 {
    static void helper(Node root, ArrayList<Integer>tarversal){
        if(root==null) return;

        tarversal.add(root.data);
        helper(root.left, tarversal);
        helper(root.right, tarversal);
    }

    static ArrayList<Integer> preorder(Node root){
        ArrayList<Integer>tarversal = new ArrayList<>();

        helper(root, tarversal);

        return tarversal;
    }
}