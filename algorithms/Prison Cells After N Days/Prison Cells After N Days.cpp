class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        //since there are only a 2**6 number of states and n can go to 10**9
        //this means that there is bound to be repetition of states
        int state=0;
        //making the initial state bitmask
        for(int i=0;i<cells.size();i++){
            if(cells[i]){
                state^=(1<<(7-i));
            }
        }
        //this array stores the various states encountered
        vector<int>seen;
        while(n--){
            int next=0;
            //transitioning to the next state
            for(int pos=6;pos>0;pos--){
                int right=pos+1,left=pos-1;
                if(((state>>right)&1)==((state>>left)&1)){
                    next|=(1<<pos);
                }
            }
            //if the next state is equal to the initial state, this means that we have
            //found the cycle. Let the length of the cycle be l=seen.size(). Therefore 
            //in the remaining n days, n/l of those will have no effect on the 
            //prison configuration. This means we can return the configuration of the 
            //n%l day.
            if(seen.size() and seen[0]==next){
                int cnt=seen.size();
                state=seen[n%cnt];
                break;
            } else {
                seen.push_back(next);
                state=next;
            }
        }
        //translating the prison state from the bitmask to an array.
        vector<int>ans(cells.size(),0);
        for(int i=0;i<8;i++){
            if((state>>i)&1){
                ans[7-i]=1;
            }
        }
        return ans;
    }
};