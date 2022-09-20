// Runtime: 1458 ms (Top 5.16%) | Memory: 28.2 MB (Top 77.80%)
class Solution {
public:
    bool SlidingWindow(vector<int>&arr,int &th,int &k){
        if(arr.size()<k) return 0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int i=0;
        if(sum<=th) return 1;
        for(int j=k;j<arr.size();j++){
            sum-=arr[i];
            sum+=arr[j];
            if(sum<=th) return 1;
            i++;
        }
        return 0;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        //Sliding Window Fixed Size (c2-c1);
        //Time Complexity -> O(n^3);
        //Hmare Saath Shri Ragunath To Kis Baat Ki Chinta -> "Jai Shri Ram"
        int ans=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int c1=0;c1<n;c1++){
            vector<int>arr(m,0);
            for(int c2=c1;c2<n;c2++){
                for(int r=0;r<m;r++){
                    arr[r]+=mat[r][c2];
                }
                int x=c2-c1+1; // jo column ka size hoga vhi row ka hona chahiye
                if(SlidingWindow(arr,threshold,x)) ans=max(ans,x);
            }
        }
        return ans;
    }
};