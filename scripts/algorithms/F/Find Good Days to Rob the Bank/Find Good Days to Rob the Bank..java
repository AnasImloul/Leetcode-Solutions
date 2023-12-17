// Runtime: 12 ms (Top 6.78%) | Memory: 59.90 MB (Top 5.93%)

class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        List<Integer> res = new ArrayList<>();
        if (time == 0) {
            for (int i = 0; i < security.length; i++) res.add(i);
            return res;
        }
        Set<Integer> set = new HashSet<>();
        int count = 1;
        for (int i = 1; i < security.length; i++) {
            if (security[i] <= security[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > time) {
                set.add(i);
            }
        }
        
        count = 1;
        for (int i = security.length - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > time && set.contains(i)) res.add(i);
        }
        return res;
    }
}
