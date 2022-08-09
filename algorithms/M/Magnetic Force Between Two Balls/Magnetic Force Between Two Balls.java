class Solution {
    
    boolean isPossible(int[] position, int m, int mid)
    {
        int count = 1;
        int placed = position[0];
        for(int i=1; i<position.length; i++)
        {
            if(position[i]-placed >= mid)
            {
                placed = position[i];
                count++;
            }
            if(count==m)
            {
                return true;
            }
        }
        return false;
    }
    
    public int maxDistance(int[] position, int m) {
        
        Arrays.sort(position);
        int n = position.length;
        
        int s = 1;
        int e = position[n-1];
        int ans = 0;
        
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(isPossible(position, m, mid))
            {
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        
        return ans;
        
    }
}
