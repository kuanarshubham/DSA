// Zig Zag Traversal of Binary Tree

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

public class Java102 {
    static ArrayList<ArrayList<Integer>> ziZagOrder(Node root){
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        ArrayDeque<Node>dq = new ArrayDeque<>();

        boolean leftToRight = true;

        dq.add(root);

        while(!dq.isEmpty()){
            int n=dq.size();

            ArrayList<Integer>temp = new ArrayList<>();

            for(int i=0; i<n; i++){
                Node node = dq.pop();
                temp.add(node.data);
            }

            if(!leftToRight){
                Collections.reverse(temp);
            }

            leftToRight=!leftToRight;

            ans.add(temp);
        }

        return ans;
    }
}