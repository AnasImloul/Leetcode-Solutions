// Runtime: 0 ms (Top 100.0%) | Memory: 41.30 MB (Top 77.37%)

class Solution {
    public String truncateSentence(String s, int k) {
        int n = s.length();
        int count = 0;
        int i = 0;
        while(i<n){
            if(s.charAt(i)==' '){
                count++;
                if(count==k) 
                    return s.substring(0,i);
            }
            i++;
        }
        return s;
    }
}
