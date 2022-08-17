class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        Arrays.sort(citations);
        for(int i = 0; i < n; i++) {
            int hlen = (n-1) - i + 1;
            if(citations[i] >= hlen) {
                return hlen;
            }
        }
        return 0;
    }
}
