class Solution 
{
    static int mod=(int)(1e9+7);
   public static int dfs(int n,ArrayList<ArrayList<Integer>> arr,int src,int dp[][])
   {
       if(n==0)
       {
           return 1;
       }
       if(dp[n][src]!=-1)
       {
           return dp[n][src];
       }
       int val=0;
    for(Integer ap:arr.get(src))
    {
         val=(val%mod+dfs(n-1,arr,ap,dp)%mod)%mod;
    }
       return dp[n][src]=val;
   }
   public static void val(ArrayList<String> arr,int color,int m,String s)
    {
        if(m==0)
        {
            arr.add(s);
            return;
        }
       for(int i=0;i<3;i++)
       {
           if(color!=i)
           val(arr,i,m-1,s+i);
       }
    }
    public static boolean Match(String s,String s1)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==s1.charAt(i))
            {
                return false;
            }
        }
        return true;
    }
    public int colorTheGrid(int m, int n)
    {
        ArrayList<String> arr=new ArrayList<String>();
        for(int i=0;i<3;i++)
        {
            String s="";
            val(arr,i,m-1,s+i);
        }
        ArrayList<ArrayList<Integer>> adj=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<arr.size();i++)
        {
            adj.add(new ArrayList<Integer>());
        }
    
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(Match(arr.get(i),arr.get(j)))
                {
                    adj.get(i).add(j);
                }
            }
        }
  int dp[][]=new int[n+1][adj.size()+1];
        for(int i=0;i<=n;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        int sum12=0;
        for(int i=0;i<arr.size();i++)
        {
                 sum12=(sum12%mod+dfs(n-1,adj,i,dp)%mod)%mod;
        }
        return sum12;
       
    }
}