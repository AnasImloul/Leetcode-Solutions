// Runtime: 21 ms (Top 98.47%) | Memory: 61.2 MB (Top 91.95%)
class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int N = nums.length;
        List<Integer> res = new ArrayList<>();

        int[] pref = new int[N + 1];
        pref[0] = 0; // at zeroth division we have no elements
        for(int i = 0; i < N; ++i) pref[i+1] = nums[i] + pref[i];

        int maxScore = -1;
        int onesToRight, zeroesToLeft, currScore;

        for(int i = 0; i < N + 1; ++i) {
            onesToRight = pref[N] - pref[i];
            zeroesToLeft = i - pref[i];
            currScore = zeroesToLeft + onesToRight;

            if(currScore > maxScore) {
                res.clear();
                maxScore = currScore;
            }
            if(currScore == maxScore) res.add(i);
        }
        return res;
    }
}