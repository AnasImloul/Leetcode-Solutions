// Runtime: 162 ms (Top 26.50%) | Memory: 73.1 MB (Top 21.04%)
class Solution {
    public boolean isScramble(String s1, String s2) {

        if(s1.length()!=s2.length())
            return false;

        return helper(s1,s2,new HashMap<>());
    }

    private boolean helper(String s1,String s2,HashMap<String,Boolean> memo){

        // is s1 and s2 equal return true BASE CASE
        if(s1.equals(s2))
            return true;

        //if length are not equal then s1 and s2 can't be scamble st any cost BASE CASE
        if(s1.length()!=s2.length())
            return false;

        String key = s1+"*"+s2;

        if(memo.containsKey(key))
            return memo.get(key);

        int n = s1.length();

        for(int i=1;i<n;i++){

            /*
                Example 1.
                s1 = gr|eat , s2 = eat|gr

                by swapping the strings s1 and s2 at patrition scrambled string can be formed
                check if s1's gr| is equal to s2's |gr
                and s1's |eat is equal to s2's eat| if yes then return true;

                Example 2.
                s1 = ca|r , s2 = ca|r

                these strings don't need swapping so we'll check if left partions are equal with each other and
                right partion are equal with each other

                Conclusion
                we'll check for both the conditions if either is true then our string is scramble

            */
            boolean swap = helper(s1.substring(0,i),s2.substring(n-i),memo) && helper(s1.substring(i),s2.substring(0,n-i),memo);

            boolean noSwap= helper(s1.substring(0,i),s2.substring(0,i),memo) && helper(s1.substring(i),s2.substring(i),memo);

            if(swap || noSwap){
                memo.put(key,true);
                return true;
            }
        }
        memo.put(key,false);

        return false;
    }
}