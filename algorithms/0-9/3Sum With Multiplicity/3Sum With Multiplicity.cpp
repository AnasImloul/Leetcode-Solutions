class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans = 0;
        int MOD = pow(10, 9) + 7;
        
        // step 1: create a counting array;
        vector<long long> counting(101); // create a vector with size == 101;
        
        for(auto &value : arr) counting[value]++; // count the number;
        
        // step 2: evaluate all cases: x, y, z;
        // case 1: x != y != z;
        for(int x_idx = 0; x_idx < counting.size() - 2; x_idx++){
            if(counting[x_idx] < 1) continue;
            
            int target_tmp = target - x_idx;
            for(int y_idx = x_idx + 1; y_idx < counting.size() - 1; y_idx++){
                if(counting[y_idx] < 1) continue;
                
                if(target_tmp - y_idx <= 100 && target_tmp - y_idx > y_idx){
                    ans += counting[x_idx] * counting[y_idx] * counting[target_tmp - y_idx];
                    ans %= MOD;
                }
            }
        }
        
        // case 2: x == y != z;
        for(int x_idx = 0; x_idx < counting.size() - 1; x_idx++){
            if(counting[x_idx] < 2) continue;
            
            int target_tmp = target - 2 * x_idx;
            if(target_tmp <= 100 && target_tmp > x_idx){
                ans += counting[x_idx] * (counting[x_idx] - 1) / 2 * counting[target_tmp];
                ans %= MOD;
            }
        }
        
        // case 3: x != y == z;
        for(int x_idx = 0; x_idx < counting.size() - 1; x_idx++){
            if(counting[x_idx] < 1) continue;
            
            int target_tmp = target - x_idx;
            if(target_tmp %2 != 0) continue;
            
            if(target_tmp/2 <= 100 && target_tmp/2 > x_idx && counting[target_tmp/2] > 1){
                ans += counting[x_idx] * counting[target_tmp/2] * (counting[target_tmp/2] - 1) / 2;
                ans %= MOD;
            }
        }
        
        // case 4: x == y == z;
        for(int x_idx = 0; x_idx < counting.size(); x_idx++){
            if(counting[x_idx] < 3) continue;
            
            if(x_idx * 3 == target){
                ans += counting[x_idx] * (counting[x_idx] - 1) * (counting[x_idx] - 2) / 6;
                ans %= MOD;
            }
        }
        
        return ans;
    }
};
