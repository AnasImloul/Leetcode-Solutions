// Runtime: 24 ms (Top 44.95%) | Memory: 10.4 MB (Top 6.64%)
class Solution {
public:
    int count(vector<int> &temp,int mid){
        int i=0,j=0,n=temp.size();
        int len=0;

        while(i<n){
            while(j<n && (temp[j]-temp[i])<=mid) j++;
            len+=j-i-1;
            i++;
        }
        return len;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int s=0,e=1e6;
        int ans=0;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        while(s<=e){
            int mid=s+(e-s)/2;

            if(count(temp,mid)>=k){
                ans=mid;
                e=mid-1;
            }else {
                s=mid+1;
            }
        }
        return ans;
    }
};