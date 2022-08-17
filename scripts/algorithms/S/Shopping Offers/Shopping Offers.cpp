/* Note: This code results in a Timeout. */
class Solution {
public:
    int n, c;
    vector<int> dp;
    int compute(const vector<int> &price, const vector<vector<int>> &offers, int needs){
        if(dp[needs] != -1) return dp[needs];
        // Compute the min cost to satisfy these needs
        int best{}, new_needs, i;
        for(int i=0; i<n; i++){
            c = ((needs>>(i*4))&0xf);
            best += c * price[i];
        }
        if(best == 0) return 0;
        for(const vector<int> &offer : offers){
            new_needs = 0;
            for(i=0; i<n; i++){
                c = ((needs>>(i*4))&0xf);
                if(c >= offer[i]) new_needs |= ((c-offer[i])<<(i*4));
                else break;
            };
            if(i == n) best = min(best, compute(price, offers, new_needs) + offer.back());
        }
        return dp[needs] = best;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dp.resize((1<<24)+10, -1);
        n = needs.size();
        int needs_hash{};
        for(int i=0; i<n; i++) needs_hash |= ((needs[i])<<(i*4));
        return compute(price, special, needs_hash);
    }
};
