						// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		// resultant string
        vector<string> result;
        
        int n = nums.size();
		// if size happens to be  zero return empty string
        if(n == 0 )
                return result;
        
		// assigning first element to a
        int a = nums[0];
        
        for(int i = 0; i<n; i++)
        {
			// if one of both is true
            if( i == n-1 || nums[i]+1 != nums[i+1])
            {
			    // if current element is not equals a
				// this means we have found a range.
                if(nums[i] != a)
                    result.push_back(to_string(a)+ "->"+ to_string(nums[i]));
					
				// this means we have reached to the end of string and now
				// we have to add a that should be the last element
                else
                        result.push_back(to_string(a));
						
				// checking  for this condition so that a got updated for next range
				// also n-1 so that a doesn't contain out of bound value
                if(i != n-1)
                    a = nums[i+1];
            }
        }
		// return result
        return result;
    }
};
