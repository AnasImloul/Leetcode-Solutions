class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        //moving num2 on num1
        
        int ptr2 = 0;
        
        int cnt = 0;
        
        int largest  = INT_MIN;
        
        for(int i=0;i<n1;i++)
        {
            cnt = 0;
            for(int j=i,ptr2=0;j<n1 && ptr2<n2;j++,ptr2++)
            {
                if(nums1[j]==nums2[ptr2])
                {
                    cnt++;
                    
                }
                else
                {
                    cnt = 0;
                }
                largest = max(largest,cnt);
            }
        }
        
        //moving num1 on num2
        ptr2 = 0;
        cnt = 0;
        for(int i=0;i<n2;i++)
        {
            cnt = 0;
            for(int j=i,ptr2=0;j<n2 && ptr2<n1;j++,ptr2++)
            {
                if(nums2[j]==nums1[ptr2])
                {
                    cnt++;
                }
                else
                {
                    cnt = 0;
                }
                largest = max(largest,cnt);
            }
        }
        
        return largest;
        
    }
};