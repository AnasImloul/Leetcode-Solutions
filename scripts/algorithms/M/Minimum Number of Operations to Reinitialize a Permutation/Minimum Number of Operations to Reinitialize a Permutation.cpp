// Runtime: 55 ms (Top 25.45%) | Memory: 44.9 MB (Top 5.73%)
class Solution {
public:
    vector<int> change(vector<int>arr,vector<int>v){
        int n=v.size();
         for(int i=0;i<n;i++){
            if(i%2==0){
                arr[i]=v[i/2];
            }
            else{
                arr[i]=v[(n/2) + ((i-1)/2) ];
            }
        }
        return arr;
    }
    int reinitializePermutation(int n) {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=i;
        }
        vector<int>arr(n);

        arr=change(arr,v);
        if(arr==v){return 1;}

        int cnt=1;

        while(arr!=v){
            arr=change(arr,arr);
            cnt++;
            if(arr==v){return cnt;}

        }
        return cnt;
    }
};