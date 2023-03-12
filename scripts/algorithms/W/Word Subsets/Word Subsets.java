class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> list=new ArrayList<>();
        int[] bmax=count("");
        for(String w2:words2)
        {
            int[] b=count(w2);
            for(int i=0;i<26;i++)
            {
                bmax[i]=Math.max(bmax[i],b[i]);
            }
        }
        for(String w1:words1)
        {
            int[] a=count(w1);
            for(int i=0;i<26;i++)
            {
                if(a[i]<bmax[i])
                {
                    break;
                }
                  if(i==25)
             {
                 list.add(w1);
             }
            } 
        }
        return list;
    }
    public int[] count(String s)
    {
        int[] ans=new int[26];
        for(char c:s.toCharArray())
        {
            ans[c-'a']++;
        }
        return ans;
    }
}