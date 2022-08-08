class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)   // We can't rearrange elements of size groupsize so return false
            return false;
        map<int,int>mp;
        for(auto it : hand)
            mp[it]++;
        while(mp.size() > 0){
            int start = mp.begin()->first;   // Taking the topmost element of map

            for(int i=0; i<groupSize; i++){
                if(mp.find(start) != mp.end()){
                    mp[start]--;
                    if(mp[start] == 0)
                        mp.erase(start);
                    start++;                // Increasing for finding next consecutive element of start. 
                }
                else
                    return false;
            }
        }
        return true;
    }
};
