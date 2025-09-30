// diameter of a tree

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

public class Java099 {
    static int ans=0;

    static int height(Node root){
        if(root==null) return 0;

        int left = 1+height(root.left);
        int right = 1+height(root.right);

        return Integer.max(left, right);
    }

    static int diameterBetter(Node root){
        if(root==null) return 0;

        int maxDaimeter = 0;

        ArrayDeque<Node>dq = new ArrayDeque<>();

        dq.push(root);

        while(!dq.isEmpty()){
            int n=dq.size();

            for(int i=0; i<n; i++){
                Node node = dq.poll();

                if(node.left!=null) dq.push(node.left);

                if(node.right!=null) dq.push(node.right);

                maxDaimeter = Integer.max(maxDaimeter, (height(node.left)+height(node.right)));
            }
        }

        return maxDaimeter;
    }

    static int heightOptimal(Node root){
        if(root==null) return 0;

        int left = heightOptimal(root.left);
        int right = heightOptimal(root.right);

        ans=Integer.max(ans, left+right);

        return Integer.max(left, right) + 1;
    }

    static int diameterOptimal(Node root){
        ans=0;
        heightOptimal(root);
        return ans;
    }
}