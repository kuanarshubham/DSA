// Boundary Traversal of Binary Tree

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

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
    static void getAlltheLeaves(Node root, ArrayList<Integer>ans){
        if(root==null) return;
        if(root.left==null && root.right==null){
            ans.add(root.data);
            return;
        }

        if(root.left!=null){
            getAlltheLeaves(root.left, ans);
        }

        if(root.right!=null){
            getAlltheLeaves(root.right, ans);
        }
    }
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
        getAlltheLeaves(root, ans);

        temp=root;
        ArrayList<Integer>rightPart = new ArrayList<>();

        while(temp.right!=null){
            rightPart.add(temp.data);
            temp=temp.right;
        }

        Collections.reverse(rightPart);

        for(int num: rightPart){
            ans.add(num);
        }

        return ans;
    }
}