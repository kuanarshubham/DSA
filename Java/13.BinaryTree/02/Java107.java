// right and left view

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

    public Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}


public class Java107 {
    static ArrayList<Integer>rightView(Node root){
        if(root==null) return null;

        ArrayDeque<Pair<Integer, Node>>dq = new ArrayDeque<>();
        dq.addLast(new Pair<>(0, root));

        TreeMap<Integer, Integer>map = new TreeMap<>();

        ArrayList<Integer>ans = new ArrayList<>();

        while(!dq.isEmpty()){
            int n=dq.size();

            for(int i=0; i<n; i++){
                Pair<Integer, Node> p = dq.poll();
                Node node = p.second;
                int x = p.first;

                if(node.left!=null) dq.push(new Pair<>(x+1, node.left));
                if(node.right!=null) dq.push(new Pair<>(x+1, node.right));

                map.put(x, node.data);
            }
        }

        for(Map.Entry<Integer, Integer>entry: map.entrySet()){
            ans.add(entry.getValue());
        }

        return ans;
    }
}