// Runtime: 3 ms (Top 96.48%) | Memory: 10.1 MB (Top 81.91%)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    int a = nums1.size();
    int b = nums2.size();

    int i=0,j=0;
    vector<int>res;

    while(i<a && j<b)
    {
        if(nums1[i] > nums2[j])
        {
            j++;
        }
        else if(nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return res;
}
};