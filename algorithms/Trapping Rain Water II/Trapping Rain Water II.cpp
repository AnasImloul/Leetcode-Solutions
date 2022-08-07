class Solution {
public:
	bool vis[201][201];                                                           //to keep track of visited cell
    int n,m;
    bool isValid(int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]==true)  return false;
        
        return true;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> dir {{1,0},{-1,0},{0,1},{0,-1}};          //direction Vector
        m = heightMap.size();   if(m==0)    return 0;                // m=0 is one edge case
        n = heightMap[0].size();
        memset(vis,false,sizeof(vis));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;                                // min heap w.r.t cell height
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    pq.push({heightMap[i][j],{i,j}});                          //pushing all outer cells in pq
                    vis[i][j]=true;
                }   
            }
        }
        int water = 0;
        int Height = INT_MIN;
        while(!pq.empty()){                                                       //normal BFS
            auto pr =  pq.top();
            pq.pop();
            int height = pr.first;
            int i = pr.second.first;
            int j = pr.second.second;
            Height = max(Height,height);
            for(int d=0;d<4;d++){                                            //iterating through direction vector
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if(isValid(x,y)){
                   water += max(0, Height - heightMap[x][y]);      //just adding the diff between cell height and surrounding height
                   vis[x][y]=true;
                   pq.push({heightMap[x][y],{x,y}});
                }
            }            
        }
        return water;
		}
	};
