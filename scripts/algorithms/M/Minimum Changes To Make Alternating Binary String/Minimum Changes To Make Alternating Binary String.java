// Runtime: 4 ms (Top 86.00%) | Memory: 41.7 MB (Top 99.33%)
class Solution {
    public int minOperations(String s) {
        int count0 = 0; // changes required when the string starts from 0
        int count1 = 0; // changes required when the string starts from 1

        for(int i = 0; i < s.length(); i++){

            // string starts with 1 => all chars at even places should be 1 and that at odd places should be 0
            if((i % 2 == 0 && s.charAt(i) == '0') || (i % 2 != 0 && s.charAt(i) == '1'))
                count1++;

            // string starts with 0 => all chars at even places should be 0 and that at odd places should be 1
            else if((i % 2 == 0 && s.charAt(i) == '1') || (i % 2 != 0 && s.charAt(i) == '0'))
                count0++;
        }

        // return minimum of the two
        return Math.min(count0, count1);
    }
}
