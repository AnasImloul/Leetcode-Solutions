class Solution {
public:
    bool isPossible(vector<int> weights, int mid, int days){
        int day=1, sum=0; //minimum day and weight
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > mid){
                day++; sum = weights[i];
            }
        }
        
        //for mid(weight) how much day it is taking? at next step we reduce wt if this is possible
        return day <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = *max_element(weights.begin(), weights.end()),
            total_weight = accumulate(weights.begin(), weights.end(), 0),
            least_weight;// final Answer
        
        //base case
        if(weights.size() == days) return max_weight;
        
        //search for minimum weight
        while(max_weight <= total_weight){
            //weight to be shipped at a time (candidate)
            int mid = max_weight + (total_weight - max_weight)/2;
            
            //function to know if we can allocate this weight(mid) to satisfy condition?
            if(isPossible(weights, mid, days)){
                least_weight = mid;
                
                //to find minimum weight ever after we find a possible candidate
                total_weight = mid -1;
            }
            else max_weight = mid +1; 
        }
        return least_weight;
    }
};
