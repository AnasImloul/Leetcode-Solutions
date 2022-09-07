// Runtime: 5 ms (Top 87.83%) | Memory: 46.8 MB (Top 47.53%)
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] ans = new int[queries.length];
        int[] freq = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            freq[i] = freqOfSmallest(words[i]);
        }
        Arrays.sort(freq);
        int k = 0;
        for (String query : queries) {
            int target = freqOfSmallest(query);
            ans[k++] = binarySearch(freq, target);
        }
        return ans;
    }
    public int freqOfSmallest(String s) {
        int[] freq = new int[26];
        char min = 'z';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq[c - 'a'] += 1;
            if (c < min) {
                min = c;
            }
        }
        return freq[min - 'a'];
    }
    public int binarySearch(int[] arr, int target) {
        int idx = arr.length;
        int lo = 0;
        int hi = idx - 1;
        int mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (arr[mid] <= target) {
                lo = mid + 1;
            } else {
                idx = mid;
                hi = mid - 1;
            }
        }
        return arr.length - idx;
    }
}