// Runtime: 8 ms (Top 98.76%) | Memory: 45.20 MB (Top 5.55%)

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int i =0,j=0,c=0;
        
        Arrays.sort(g);
        Arrays.sort(s);
        
        
        for(;i< g.length;i++)
        {
                // System.out.println(s[j]+" "+g[i]);
 
            while(j<s.length)
            {
                if(s[j]>=g[i] )
                {
                    // System.out.println(s[j]+" "+g[i]);
                    j++;c++;
                    break;
                }
                j++;
            }
        }
       
        return c;
        
    }
}
