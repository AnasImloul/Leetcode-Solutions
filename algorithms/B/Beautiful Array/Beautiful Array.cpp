class Solution {
public:
	vector<int> beautifulArray(int n) {

		vector<int> v = {1};

		while(v.size()<n)
		{
			vector<int> x;

			for(auto c:v)
			{
				if(c*2-1<=n)
				{
					x.push_back(c*2-1);
				}
			}

			for(auto d:v)
			{
				if(d*2<=n)
				{
					x.push_back(d*2);
				}
			}
			v=x;
		}

		return v;
	}
};