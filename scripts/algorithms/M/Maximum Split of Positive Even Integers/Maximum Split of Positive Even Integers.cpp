// Runtime: 308 ms (Top 27.53%) | Memory: 40.6 MB (Top 11.24%)
class Solution {
public:
    using ll = long long;

    ll bs(ll low , ll high, ll fs){

        ll ans = 1;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(mid*(mid+1)>fs){
                high = mid-1; // If sum till index equal to 'mid' > fs then make high = mid-1
            }
            else if(mid*(mid+1)==fs){
                return mid; // If sum till index equal to 'mid == fs, return 'mid'
            }
            else{
                ans = mid; // If sum till index equal to 'mid' < fs, update answer
                low = mid+1; // check for better answer
            }
        }
        return ans;
    }

    vector<long long> maximumEvenSplit(long long finalSum) {
        // ****some base cases / corner cases****
        if(finalSum&1) return {};
        if(finalSum==4) return {4};
        if(finalSum==8) return {2,6};

        vector<ll> ans;

        // assume that we are giving indices to even numbers
        // EVEN NUMBERS -> 2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 ..............
        // THEIR INDICES-> 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 ..............

        // 'idx' is the index of that EVEN number uptil which the total sum of all even numbers <= finalSum
        ll idx = bs(1,finalSum/2,finalSum);

        //Consequently, 'end' is that EVEN number uptil which the total sum of all even numbers <= finalSum
        ll start = 2, end = idx*2;

        //Now, we add all the even numbers from index 1 to index 'idx-1'
        // 2 + 4 + 6 + 8 ........................... + (end-2) + end
        // 1 2 3 4 ........................... idx-1 idx
        for(int i = start; i<= (idx-1)*2; i+=2){
            ans.push_back(i);
        }

        // We do not add the last even number yet, so that we can modify it and add it later to make the (totalSumSoFar) == finalSum
        // 'totalSumSoFar' can be easily calculated by using the formula ( totalSumSoFar = idx*(idx+1) )

        // increasing the last even number 'end' by the difference of (finalSum and totalSumSoFar)
        if(idx*(idx+1)<finalSum){
            end = end + abs(finalSum - idx*(idx+1));
        }

        // adding the last even number after increasing it with the required factor
        ans.push_back(end);
        return ans;
    }
};