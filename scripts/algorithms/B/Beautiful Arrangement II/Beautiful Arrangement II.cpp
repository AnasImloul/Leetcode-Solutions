// Runtime: 0 ms (Top 100.0%) | Memory: 7.80 MB (Top 40.6%)

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int diff = n - k;
        int lo = 1;
        int hi = n;
        vector<int> out;
        int i = 0; 
		// we generate a difference of 1 between subsequent elements for the first n-k times.
        while(i < diff){
            out.push_back(lo);
            lo++;
            i++;
        }
        bool flag = true;
		//Now we go zig zag to generate k unique differences, the last one will be automatically taken care
		//as the difference between last two elements will be one which we have already generated above.
        for(int i = out.size()   ; i < n ; i++){
           //flag to alternatively zig zag
		   if(flag){
                out.push_back(hi);
                hi--;
                flag = false;
            }
            else{
                out.push_back(lo);
                lo++;
                flag = true;
            }
        }
        return out;
    }
};