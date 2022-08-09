class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(MaxValOfA1(nums1,nums2), MaxValOfA1(nums2,nums1));
    }
    
    int MaxValOfA1(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        int sum = 0;
        for(auto &i:a1) sum+=i;
        int L=0, R=0, max_inc=0;
		//max_inc is maximum positive contribution of a1
        int acc1 = 0, acc2 =0;
        while(L<n && R<n) {
            acc1 += a1[R];
            acc2 += a2[R];
            max_inc = max(max_inc, acc2-acc1);
            if(acc1>=acc2) {
                L=R+1;
                R=L;
                acc1=0;
                acc2=0;
            } else {
                R=R+1;
            }
        }
        return sum + max_inc;
    }
};
