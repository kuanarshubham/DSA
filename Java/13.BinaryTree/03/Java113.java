// print all the nodes of at a diustance k

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

    public Pair(U u1, V v1) {
        first = u1;
        second = v1;
    }
}

public class Java113 {
    private void markParent(HashMap<Node, Node> parentMap, Node root) {
        ArrayDeque<Node> dq = new ArrayDeque<>();
        dq.push(root);

        while (!dq.isEmpty()) {
            Node node = dq.poll();

            if (node.left != null) {
                dq.push(node.left);
                parentMap.put(node.left, node);
            }

            if (node.right != null) {
                dq.push(node.right);
                parentMap.put(node.right, node);
            }
        }
    }

    public ArrayList<Integer> distance(Node root, Node targetNode, int k) {
        HashMap<Node, Node> parentMap = new HashMap<>();
        markParent(parentMap, root);

        ArrayList<Integer> ans = new ArrayList<>();

        ArrayDeque<Node> dq = new ArrayDeque<>();
        int level = 0;

        dq.push(targetNode);

        while (!dq.isEmpty()) {
            int n = dq.size();

            if (level == k) break;
            level++;

            for (int i = 0; i < n; i++) {
                Node node = dq.poll();

                if (parentMap.containsKey(node)) {
                    dq.add(parentMap.get(node));
                }

                if (node.left != null) {
                    dq.add(node.left);
                }

                if (node.right != null) {
                    dq.push(node.right);
                }
            }
        }

        while(!dq.isEmpty()){
            ans.add(dq.poll().data);
        }

        return ans;
    }
}