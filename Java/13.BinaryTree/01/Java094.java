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

        st.push(head);

        while(!st.isEmpty()){
            if(st.peek().left!=null){
                st.push(st.peek().left);
                continue;
            }

            Node topValue = st.pop();

            ans.add(topValue.data);
            
            if(topValue.right!=null) st.push(topValue.right);
        }

        return ans;
    }
    
}