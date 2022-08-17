class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int c=0;
        vector<int> v={-1,-1};
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==1)
                c++;
        }
        if(c%3!=0)return v;
        if(c==0)return {0,2}; //can make split from anywhere. this is in case we have 3 size of given array
        
        int idx=-1;
        int cnt=0;
        // start counting c/3 1s from back,so that we can make 3 equal parts
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==1)
                cnt++;
            if(cnt==c/3)
            {  idx=i;
             break;}
            
        }
        int front=0;  // ignoring leading 0s
        while(arr[front]==0)
            front++;
        
        int strt=idx;
        while(strt<n && arr[front]==arr[strt]){
            front++;
            strt++;
        }
        if(strt!=n)return v;
        int frststrt=front-1;
        while(arr[front]==0)front++;
        strt=idx;
        while(strt<n && arr[front]==arr[strt]){
            front++;
            strt++;
        }
         if(strt!=n)return v;
        return {frststrt,front};
        
    }
};
