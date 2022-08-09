class Solution {
private:
    int mod=1e9+7;
    //stores the hat as the key and an array of the people who prefer it
    unordered_map<int,vector<int>>hatTable;
    //dp table defined by two variables:-
    //hat->the current hat number we are on
    //mask->is a bitmask which tells us which people have already been given a hat
    vector<vector<int>>mem;
    //every hat may or may not be paired with a person, therefore for every hat present in the 
    //hatTable hashmap we will either ignore it(not assign it to anybody) or we will iterate over
    //all the people who have a preference for that hat and assign it to them. Then perform a 
    //recursive call for the next hat with the updated bitmask and store the results.
    int solve(int hat,int mask,int n){
        //if all the people have been assigned a hat, then we have discovered one possible assignment
        if(mask==(1<<n)-1){
            return 1;
        } else if(hat==41){
            //otherwise if we have exhausted all the hats then return 0 as we were not able to discover 
            //a valid assignment
            return 0;
        } else if(mem[hat][mask]!=-1){
            return mem[hat][mask];
        } else if(!hatTable.count(hat)) {
            return mem[hat][mask]=solve(hat+1,mask,n)%mod;
        }
        else {
            //we can skip the current hat(not assign it to anybody)
            int ans=solve(hat+1,mask,n);
            //we will assign the current hat to every person who prefers it and then perform
            //a recursive call and store the number of ways from all possible assignments
            for(int i=0;i<hatTable[hat].size();i++){
                int curr=hatTable[hat][i];
                if((mask>>curr)&1){
                    continue;
                } else {
                    ans=(ans%mod+solve(hat+1,mask|(1<<curr),n)%mod)%mod;
                }
            }
            return mem[hat][mask]=ans;
        }
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                hatTable[hats[i][j]].push_back(i);
            }
        }
        mem=vector<vector<int>>(41,vector<int>(1<<n,-1));
        return solve(1,0,n);
    }
};