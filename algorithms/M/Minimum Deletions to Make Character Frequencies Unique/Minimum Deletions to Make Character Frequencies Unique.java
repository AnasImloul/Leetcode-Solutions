class Solution {
    private int N = 26;
    public int minDeletions(String s) {
        int[] array = new int[N];
        for (char ch : s.toCharArray()) {
            array[ch - 'a']++;
        }
        int ans = 0;
        Set<Integer> set = new HashSet<>();
        for (int i : array) {
            if (i == 0) continue;
            while (set.contains(i)) {
                i--;
                ans++;
            }
            if (i != 0) {
                set.add(i);
            }
        }
        return ans;
    }
}
