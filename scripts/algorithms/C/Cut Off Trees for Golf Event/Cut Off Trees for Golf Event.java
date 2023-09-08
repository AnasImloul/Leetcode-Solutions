// Runtime: 273 ms (Top 92.8%) | Memory: 44.58 MB (Top 18.0%)

class Solution {
    //approach: 1st store all the positions in the min heap acc. to their height
    //now start removing the elements from the heap and calculate their dis using bfs
    // if at any point we cann't reach at the next position return -1;
    // else keep on adding the distances and return;
    public int cutOffTree(List<List<Integer>> forest) {
       PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->(forest.get(a[0]).get(a[1])-forest.get(b[0]).get(b[1])));
       for(int i=0;i<forest.size();i++){
           for(int j=0;j<forest.get(0).size();j++){
               if(forest.get(i).get(j)>1)
                   pq.add(new int[]{i,j});
           }
       }
        int ans=0;
       int curr[]={0,0};
       while(pq.size()>0){
           int[] temp=pq.poll();
           int dis=calcDis(forest,curr,temp);
           //System.out.println(dis+" "+temp.height);
           if(dis==-1)
               return -1;
           ans+=dis;
           curr=temp;
       }
        return ans;
    }
    int calcDis(List<List<Integer>> forest,int start[],int end[]){
        int n=forest.size(),m=forest.get(0).size();
        boolean vis[][]=new boolean[n][m];
        Queue<int[]> queue=new LinkedList<>();
        queue.add(start);
        vis[start[0]][start[1]]=true;
        int dis=0;
        while(queue.size()>0){
            int len =queue.size();
            while(len-->0){
                int temp[]=queue.remove();
                int r=temp[0],c=temp[1];
                if(r==end[0] && c==end[1])
                    return dis;
                if(r+1<n && !vis[r+1][c] && forest.get(r+1).get(c)!=0){
                    queue.add(new int[]{r+1,c});
                    vis[r+1][c]=true;
                }if(r-1>=0 && !vis[r-1][c] && forest.get(r-1).get(c)!=0){
                    queue.add(new int[]{r-1,c});
                    vis[r-1][c]=true;
                }if(c-1>=0 && !vis[r][c-1] && forest.get(r).get(c-1)!=0){
                    queue.add(new int[]{r,c-1});
                    vis[r][c-1]=true;
                }if(c+1<m && !vis[r][c+1] && forest.get(r).get(c+1)!=0){
                    queue.add(new int[]{r,c+1});
                    vis[r][c+1]=true;
                }
            }
            dis++;
        }
        return -1;
        
    }
}