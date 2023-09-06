// Runtime: 34 ms (Top 47.7%) | Memory: 44.49 MB (Top 31.3%)

class Solution {
    public int minimumPartition(String s, int k) {
        int i=0,c=0,j=0;
        // i - left pointer
        // j - right pointer
        while(j<s.length())
        {
            while(j<s.length() && Long.parseLong(s.substring(i,j+1))<=k)
                j++;
            c++;
            if(i==j)
                return -1;
            i=j;
        }
        return c;
    }
}