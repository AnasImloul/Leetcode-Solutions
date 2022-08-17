class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > busy; //departure time as first , index as second
        priority_queue<int, vector<int>, greater<int>> free; //min heap of chair index that are unoccupied
        
		//store friend indexes so that they don't get lost after sorting
        for(int i=0;i<n;++i){
            times[i].push_back(i);
        }
		//Sort according to arrival time
        sort(times.begin(),times.end());
        
		int new_chair = 0; //chairs alloted till now 
        for(int i=0;i<n;++i){
            int arrival = times[i][0]; //pop chairs before arrival 
            int leave_time = times[i][1];
            int fr = times[i][2]; //friend index
            //free chairs accordingly
            while(!busy.empty() && busy.top().first <= arrival){
                // cout << "Chair free " << busy.top().second << endl;
                free.push(busy.top().second);
                busy.pop();
            }   
            //No free chair allot new chair
            if(free.empty()){
                // cout << "Alloting new_chair " << new_chair << "to" << fr << endl;
                if(fr  == targetFriend) return new_chair;
                busy.push({leave_time,new_chair});
                new_chair++;
            }
            else{
                int x = free.top();
                // cout << "giving chair " << x << "to" << fr << endl;
                free.pop();
                if( fr  == targetFriend) return x; 
                busy.push({leave_time,x});
            }
        }
        return -1;
    }
    
};
