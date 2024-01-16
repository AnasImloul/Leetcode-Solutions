// Runtime: 26 ms (Top 92.47%) | Memory: 48.80 MB (Top 99.46%)

class Solution {
    public String largestWordCount(String[] messages, String[] senders) 
    {
        HashMap<String,Integer> map = new HashMap<>();
        String res = "";int max =0;
        
        for(int i=0; i<messages.length;i++)
        {
            int words = get_count(messages[i]);
            
            if(!map.containsKey(senders[i]))
               map.put(senders[i] , words);
               
            else
               map.put(senders[i],map.get(senders[i]) + words);
        }
        
        for(String s: map.keySet())
        {
            if(map.get(s) > max)
            {
                res = s;
                max = map.get(s);
            }
            
            if(map.get(s) == max && res.compareTo(s) < 0)
                res = s;
        }
        return res;
    }
    
    private int get_count(String s)
    {
        int spaces = 0;
        
        for(int i=0; i<s.length();i++)
        {
            char ch = s.charAt(i);
            if(ch == ' ')
                spaces++;
        }
        return spaces+1;
    }
}
