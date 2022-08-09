typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;
        int no = 1;
        for (int x : nums1){
            mapping[x] = no;
            no++;
        }
        for (int i = 0; i < nums2.size(); ++i)
            nums2[i] = mapping[nums2[i]];
        int n = nums2.size();
        ordered_set st1;
        ordered_set st2;
        for (int x : nums2)
            st2.insert(x);
        ll ans = 0;
        st1.insert(nums2[0]);
        st2.erase(st2.find(nums2[0]));
        for (int i = 1; i < n - 1; ++i)
        {
            st2.erase(st2.find(nums2[i]));
            ll less = (ll)st1.order_of_key(nums2[i]);
            ll great = (ll) (((int)st2.size()) - st2.order_of_key(nums2[i]));
            ans += (less * great);
            st1.insert(nums2[i]);
        }
        return ans;
    }
};
