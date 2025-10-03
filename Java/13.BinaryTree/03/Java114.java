// min time to burn all the nodes

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

class Pair<U, V>{
    public U first;
    public V second;

    public Pair(U u1, V v1){
        first=u1;
        second=v1;
    }
}

public class Java114 {
    static void makeParent(Node root, HashMap<Node, Node>parentMap){
        ArrayDeque<Node>dq = new ArrayDeque<>();

        dq.push(root);

        while(!dq.isEmpty()){
            Node node = dq.poll();

            if(node.left!=null){
                parentMap.put(node.left, node);
                dq.add(node.left);
            }

            if(node.right!=null){
                parentMap.put(node.right, node);
                dq.add(node.right);
            }
        }
    }

    static int timeTaken(Node root, Node targetNode){
        HashMap<Node, Node>parentMap = new HashMap<>();

        makeParent(root, parentMap);

        ArrayDeque<Node>dq = new ArrayDeque<>();

        dq.add(targetNode);

        int time = 0;

        while(!dq.isEmpty()){
            int n=dq.size();

            for(int i=0; i<n; i++){
                Node node = dq.poll();

                if(node.left!=null) dq.add(node.left);
                if(node.right!=null) dq.add(node.right);

                if(parentMap.containsKey(node)) dq.push(parentMap.get(node));
            }

            time++;
        }

        return time;
    }
}
