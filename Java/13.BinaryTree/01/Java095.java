// itreative postorder

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

public class Java095 {
    static ArrayList<Integer> postOrder(Node head){
        ArrayList<Integer>ans = new ArrayList<>();

        Stack<Node>st = new Stack<>();

        Node curr=head, lastVisited=null;

        while(curr!=null || !st.isEmpty()){
            while(curr!=null){
                st.push(curr);
                curr=curr.left;
            }

            Node temp=st.peek();
            System.err.println(st);
            
            if(temp.right!=null && lastVisited!=temp.right){
                curr=temp.right;
            }
            else{
                ans.add(temp.data);
                lastVisited=st.pop();
            }
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

        System.err.println(postOrder(root));
    }
}