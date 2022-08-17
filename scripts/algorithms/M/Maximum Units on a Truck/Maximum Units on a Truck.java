class Solution {
	public int maximumUnits(int[][] boxTypes, int truckSize) {
		Arrays.sort(boxTypes, Comparator.comparingInt(o -> -o[1]));
		int ans = 0, i = 0, n = boxTypes.length;
		while (i < n && truckSize > 0) {
			int maxi = Math.min(boxTypes[i][0], truckSize);
			ans += maxi * boxTypes[i][1];
			i++;
			truckSize -= maxi;
		}
		return ans;
	}
}