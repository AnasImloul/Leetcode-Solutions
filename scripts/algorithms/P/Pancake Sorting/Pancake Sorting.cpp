class Solution {
private:
    void reverse(vector<int>&arr,int start,int end){
        while(start<end){
            swap(arr[start++],arr[end--]);
        }
    }
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>copy=arr;
        sort(copy.begin(),copy.end());
        int end=copy.size()-1;
        vector<int>ans;
        while(end>0){
            if(arr[end]!=copy[end]){
                int pos=end-1;
                while(arr[pos]!=copy[end]){
                    pos--;
                }
                reverse(arr,0,pos);
                if(pos!=0){
                    ans.push_back(pos+1);
                }
                reverse(arr,0,end);
                ans.push_back(end+1);
            }
            end--;
        }
        return ans;
    }
};