			class Solution {
			public:
				bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
				{
					if(k==0)
						return false;
					multiset<long> window;

					for(int i=0;i<nums.size();i++)
					{
						if(i>k)
							window.erase(nums[i-k-1]);
						auto it=window.lower_bound((long)nums[i]-(long)t);
						if(it!=window.end() && *it<=(long)nums[i]+(long)t)
							return true;
						window.insert(nums[i]);
					}
					return false;
				}
			};





			// class Solution {
			// public:
			//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
			//     {
			//         double x;
			//         for(int i=0;i<nums.size();i++)
			//         {
			//             for(int j=i+1;j<nums.size();j++)
			//             {
			//                 x=0.0+nums[i]-nums[j];
			//                 if(x<0)
			//                     x=-1*x;
			//                 if(i!=j && x<=t && abs(i-j)<=k)
			//                     return true;
			//             }
			//         }
			//         return false;
			//     }
			// };