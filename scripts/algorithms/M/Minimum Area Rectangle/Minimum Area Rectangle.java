// Runtime: 35 ms (Top 98.98%) | Memory: 45.00 MB (Top 39.53%)

class Solution {
    public int minAreaRect(int[][] points) {
        HashMap<Integer,Set<Integer>> hm = new HashMap<>();
        int area=Integer.MAX_VALUE;
        
        for(int[] point: points)
        {            
            if(!hm.containsKey(point[0]))
                hm.put(point[0],new HashSet());        
            hm.get(point[0]).add(point[1]); // x-coordinate already exits, just add the y-coordinate to the set
        }
        
        for(int i=0;i<points.length-1;i++)
        {
            for(int j=i+1;j<points.length;j++)
            {
                int x1=points[i][0],x2=points[j][0],y1=points[i][1],y2=points[j][1]; // this step reduced the time from 368ms to 186ms
                if(x1!=x2 && y1!=y2) //diagonal is not parallel to x or y axis
                {
                    if(area>Math.abs((x2-x1) * (y2-y1))) //pre-calulate the area to avoid unecessary lookup. This step reduced the time from 186ms to 57ms.
                    {
                        if(hm.get(x1).contains(y2) && hm.get(x2).contains(y1)) // learnt from other leetcoders. Thank you.
                             area=Math.abs((x2-x1) * (y2-y1)); 
                    }
                }
                
            }
        }
        
        return area<Integer.MAX_VALUE? area:0;
    }
}
