import java.util.*;


public class Java137 {
    static ArrayList<Integer> bfs(int[][] graph){
        int nodes=graph.length;
        

        ArrayDeque<Integer>dq=new ArrayDeque<>();
        ArrayList<Integer>ans=new ArrayList<>();

        int[] vis = new int[nodes];

        dq.addLast(0);

        while(!dq.isEmpty()){
            int currNode = dq.poll();

            if(vis[currNode]==0){
                vis[currNode]=1;

                for(int num: graph[currNode]){
                    dq.addLast(num);
                }

                ans.add(currNode);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        
    }
}