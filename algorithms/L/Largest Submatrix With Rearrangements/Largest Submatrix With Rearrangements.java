class Solution {
    public int largestSubmatrix(int[][] matrix) {
         //Store matrix[i][j]= total number of consecutive 1s along column j ending at index (i,j).
        for(int i=1;i<matrix.length;i++)  //Start from row 1 because row 0 will be unaffected as no row above it.
        {
            for(int j=0;j<matrix[i].length;j++)
            {
                if(matrix[i][j]==0) continue;
                else  matrix[i][j]=matrix[i-1][j]+1;
            }
        }
        
        int maxSize=0;
        for(int i=0;i<matrix.length;i++)
        {
           
            PriorityQueue<Integer> pq  =  new PriorityQueue<Integer>();// minheap
            for(int j=0;j<matrix[i].length;j++)
            {
                if(matrix[i][j]>0)  pq.add(matrix[i][j]); // Add all the entries from row i in minheap
            }
            int size=0,curr=0;
            /*
                In current row, total entries with value k or greater than k will contribute the squares of
				size=k*(number of squares of size k or greater than k).Largest square ending at current
				row= k * (all entries greater than or equal to k in current row) for all ks in current row
            */
            while(!pq.isEmpty())  
            {
                curr=pq.peek(); 
                
                size=curr*pq.size();
                maxSize=Math.max(maxSize,size);
                
                pq.poll();
            }
        }
        return maxSize;
        
        
        
    }
}
