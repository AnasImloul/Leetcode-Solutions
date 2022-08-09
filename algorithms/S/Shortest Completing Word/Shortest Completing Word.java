class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words)     {
        HashMap<Character,Integer> plate = new HashMap<Character,Integer>();
        ArrayList<String> ans = new ArrayList<>();
        String str = licensePlate.toLowerCase();
        for(int i=0;i<licensePlate.length();i++)
        {
            char c = str.charAt(i);
            if(c>='a' && c<='z')
            {
                if(plate.containsKey(c))
                {
                    plate.put(c,plate.get(c)+1);
                }
                else
                {
                    plate.put(c,1);
                }
            }
        }
        
            
        for(int i=0;i<words.length;i++)
        {
            String s = words[i].toLowerCase();
            HashMap<Character,Integer> wordHash = new HashMap<>();
            
            for(int j=0;j<words[i].length();j++)
            {
                char c = words[i].charAt(j);
                if(wordHash.containsKey(c))
                {
                    wordHash.put(c,wordHash.get(c)+1);
                }
                else
                {
                    wordHash.put(c,1);
                }
            }
            
            int count = 0;
            
            for(Map.Entry<Character,Integer> t:plate.entrySet())
            {
                if(wordHash.containsKey(t.getKey()))
                {
                    if(wordHash.get(t.getKey())>=t.getValue())
                    {
                        count++;
                    }
                }
            }
            
            if(count==plate.size())
            {
                ans.add(words[i]);
            }
            
        }
        
        Comparator<String> stringLengthComparator = new Comparator<String>()
        {
            @Override
            public int compare(String o1, String o2)
            {
                return Integer.compare(o1.length(), o2.length());
            }
        };
        
        Collections.sort(ans, stringLengthComparator);
        
        return ans.get(0);
    }
}
