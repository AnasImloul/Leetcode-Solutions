class Solution {
public:
	int f(int i,vector<int>& v, int a, int b){
		if(i==v.size()){
			if(a==b){
				return a;
			}
		  return 0;
		}

		int x = f(i+1,v,a,b);
		int y = f(i+1,v,a+v[i],b);
		int z = f(i+1,v,a,b+v[i]);

		return max({x,y,z});
	}
	int tallestBillboard(vector<int>& rods) {
		return f(0,rods,0,0);

	}
};
