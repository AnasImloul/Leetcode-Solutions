// Runtime: 3 ms (Top 100.0%) | Memory: 44.50 MB (Top 53.43%)

class Solution {
  public int minimizedStringLength(String s) {
    var map = new boolean[26];
    var ans = 0;
    
    for (var c : s.toCharArray())
      map[c - 'a'] = true;

    for (var c : map) if (c) ans++;
    
    return ans;
  }
}
