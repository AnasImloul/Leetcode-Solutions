class Solution 
{
	public:
	vector<int> findnumbers(int num)
	{
		int m=sqrt(num);
		while(num%m!=0)
		{
			m--;
		}
		return {num/m,m};
	}
	vector<int> closestDivisors(int num) 
	{
		vector<int> ans1=findnumbers(num+1);
		vector<int> ans2=findnumbers(num+2);
		if(abs(ans1[0]-ans1[1])<abs(ans2[0]-ans2[1]))
			return ans1;
		return ans2;
	}
};
