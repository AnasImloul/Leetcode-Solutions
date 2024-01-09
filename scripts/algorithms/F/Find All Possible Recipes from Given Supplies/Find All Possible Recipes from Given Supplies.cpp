// Runtime: 544 ms (Top 27.33%) | Memory: 101.90 MB (Top 78.97%)

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,int>indegree;
        for(auto i:recipes)
            indegree[i]=0;   //Initially indegree of every recipe is 0
        
        unordered_map<string,vector<string>>graph;
        
        for(int i=0;i<recipes.size();i++){
            
            for(int j=0;j<ingredients[i].size();j++){
                
                if(find(supplies.begin(),supplies.end(),ingredients[i][j])==supplies.end()){ //finds if the ingredient exist in the supply or not
                    
                    graph[ingredients[i][j]].push_back(recipes[i]); //If not then ingredients[i][j] is required to prepare the recipes[i] i.e bread--->burger, sandwitch ---> burger
                    
                    indegree[recipes[i]]++;     //increase the indegree of the recipe , for example , bread->burger,sandwitch-->burger , now indegree of burger is 2
                }
            }
        }
        queue<string>q;            //Now simple topo sort using bfs (Kahn's algorithm)
        for(auto i:indegree){
            if(i.second==0)
                q.push(i.first);
        }
        vector<string>ans;
        
        while(!q.empty()){
            string front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:graph[front]){
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
        }
        return ans;
    }
};
