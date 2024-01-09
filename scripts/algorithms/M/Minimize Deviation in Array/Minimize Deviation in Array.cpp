// Runtime: 271 ms (Top 90.46%) | Memory: 89.40 MB (Top 17.18%)

// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set <int>  s;
        
        // Storing all  elements  in sorted order
        //insert even directly and odd with one time multiplication
        //and it will become even
        for(int i = 0; i<nums.size() ; ++i)
        {
            if(nums[i] % 2 == 0)
                s.insert(nums[i]);
            
            else
                // Odd number are transformed
                // using 2nd operation
                s.insert(nums[i] * 2);
        }
        
        // maximum - minimun
        int diff = *s.rbegin() - *s.begin();
        
        //run the loop untill difference is minimized
        while(*s.rbegin() % 2 == 0)
        {
            
            // Maximum element of the set
            int x = *s.rbegin();
            s.erase(x);
            // remove begin element and inserted half of it for minimizing
            s.insert(x/2);
            
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        return diff;
    }
};
