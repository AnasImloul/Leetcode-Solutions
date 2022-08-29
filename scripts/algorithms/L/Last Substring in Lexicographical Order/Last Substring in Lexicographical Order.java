// Runtime: 27 ms (Top 54.24%) | Memory: 57.7 MB (Top 33.05%)
class Solution {

public String lastSubstring(String s) {
int maxIndex = s.length() - 1;

for(int currIndex = s.length() - 1 ; currIndex >= 0 ; currIndex--){
    if(s.charAt(currIndex) > s.charAt(maxIndex))
        maxIndex = currIndex;

    else if(s.charAt(currIndex) == s.charAt(maxIndex)){
        int i = currIndex + 1;
        int j = maxIndex + 1;

        while(i < maxIndex && j < s.length() && s.charAt(i) == s.charAt(j)){
            i++;
            j++;
        }

        if(i == maxIndex || j == s.length() || s.charAt(i) > s.charAt(j))
            maxIndex = currIndex;
    }
}

return s.substring(maxIndex);
}
}