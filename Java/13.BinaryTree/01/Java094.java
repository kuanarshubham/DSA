// inorder iterative

import java.util.*;

class Node{
    public int data;
    public Node left, right;

    public Node(int data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}

public class Java094 {
    static List<Integer> inorder(Node head){
        
        List<Integer>ans = new ArrayList<>();
        Stack<Node>st = new Stack<>();

        Node curr=head;

        while(curr!=null || !st.isEmpty()){
            while(curr!=null){
                st.push(curr);
                curr=curr.left;
            }

            curr=st.pop();
            ans.add(curr.data);

            curr=curr.right;
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

        System.err.println(inorder(root));
    }
}