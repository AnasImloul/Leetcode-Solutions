class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& arr) {
		int sum=0;
		for(auto i : arr)
			sum+=i;
		if(sum%3!=0)
			return false;   //partition not possible
		int part=sum/3,temp=0,found=0;
		for(int i=0;i<arr.size();i++){
			temp+=arr[i];
			if(temp==part){
				temp=0;
				found++;
			}
		}
		return found>=3 ? true : false;
	}
};

feel free to ask your doubts :)
and pls upvote if it was helpful :)