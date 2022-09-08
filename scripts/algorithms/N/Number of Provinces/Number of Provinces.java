// Runtime: 7 ms (Top 22.65%) | Memory: 42.7 MB (Top 99.36%)
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int size = isConnected.length;
        boolean[] isCheck = new boolean[size+1];
        int ans = 0;

        for(int i=1; i<=size; i++){

            if(!isCheck[i]){ // Doing BFS if it's false in isCheck[]
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                ans++; // No. of queue = No. of Graphs

                while(!q.isEmpty()){
                    int temp = q.remove();
                    isCheck[temp] = true;

                    for(int j=0; j<size; j++){
                        if(isConnected[temp-1][j]==1 && !isCheck[j+1])
                            q.add(j+1);
                    }
                }
            }
        }
        return ans;
    }
}