// Runtime: 161 ms (Top 37.4%) | Memory: 79.76 MB (Top 6.9%)

class Solution {
public:
//Idea is to create min heap for both array & pop from
// trainers until we find a trainer capacity>=player, 
//if found res increased by one pop that trainer cause one player one trainer.
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int,vector<int>,greater<int>>p(players.begin(),players.end());
        priority_queue<int,vector<int>,greater<int>>q(trainers.begin(),trainers.end());
        int res=0;
        while(!p.empty() && !q.empty()){
            if(p.top()>q.top())q.pop();
            else if(p.top()<=q.top()){
                res++;
                p.pop();
                q.pop();
            }
        }
        return res;

        
    }
};