// Runtime: 117 ms (Top 97.32%) | Memory: 56.20 MB (Top 42.83%)

//149ms

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        HashMap<String,Integer> wordMap = new HashMap<>();
        Set<Integer> set = new TreeSet<>();
        int n = words.length;
        
        for(int i=0;i<n;i++){
            wordMap.put(words[i],i);
            set.add(words[i].length());
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        
        for(int i=0;i<n;i++){
            int length = words[i].length();
            
            // if(length ==1){
            //     if(wordMap.containsKey("")){
            //         ans.add(Arrays.asList(i, wordMap.get("")));
            //         ans.add(Arrays.asList(wordMap.get(""), i));
            //     }
            //     continue;
            // }
            String reverse= new StringBuilder(words[i]).reverse().toString();
            if(wordMap.containsKey(reverse) && wordMap.get(reverse) != i)
                ans.add(Arrays.asList(i,wordMap.get(reverse)));
            
            for(Integer k:set){
                if(k==length)
                    break;
                if(isPalindrome(reverse,0,length-1-k)){
                    String s1 = reverse.substring(length-k);
                    if(wordMap.containsKey(s1))
                        ans.add(Arrays.asList(i,wordMap.get(s1)));
                }
                
                if(isPalindrome(reverse,k,length-1)){
                    String s2 = reverse.substring(0,k);
                    if(wordMap.containsKey(s2))
                        ans.add(Arrays.asList(wordMap.get(s2),i));
                }
            }
        }
        return ans;
    }
    
    private boolean isPalindrome(String s, int left, int right){
        while(left<right)
            if(s.charAt(left++)!=s.charAt(right--))
                return false;
        return true;
    }
}
