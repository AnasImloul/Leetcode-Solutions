// Runtime: 64 ms (Top 46.55%) | Memory: 48.10 MB (Top 75.28%)

class Solution {
public List<String> findAllConcatenatedWordsInADict(String[] words) {
 //sort the array in asc order of word length, since longer words are formed by shorter words.
 Arrays.sort(words, (a,b) -> a.length() - b.length());

  List<String> result = new ArrayList<>();

  //list of shorter words 
  HashSet<String> preWords = new HashSet<>();

  for(int i=0; i< words.length; i++){
      //Word Break-I problem.
      if(topDown(words[i], preWords, 0, new Boolean[words[i].length()])) {
          result.add(words[i]);
      }
      preWords.add(words[i]);
  }
  return result;
 }

private boolean topDown(String s, HashSet<String> wordDict, int startIndex, Boolean[] memo) {
 if(wordDict.isEmpty()) {
     return false;
 }
 // if we reach the beyond the string, then return true
 // s = "leetcode" when "code" is being checked in the IF() of the loop, we reach endIndex == s.length(), 
 // and wordDict.contains("code") => true and topDown(s, wordDict, endIndex, memo) needs to return true. 
 if(startIndex == s.length()) {
     return true;
 }
 
 // memo[i] = true means => that the substring from index i can be segmented. 
 // memo[startIndex] means => wordDict contains substring from startIndex and it can be segemented.
 if(memo[startIndex] != null) { //Boolean[] array's default value is "null"
     return memo[startIndex];
 }
 
 for(int endIndex = startIndex + 1; endIndex <= s.length(); endIndex++) {
     if(wordDict.contains(s.substring(startIndex, endIndex)) && topDown(s, wordDict, endIndex, memo)) {
         memo[startIndex] = true;
         return true;
     }
 }
 memo[startIndex] = false;
 return false;
}
} 
