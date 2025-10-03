// maximum width of BT

import java.util.ArrayDeque;
import java.util.Deque;

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

public class Java111 {
    static int maxiWidth(Node root){
        if(root==null) return 0;

        ArrayDeque<Pair<Node, Integer>>dq = new ArrayDeque<>();

        dq.push(new Pair<Node, Integer>(root, 0));

        int maxiDiff = 0, first=-1, last=-1;

        while(!dq.isEmpty()){
            int n=dq.size();

            int mini=dq.peek().second;

            for(int i=0; i<n; i++){
                Pair<Node, Integer>p = dq.poll();
                Node node = p.first;
                int num = p.second;

                if(i==0) first=num;
                if(i==n-1) last=num;

                if(node.left!=null) dq.push(new Pair<>(node.left, (num-mini)*2+1));
                if(node.right!=null) dq.push(new Pair<>(node.right, (num-mini)*2+2));
            }

            maxiDiff=Integer.max(first-last, maxiDiff);
        }

        return maxiDiff;
    }
}