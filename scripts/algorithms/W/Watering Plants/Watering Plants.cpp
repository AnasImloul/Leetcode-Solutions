class Solution {
public:
	int wateringPlants(vector<int>& plants, int capacity) {
		int result = 0;
		int curCap = capacity;

		for (int i=0; i < plants.size(); i++){
			if (curCap >= plants[i]){
				curCap -= plants[i];
				result++;    
			}
			else{
				result += i * 2 + 1;
				curCap = capacity - plants[i];
			}
		}
		return result;
	}
};
