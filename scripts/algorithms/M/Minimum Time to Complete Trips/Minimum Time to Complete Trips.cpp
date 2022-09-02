// Runtime: 736 ms (Top 18.65%) | Memory: 94.5 MB (Top 68.73%)
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long anstillnow=-1;

        long long left=1, right= 100000000000001; //can also write this as 1+1e14

        while(left<=right){
            long long mid= left+ (right-left)/2; // find mid point like this to avoid overflow
            long long curr_trips=0;
            for(int t: time){
                curr_trips+= mid/t;
            }

            if(curr_trips>=totalTrips){
                anstillnow=mid;
                right=mid-1;
            }

            else{
                left=mid+1;
            }
        }

        return anstillnow;
    }
};