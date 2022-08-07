/*
    https://leetcode.com/problems/random-pick-with-weight/
    
    SOLUTION 1
    
    Precomputation
        TC: O(N)
        SC: O(n + 100) ~ O(n)
    Run-time: pickIndex()
        TC: O(1)
        SC: O(1)
    Since we want to randomly select an index but based on the weight / probability,
    we need to use the probability score in some way to do that.
    Maintain a vector that stores the index values of 'w' array.
    For each index, we can calculate the probability and then map it to [1, 100] count,
    then add that many entries to idx vector.
    Randomly pick a number, since we have put duplicate entries for each index based on the 
    weight, the probability of a index getting picked will depend on the no. of such elements in 
    the array and it will work as expected.
    
    
    SOLUTION 2: Binary Search
    
    Precomputation
        TC: O(N)
        SC: O(n)
    Run-time: pickIndex()
        TC: O(logn)
        SC: O(1)
    
    Since we want a way to account for the weight of individual index values,
    we can use cummulative sum for that. We store the cummulative sum of all the
    weight values. The idea behind cummulative sum is that for a w[i] that has more weight, it will cover more numbers
    hence a random number has more chances of falling in that range.
    Eg: [1, 5, 3] => cumm_sum = [1, 6, 9]
    index 0 covers [1, 1] => covers 1 number
    index 1 covers [2, 6] => covers 5 numbers
    index 2 covers [7, 9] => covers 3 numbers
    
    As evident, index 1 has weight = 6 and subsequently covers most numbers as well.
    Next we generate a random number in [min_value_cumm_sum, max_value_cumm_sum] range.
    Using binary search find the 1st position where it should lie. 
*/
/////////////////////////////////////////// SOLUTION 1 ////////////////////////////////////

class Solution {
private:
    // stores the index value of w array
    vector<int> idx;
    // For generating random numbers in range(0, index_array_size)
    random_device rd;
    uniform_int_distribution<int> dist;
    
public:
    Solution(vector<int>& w) {
        // Total sum of all the weights
        long long sum = accumulate(w.begin(), w.end(), 0);
        
        for(int i = 0; i < w.size(); i++) {
            // Convert the probability score to a natural number, this will be [0, 100]
            int prob_score = round((double)w[i] / sum * 100);
            // If prob_score = 0.00001, then round(prob_score)  = 0, so we give min value of 1
            // so that atleast one entry for the index is inserted
            int prob = max(1, prob_score);
            // For the current index based on the weight, we add that many entries in the 
            // idx array
            vector<int> chance(prob, i);
            idx.insert(idx.end(), chance.begin(), chance.end());
        }
        // set the random distribution's range
        dist = uniform_int_distribution<int>(0, idx.size() - 1);
    }
    
    int pickIndex() {
        // we randomly generate an index from the index array and then return the index
        // value stored there
        int index = dist(rd);
        return idx[index]; 
    }
};


/////////////////////////////////////////// SOLUTION 2: Binary Search ///////////////////////////////
class Solution {
private:
    // stores the cummulative sum of w array
    vector<int> cumm_sum;
    // For generating random numbers in range(0, index_array_size)
    random_device rd;
    uniform_int_distribution<int> dist;
    
public:
    Solution(vector<int>& w) {
        long long sum = 0;
        cumm_sum.resize(w.size(), 0);
        
        for(int i = 0; i < w.size(); i++) {
            sum += w[i];
            cumm_sum[i] = sum;
        }
        // set the random distribution's range: [1, Total_sum_of_w]
        dist = uniform_int_distribution<int>(1, sum);
    }
    
    // Returns the 1st position where the element should be inserted
    int binarySearch(int num) {
        int low = 0, high = cumm_sum.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(cumm_sum[mid] == num)
                return mid;
            else if(cumm_sum[mid] > num) 
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
    
    int pickIndex() {
        // we randomly generate a number from the cumm_sum array and then search the index
        // value using binary search. For a w[i] that has more weight, it will cover more numbers
        // hence a random number has more chances of falling in that range. We find the 1st position where that number
        // can lie. 
        int random_index = dist(rd);
        int index = binarySearch(random_index);
        return index; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
