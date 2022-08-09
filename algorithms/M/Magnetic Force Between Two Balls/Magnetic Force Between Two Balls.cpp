class Solution {
public:
    bool isPossible(vector<int>& position, int m,int mid){
        long long int basketCount=1;
        int lastPos=position[0];
        for(int i=0;i<position.size();i++){
            if((position[i]-lastPos)>=mid){
                basketCount++;
                lastPos=position[i];
            }
        }
        return basketCount>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        long long int start=1;
        long long int end=position[n-1]-position[0];
        int ans=0;
        int mid= start+(end-start)/2;
        while(start<=end){
            if(isPossible(position,m,mid)){
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
           mid= start+(end-start)/2; 
        }
        return ans;
    }
};