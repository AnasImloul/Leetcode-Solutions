class Solution {
private:
	long long f(int row, int col, map<pair<int,int>,long long> &mp){

		//Base case is tackled in this line
		long long ans = mp[{row,col}]; 

		for(int i = 1;i < row;i++) //Partitions Row-wise
			ans = max(ans,f(i,col,mp) + f(row-i,col,mp));

		for(int j = 1;j < col;j++) //Partitions Column-wise
			ans = max(ans,f(row, j, mp) + f(row, col-j, mp));

		return ans;
	}
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {
		//Declaring the HashMap
		map<pair<int,int>,long long> mp;

		//Storing Prices in HashMap where {height,width} of wood is key and {Price} is value
		for(int i = 0;i < prices.size();i++)
			mp[{prices[i][0],prices[i][1]}] = prices[i][2];

		return f(m,n,mp);
	}
};
