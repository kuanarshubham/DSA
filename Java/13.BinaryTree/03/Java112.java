// child sum property

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

public class Java112 {
    static void childSum(Node root){
        if(root==null) return;

        int child=0;
        if(root.left!=null) child+=root.left.data;

        if(root.right!=null) child+=root.right.data;

        if(child>root.data) root.data=child;
        else {
            if(root.left!=null) root.left.data=root.data;
            if(root.right!=null) root.right.data=root.data;
        }

        childSum(root.left);
        childSum(root.right);

        int tot=0;

        if(root.left!=null) tot+=root.left.data;

        if(root.right!=null) tot+=root.right.data;

        if(root.left!=null || root.right!=null) root.data=tot;
    }
}