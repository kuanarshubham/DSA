// complete bt nodes with TC < O(N)

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

    public Pair(U u1, V v1){
        first=u1;
        second=v1;
    }
}

public class Java115 {
    static int countNodes(Node root){
        if(root==null) return 0;
        
        int leftTreeCount = countNodes(root.left);
        int rightTreeCount = countNodes(root.right);

        if(leftTreeCount==rightTreeCount) return (1<<leftTreeCount)-1;

        return 
    }

    static int findHeight(Node root){
        if(root==null) return 0;

        int leftH = findHeight(root.left);
        int rightH = findHeight(root.right);

        return 1 + Math.max(leftH, rightH);
    }
}