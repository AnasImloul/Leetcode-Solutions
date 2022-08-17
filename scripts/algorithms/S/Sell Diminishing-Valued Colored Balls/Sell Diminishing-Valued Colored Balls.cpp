#define ll long long
const int MOD = 1e9+7; 

class Solution {
public:
    
    ll summation(ll n) {
        return (n*(n+1)/2);
    }
    
    int maxProfit(vector<int>& inventory, int orders) {
        ll n = inventory.size(), i = 0, ans = 0;
        inventory.push_back(0);
        sort(inventory.rbegin(), inventory.rend());
        while(orders and i < n) {
            if(inventory[i] != inventory[i+1]) {
                ll width = i+1, h = inventory[i] - inventory[i+1];
                ll available = width * h, gain = 0;
                if(available <= orders) {
                    orders -= available;
					// from each of the first i+1 inventories, we gain (inventory[i+1] + 1) + ... + inventory[i] value
                    gain = (width * (summation(inventory[i]) - summation(inventory[i+1]))) % MOD; 
                } else {
                    ll q = orders / width, r = orders % width;
					// q balls picked from each of the first i+1 inventories
                    gain = (width * (summation(inventory[i]) - summation(inventory[i]-q))) % MOD;
					// 1 ball picked from r inventories providing value (inventory[i]-q)
                    gain = (gain + r*(inventory[i]-q)) % MOD;
                    orders = 0;
                }
                
                ans = (ans + gain) % MOD; 
            }
            
            i++;
        }
        
        return ans;
    }
};
