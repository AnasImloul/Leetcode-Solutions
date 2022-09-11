// Runtime: 2 ms (Top 90.24%) | Memory: 43 MB (Top 54.79%)
class Solution {
    public boolean buddyStrings(String s, String goal) {
        char a = '\u0000', b = '\u0000';
        char c = '\u0000', d = '\u0000';
        int lenS = s.length();
        int lenGoal = goal.length();
        boolean flag = true;
        HashSet<Character> hset = new HashSet<>();

        if(lenS != lenGoal)
            return false;

        if(s.equals(goal)){
            for(int i = 0; i < lenS; i++){
                if(!hset.contains(s.charAt(i))){
                    hset.add(s.charAt(i));
                }
                else
                    return true;
            }
            return false;
        }
        else{
            for(int i = 0; i < lenS; i++){
                if(s.charAt(i) == goal.charAt(i)){
                    continue;
                }
                if(a == '\u0000'){
                    a = s.charAt(i);
                    c = goal.charAt(i);
                    continue;
                }
                if(b == '\u0000'){
                    b = s.charAt(i);
                    d = goal.charAt(i);
                    continue;
                }
                return false;
            }

            if(a == d && c == b && a != '\u0000')
                return true;

            return false;
        }
    }
}