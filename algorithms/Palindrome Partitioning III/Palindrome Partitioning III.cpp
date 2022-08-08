class Solution {
public:

	int dp[105][105];
	/// Count Number of changes to be done
	/// to make substring of s from i to j 
	/// to palindrome
	int changes(int i , int j , string& s){
		int cnt = 0;
		while(i < j){
			cnt += (s[i++] != s[j--]);
		}
		return cnt;
	}

	int recur(int idx, int k, string &s){

		/// If Reached end of s and found partions to be done 0
		/// return 0 , otherwise return INT_MAX/any big number
		if(idx == s.size()){
			return (k == 0) ? 0 : 1e7;
		}

		/// Partitions to be done have completed , but
		/// we are not at the end of the string 
		/// return INT_MAX/any big number
		if(k == 0){
			return 1e7;
		}

		if (dp[idx][k] != -1){
			return dp[idx][k];
		}

		/// Partitioning the String
		int ans = INT_MAX;
		for (int i = idx ; i < s.size() ; i++){
			ans = min(ans , changes(idx , i , s) + recur(i + 1, k - 1, s));
		}
		return dp[idx][k] = ans;
	}

	int palindromePartition(string s, int k) {

		/// Edge Case
		if(k == s.size()){
			return 0;
		}
		memset(dp , -1 , sizeof(dp));
		return recur(0 , k , s);
	}

};