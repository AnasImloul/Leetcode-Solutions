// Runtime: 1 ms (Top 80.43%) | Memory: 42.9 MB (Top 28.86%)
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int val=1;
        int[] alp = new int[26];

        for(int i=0;i<order.length();i++) {
            alp[order.charAt(i)-'a']=val;
            val++;
        }
        int flag=0; // if second string is shorter than first then this will be used to check if second is a subset of first starting from the beginning

        for(int i=0;i<words.length-1;i++) {
            flag=0;
            for(int j=0; j<words[i].length() && j<words[i+1].length(); j++) {
                if(words[i].charAt(j) == words[i+1].charAt(j)) {
                    continue;
                }
                if(alp[words[i].charAt(j)-'a'] > alp[words[i+1].charAt(j)-'a']) {
                    return false;
                } else if(alp[words[i].charAt(j)-'a'] < alp[words[i+1].charAt(j)-'a']) {
                    flag=1;
                    break;
                }
            }
            if(flag==0 && words[i].length()>words[i+1].length()) {
                return false; // if second word is sub string of first word starting from the beginning, return false.
            }
        }

        return true;
    }
}