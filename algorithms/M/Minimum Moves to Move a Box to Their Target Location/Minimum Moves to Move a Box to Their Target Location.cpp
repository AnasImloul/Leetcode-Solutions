class Solution {
public:
    
    pair<int,int> t; //target
    pair<int,int> s; //source
    pair<int,int> b; //box
    
    // struct to store each member in priority queue
    struct node {
        int heuristic; // to find the dist between target and box
        int dist; // to keep track of how much the box moved
        pair<int,int> src; // to store the source
        pair<int,int> dest; // to store the box location
    };
    
    struct comp {
        bool operator()(node const& a, node const& b){
            return a.heuristic + a.dist > b.heuristic + b.dist;
        }
    };
 
    int direction[4][2]= {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    int minPushBox(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='T')
                    t={i,j};
                
                else if(grid[i][j]=='B')
                    b={i,j};
                
                else if(grid[i][j]=='S')
                    s={i,j};
            }
        }
        
        priority_queue<node,vector<node>,comp> pq;
        set<string> visited;
        
        node initialState = node{manhattanDist(b.first,b.second),0,s,b};
        string initialStr = hash(initialState);
        
        pq.push(initialState);
                
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            
            // we have reached the target return
            if(cur.dest == t) 
                return cur.dist;
            
            // hash the cur string and 
            string cur_vis = hash(cur);
            if(visited.count(cur_vis)) continue;
            
            // mark it as visited
            visited.insert(cur_vis);
            
            // in all the four directions
            for(auto& dir:direction){
                int sx = cur.src.first + dir[0];
                int sy = cur.src.second + dir[1];
                
                // if the new source is valid index
                if(valid(sx,sy,grid)){
                    
                    //if the source is equal to the where the box is
                    if(sx == cur.dest.first && sy == cur.dest.second){
                        int bx=cur.dest.first + dir[0];
                        int by=cur.dest.second + dir[1];
                        
                        // if the box is at right position
                        if(valid(bx,by,grid)){
                            
                            // increment the dist by 1 and update the source and box location
                            node updated = node{manhattanDist(bx,by),cur.dist+1,{sx,sy},{bx,by}};
                            pq.push(updated);
                        }
                    }else{
                        // update the new location of source 
                        node updated = node{cur.heuristic,cur.dist,{sx,sy},cur.dest};
                        pq.push(updated);
                    }
                }
            }
        }
        
        // we cannot perform the operation
        return -1;
        
    }
    
    string hash(node t){
        stringstream ss;
        ss<<t.src.first<<" "<<t.src.second<<" "<<t.dest.first<<" "<<t.dest.second;
        return ss.str();
    }
    
    int manhattanDist(int i, int j){
        return abs(t.first-i) + abs(t.second-j);
    }
    
    bool valid(int i, int j, vector<vector<char>>& g){
        
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]=='#') return false;
        
        return true;
    }
};
