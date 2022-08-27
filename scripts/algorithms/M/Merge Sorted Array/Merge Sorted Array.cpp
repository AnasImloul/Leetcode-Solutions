// Runtime: 3 ms (Top 76.26%) | Memory: 9.3 MB (Top 30.17%)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(n+m);
        int i=0,j=0,k=0;
        while(i<m && j<n){ //select smaller element from both vector
            if(nums1[i]<nums2[j]){
                temp[k]=nums1[i];
                i++;
                k++;
            }
            else{
                temp[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<m){ //insert remaining nums1 element
            temp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n){ //insert remaining nums2 element
            temp[k]=nums2[j];
            j++;
            k++;
        }
        nums1=temp;
        return ;
    }
};