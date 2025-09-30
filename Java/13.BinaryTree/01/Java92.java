// level order traversal

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

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

public class Java92 {
    static ArrayList<Integer> levelOrder(Node root) {
        Node temp = root;

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        LinkedList<Node> q = new LinkedList<>();

        q.push(temp);

        while (!q.isEmpty()) {
            ArrayList<Integer> currArray = new ArrayList<>();

            int currQueueSize = q.size();

            for (int i = 0; i < currQueueSize; i++) {
                Node topValue = q.getFirst();
                q.pop();

                currArray.add(topValue.data);

                if (topValue.left != null) {
                    q.push(topValue.left);
                }

                if (topValue.right != null) {
                    q.push(topValue.right);
                }
            }

            ans.add(currArray);
        }

        return ans;
    }
}