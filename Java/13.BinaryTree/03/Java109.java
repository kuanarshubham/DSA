// root to node path 

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

public class Java109 {
    static void helper(Node root, int node, ArrayList<Integer>arr){
        if(!arr.isEmpty() && arr.getLast()==node) return;
        if(root==null) return;
        if(root.data==node){
            arr.add(root.data);
            return;
        }

        arr.add(root.data);
        helper(root.left, node, arr);
        helper(root.right, node, arr);
        arr.removeLast();
    }
    static ArrayList<Integer> rootToNode(Node root, int node){
        if(root==null) return new ArrayList<>(1);

        ArrayList<Integer>ans = new ArrayList<>();

        helper(root, node, ans);
        return ans;
    }
}