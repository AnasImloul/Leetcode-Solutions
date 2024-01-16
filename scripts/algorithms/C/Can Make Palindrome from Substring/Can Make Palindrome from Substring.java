// Runtime: 29 ms (Top 84.38%) | Memory: 106.10 MB (Top 54.69%)

class Solution 
{ public List<Boolean> canMakePaliQueries(String s, int[][] queries) 
    {
        List<Boolean> list = new ArrayList<>();
        
        int n = s.length();
        // prefix map to count number of time each letters have occured to access in queries in O(1)
       //s=  a b c d a
        // a 1 1 1 1 2
        // b 0 1 1 1 1
        // c 0 0 1 1 1
        // d 0 0 0 1 1
        // e
        // f
        // .
        // .
        // .
        int[][] map = new int[n+1][26];
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<26;j++)
                map[i+1][j] = map[i][j];
            
            map[i+1][s.charAt(i) - 'a']++;
        }
        
        for(int[] q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int count = 0;
            
            for(int i=0;i<26;i++)
                count += (map[r+1][i] - map[l][i]) % 2;// count total characters that have odd count, so that we can replace the half of them with their pair.
            
            list.add(count/2 <= k);// if we can replace half of them with their pair
        }
        
        return list;
    }
}
