//comparator class for sorting restaurants by their rating 
class comp{
        public:
        bool operator ()(vector<int>a,vector<int>b){
		//same rating then sort by ids
                if(a[1]==b[1]) return a[0]>b[0];
                return a[1]>b[1];
        }
};
class Solution {
public:
        vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
		{ //sort restaurants by their rating
            sort(restaurants.begin(),restaurants.end(),comp());
            vector<int>ans;
            for(int i=0;i<restaurants.size();i++){
			//veganfriendly
                    if(veganFriendly)
					{
					// store ids who satisfy the constraints
                    if(restaurants[i][2]==veganFriendly and restaurants[i][3]<=maxPrice and  restaurants[i][4]<=maxDistance)
					        {
                            ans.push_back(restaurants[i][0]);
                            }
                    }
					// non vegan
                    else{
					// store ids who satisfy the constraints
                            if(restaurants[i][3]<=maxPrice and  restaurants[i][4]<=maxDistance)
							{
                            ans.push_back(restaurants[i][0]);
                            }
                    }
            }
         return ans;
    }
};
