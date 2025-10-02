// symetric binary tree

import java.util.*;

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

class Pair<U, V>{
    public U first;
    public V second;

    public Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}

public class Java108 {
    static boolean helper(Node left, Node right){
        if(left==null && right==null) return true;
        
        if(left==null || right==null) return false;

        if(left.data!=right.data) return  false;

        return helper(left.left, right.right) && helper(left.right, right.left);
    }

    static boolean isSymmetric(Node root){
        if(root==null) return true;

        return helper(root.left, root.right);
    }
}