// Boundary Traversal of Binary Tree

import java.util.ArrayList;

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

public class Java103 {
    static getAllthe
    static ArrayList<Integer> boundaryList(Node root){
        if(root==null) return new ArrayList<>();

        ArrayList<Integer>ans = new ArrayList<>();

        // go left and take all the lefts 
        Node temp = root;
        while(temp.left!=null){
            ans.add(temp.data);
            temp=temp.left;
        }

        // take all the leave
        

    }
}