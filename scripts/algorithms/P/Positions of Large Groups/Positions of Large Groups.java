// Runtime: 2 ms (Top 35.3%) | Memory: 44.08 MB (Top 18.5%)

class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        int count = 1;
        
        for (int i = 0; i < s.length() - 1; i++) {
            // Increment the count until the next element is the same as the previous element. Ex: "aaa"
            if (s.charAt(i) == s.charAt(i + 1)) {
                count++;
            } 
            // Add the first and last indices of the substring to the list when the next element is different from the previous element. Ex: "aaab"
            else if (s.charAt(i) != s.charAt(i + 1) && count >= 3) {
                // gives the starting index of substring
                tmp.add(i - count + 1);
                // gives the last index of substring 
                tmp.add(i);
                res.add(tmp);
                count = 1;
                tmp = new ArrayList<>();
            } 
            else {
                count = 1;
            }
        }

        // Check for a large group at the end of the string. Ex: "abbb".
        if (count >= 3) {
            tmp.add(s.length() - count);
            tmp.add(s.length() - 1);
            res.add(tmp);
        }

        return res;
    }
}
