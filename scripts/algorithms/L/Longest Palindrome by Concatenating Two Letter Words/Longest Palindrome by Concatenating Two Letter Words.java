// Runtime: 7 ms (Top 99.82%) | Memory: 57.9 MB (Top 94.96%)
class Solution {
  public int longestPalindrome(String[] words) {
    int[][] freq = new int[26][26];//array for all alphabet combinations
    for (String word : words)
      freq[word.charAt(0) - 'a'][word.charAt(1) - 'a']++;// here we first increase the freq for every word
    int left = 0;//to store freq counts
    boolean odd = false;
    for (int i = 0; i != 26; i++) {//iterate over our array
      odd |= (freq[i][i] & 1) == 1;//means odd number of freq for similar words are there
      left += freq[i][i] / 2;
      for (int j = i + 1; j != 26; j++)//nested iteration to find non similar pairs
        left += Math.min(freq[i][j], freq[j][i]);//taking min times from both present
    }
    int res = left * 2 * 2;//res from total freq found!!
    if (odd){
        res+=2;// if odd then adding 2
    }
    return res;
  }
}