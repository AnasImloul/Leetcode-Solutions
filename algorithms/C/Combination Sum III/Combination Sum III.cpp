class Solution {
public:
    vector<vector<int>> ans;
    //declare temp global vector in this vector we will store temprary combinations
    vector<int> temp;
    void solve(int k,int n,int order){
        //check if our target became zero and combination size became zero then push temp vector inside the ans it means this temp vector combination having sum is equal to target and size of vector is equal to k
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        //check if our target is less than zero then return 
        if(n<0) return;
         // take for loop and check for all posibility ahead of order
        for(int i=order;i<=9;i++){
            //push current index value
            temp.push_back(i);
            // call solve function for further posiblity
            solve(k-1,n-i,i+1);
            //Pop last push value 
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,1);
        return ans;
    }
};
