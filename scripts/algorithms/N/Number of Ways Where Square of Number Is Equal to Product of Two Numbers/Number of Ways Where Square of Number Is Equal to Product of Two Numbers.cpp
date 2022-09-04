// Runtime: 255 ms (Top 49.82%) | Memory: 34.9 MB (Top 21.03%)
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<long, int> m1, m2;
        for(int i : nums1) m1[(long long)i*i]++;
        for(int i : nums2) m2[(long long)i*i]++;

        int ans = 0;

        for(int i=0; i<nums2.size()-1; i++){
            for(int j=i+1; j<nums2.size(); j++){
                if(m1[(long long)nums2[i] * nums2[j]]){
                    ans += m1[(long long)nums2[i] * nums2[j]];
                }
            }
        }
        for(int i=0; i<nums1.size()-1; i++){
            for(int j=i+1; j<nums1.size(); j++){
                if(m2[(long long)nums1[i] * nums1[j]]){
                    ans += m2[(long long)nums1[i] * nums1[j]];
                }
            }
        }
        return ans;
    }
};