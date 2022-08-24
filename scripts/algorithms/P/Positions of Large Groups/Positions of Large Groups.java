// Runtime: 3 ms (Top 46.85%) | Memory: 45.5 MB (Top 9.24%)
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> ans = new ArrayList<>();
        int count = 1;
        int si = -1;
        int i = 0;
        for (; i < s.length() - 1; i++) {
            char ch = s.charAt(i);
            if (ch == s.charAt(i + 1)) {
                if (si == -1) {
                    si = i;
                }
                count++;
            } else {
                if (count >= 3) {
                    ans.add(new ArrayList<Integer>(Arrays.asList(si, i)));
                }
                si = -1;
                count = 1;
            }
        }
        if (count >= 3) {
            ans.add(new ArrayList<Integer>(Arrays.asList(si, i)));
        }
        return ans;
    }
}