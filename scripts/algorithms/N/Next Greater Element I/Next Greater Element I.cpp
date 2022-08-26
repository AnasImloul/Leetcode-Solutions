// Runtime: 13 ms (Top 39.43%) | Memory: 8.9 MB (Top 32.91%)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vc;
        int len1=nums1.size();
        int len2=nums2.size();
        unordered_map<int,int>ump;
        int e,f;
        for(e=0;e<len2;e++)
        {
            for(f=e+1;f<len2;f++)
            {
                if(nums2[f]>nums2[e])
                {
                    ump[nums2[e]]=nums2[f];
                    break;
                }

            }
            if(f==len2) ump[nums2[e]]=-1;

        }
        unordered_map<int,int>::iterator it;
        for(int e=0;e<len1;e++)
        {
            it=ump.find(nums1[e]);
            if(it!=ump.end())
            {
                vc.push_back(it->second);
            }
        }

        return vc;

    }
};