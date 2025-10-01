// vertical order traversal

import java.lang.reflect.Array;
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

class Pair<U, V> {
    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

public class Java104 {
    static ArrayList<ArrayList<Integer>> verticalOrder(Node root){
        if(root==null) return new ArrayList<>();

        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();

        // {Node, {x, y}}
        ArrayDeque<Pair<Node, Pair<Integer, Integer>>>dq = new ArrayDeque<>();

        dq.add(new Pair<>(root, new Pair<>(0, 0)));

        // {y, []}
        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<>();

        while(!dq.isEmpty()){
            Pair<Node, Pair<Integer, Integer>> topValue =  dq.pop();

            Node node = topValue.first;
            int x = topValue.second.first, y=topValue.second.second;

            if(!map.containsKey(y)){
                map.put(y, new ArrayList<>());
            }
            
            map.get(y).add(node.data);

            if(node.left!=null) dq.push(new Pair<>(node.left, new Pair<>(x+1, y-1)));

            if(node.right!=null) dq.push(new Pair<>(node.right, new Pair<>(x+1, y+1)));
        }

        for(Map.Entry<Integer, ArrayList<Integer>>entry: map.entrySet()){
            ans.add(entry.getValue());
        }

        return ans;
    }
}