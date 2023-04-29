class Solution {
public:
	bool isPowerOfThree(int n) {
		if(n<=0){return false;}
		if(n>pow(2, 31)-1 || n<pow(2, 31)*(-1)){return false;}
		return 1162261467%n==0;
	}
};