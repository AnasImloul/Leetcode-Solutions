class Solution {
	public int longestSubstring(String s, int k) {
		int n=s.length();
		if(n==0 || k>n)return 0;
		if(k<=1) return n;
		HashMap<Character,Integer> map=new HashMap<>();
		for(char x:s.toCharArray())
			map.put(x,map.getOrDefault(x,0)+1);
		int low=0;
		while(low<n && map.get(s.charAt(low))>=k)low++;
		if(low>=n-1)return low;
		int left=longestSubstring(s.substring(0,low),k);
		while(low<n && map.get(s.charAt(low))<k)low++;
		 int right=(low < n) ? longestSubstring(s.substring(low), k) : 0;
		return Math.max(left,right);

}
