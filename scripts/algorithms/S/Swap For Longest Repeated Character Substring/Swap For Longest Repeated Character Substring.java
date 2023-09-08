// Runtime: 14 ms (Top 27.8%) | Memory: 41.85 MB (Top 50.9%)

class Solution {
		public int maxRepOpt1(String s) {
		   int[] count = new int[26];
		   int[] left = new int[s.length()];
		   int[] right = new int[s.length()];
			int max =0;
			// Left Array Containing Length Of Subarray Having Equal Characters Till That Index
			for(int i=0;i<s.length();i++){
				count[s.charAt(i) -'a']++;
				if(i> 0){
					if(s.charAt(i) == s.charAt(i-1)){
						left[i] = left[i-1]+1;
					}else{
						left[i] = 1;
					}
				}else{
					left[i] =1;
				}
				max = Math.max(max,left[i]);
			}
			// Right Array Containing Length Of Subarray Having Equal Characters Till That Index
			for(int i=s.length()-1;i>=0;i--){
				if(i < s.length()-1){
					if(s.charAt(i+1) == s.charAt(i)){
						right[i] = right[i+1] +1;
					}else{
						right[i] =1;
					}
				}else{
					right[i] = 1;
				}
			}
			// Count The Length Of SubString Having Maximum Length When A Character Is Swapped
			for(int i=1 ; i<s.length()-1 ; i++){
				if(s.charAt(i-1) == s.charAt(i+1) && s.charAt(i) != s.charAt(i-1)){
					if(count[s.charAt(i-1) -'a'] == left[i-1] + right[i+1]){
						max = Math.max(max , left[i-1] + right[i+1]);
					}else{
						max = Math.max(max,left[i-1] + right[i+1]+1);
					}
				}else{
					if(count[s.charAt(i) -'a'] == left[i]){
						max = Math.max(max,left[i]);
					}
					else{
						max = Math.max(max,left[i]+1);
					}
				}
			}
			 if(count[s.charAt(s.length()-1)-'a']!=left[s.length()-1])
					{
						max = Math.max(max, left[s.length()-1]+1);
					}
		   return max; 
		}
	}
	