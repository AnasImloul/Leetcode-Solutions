class Solution 
{
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) 
    {
        List<Boolean> list = new ArrayList<>();
        
        int n = s.length();
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
                count += (map[r+1][i] - map[l][i]) % 2;
            
            list.add(count/2 <= k);
        }
        
        return list;
    }
}
