// Runtime: 483 ms (Top 84.03%) | Memory: 167.40 MB (Top 58.68%)

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) { 
		// create the graph betwen the persons
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0; i < meetings.size(); ++i){
            graph[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            graph[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }

		// using min heap , using time as the sort order key.   
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> > q;
		
		// Add both 0 and firstPerson in the queue as they know the secret initially at time 0 
        q.push({0, firstPerson});
        q.push({0, 0});
		//  vector to store res  
        vector<int> res;
		
		// marking the persons as visited if they have met and shared the secret to all possible persons they could 
        vector<bool> visited(n,false);
        
        while(!q.empty()){
            pair<int,int> curr = q.top();
            q.pop();
            
            int person = curr.second;
            int time = curr.first;
			
			// person had already shared the secret with others
            if(visited[person]) {
                continue;
            }
            visited[person] = true;
			
			//iterate all the meetings of this person and add the potential new persons he can share secret with 
            for(pair<int,int> neigh : graph[person]){
                if(!visited[neigh.first] && time <= neigh.second){
                    q.push({neigh.second,neigh.first});
                }
            }
        }
        
		// all visited persons know the secret
        for(int i = 0; i < n ; ++i ){
            if(visited[i]){
                res.push_back(i);        
            }
        }
        return res;
    }
};
