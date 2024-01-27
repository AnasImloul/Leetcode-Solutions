// Runtime: 0 ms (Top 100.0%) | Memory: 41.60 MB (Top 23.65%)

class Solution {
    public char repeatedCharacter(String s) {
        HashSet<Character> set = new HashSet<>();//Create a set of characters
        for(int i = 0 ; i < s.length() ; i++){
            if(set.contains(s.charAt(i))) return s.charAt(i);//If the set already contains the current character, then it is the required ans
            set.add(s.charAt(i));
        }
        return 'a';//As it is given in the question that there is at least one letter that appears twice, therefore it is certain that the ans will be found before we reach this statement. So, just adding any random return statement so that there is no error in the code.
    }
}
