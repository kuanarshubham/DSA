// bottom view

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

public class Java106 {
    static ArrayList<Integer> bottomView(Node root){
        if(root==null) return new ArrayList<>(1);

        ArrayDeque<Pair<Integer, Node>>dq = new ArrayDeque<>();

        ArrayList<Integer>ans = new ArrayList<>();

        TreeMap<Integer, Integer>map = new TreeMap<>();

        dq.push(new Pair<>(0, root));

        while(!dq.isEmpty()){
            Pair<Integer, Node>p = dq.poll();
            Node node = p.second;
            int y=p.first;

            if(node.left!=null) dq.addLast(new Pair<>(y-1, node.left));
            if(node.right!=null) dq.addLast(new Pair<>(y+1, node.right));

            map.put(y, node.data);
        }

        for(Map.Entry<Integer, Integer>entry: map.entrySet()){
            ans.add(entry.getValue());
        }

        return ans;
    }
}