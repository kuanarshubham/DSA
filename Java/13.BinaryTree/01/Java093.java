// interactive preorder

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

public class Java093 {
    static List<Integer> preorder(Node head){
        Node temp=head;

        Stack<Node>st = new Stack<>();
        ArrayList<Integer>ans = new ArrayList<>();

        st.push(temp);

        while(!st.isEmpty()){
            Node node = st.pop();
            
            ans.add(node.data);

            if(node.right!=null) st.push(node.right);
            
            if(node.left!=null) st.push(node.left);
        }

        return ans;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node node2 = new Node(2), node3 = new Node(3), node4 = new Node(4), node5 = new Node(5), node6 =  new Node(6);

        root.left=node2;
        root.right=node3;
        node2.left=node4;
        node2.right=node5;
        node3.right=node6;

        System.err.println(preorder(root));
    }
}