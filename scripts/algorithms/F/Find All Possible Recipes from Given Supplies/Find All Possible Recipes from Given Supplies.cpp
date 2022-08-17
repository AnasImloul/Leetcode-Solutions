class Solution {
public:
    
    // idea is to use TOPOLOGICAL SORTING
    
    // where any foood item with indegree 0 means that item can be created
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        // store what all dependencies exist for any item
        // similar to adjacent list of any node N
        // here node N is string, and all neighbour nodes are stored as vector<string>
        map<string, vector<string>> adjList;
        
        // to keep track of whether item can be made or still needs something before we can make it
        map<string, int>indegree;
        
        // check for each row of 2D matrix
        for(int i=0; i<ingredients.size(); i++)
        {
            // this will list out all the items need to make recipes[i]
            for(auto &item : ingredients[i])
            {
                // 'item' is required to make 'recipes[i]'
                adjList[item].push_back(recipes[i]);
                
                // recipes[i] now has a dependency 
                indegree[recipes[i]]++;
            }
        }
        
        // will contain all items which can be made
        queue<string>q;
        
        // check from the list of given supplies, if some item is independent and we can make it or use it to make others
        for(auto &x : supplies)
            if(indegree[x]==0)
                q.push(x);
        
        
        
        while(!q.empty())
        {
            string node = q.front();
            q.pop();
            
            
            for(auto &nei : adjList[node])
            {
                // remove link of all neighbours of 'node'
                indegree[nei]--;
                
                // if something becomes independent, add it to our queue
                if(indegree[nei]==0)
                    q.push(nei);
            }
        }
        
        
        vector<string> ans;
        
        // all things which have 0 indegree means that they can be made. hence, they will be part of our answer
        for(auto &x : recipes)
            if(indegree[x]==0)
                ans.push_back(x);
            
        return ans;
    }
};
