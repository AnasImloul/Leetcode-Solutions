// Runtime: 70 ms (Top 83.06%) | Memory: 35.10 MB (Top 50.72%)

// if you like this, please give me a upvote
class Solution {
public:
    int parents[1001]; // why 1001? becoz it is max length of accounts, see constraints (1 <= accounts.length <= 1000)
    
    // function to find original parent
    int findpar(int parents[], int to_find)
    {
        while(parents[to_find] != to_find)
            to_find = parents[to_find];
        
        return to_find; 
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Link each email to their respective orginal parent, 
        // we will do it by linking each email to its unique id
        unordered_map<string, int> email_to_id;
        
        for(int i = 0; i < accounts.size(); i++) // traversing from each row
        {
            parents[i] = i; // intially we don't know anything, so every parent is unique id of itself
            
            // why we start from 1? becoz emails starting from this place
            for(int j = 1; j < accounts[i].size(); j++)
            {
                // we check if this particular email already got their unique id, if yes then we link it to its original parent unique id
                if(email_to_id.find(accounts[i][j]) != email_to_id.end())
                {
                    int parent1 = findpar(parents, i);
                    int parent2 = findpar(parents, email_to_id[accounts[i][j]]);
                    
                    parents[parent1] = parent2;
                }
                else // if not find, then just give it to exsiting parent
                {
                    email_to_id[accounts[i][j]] = parents[i];
                }
            }
        }
            
            // Now, we create a map that store all email id with their unique ids
            //            id,  vector of all emails
            unordered_map<int, vector<string>> resultant_map;
            
            for(auto it: email_to_id)
            {
                int uniq_id = findpar(parents, it.second); 
                resultant_map[uniq_id].push_back(it.first);
            }
            
            // uff tired, so now towards final ans
            vector<vector<string>> ans;
            for(auto it: resultant_map)
            {
                vector<string> email = it.second;
                
                // question demand in sorted order
                sort(email.begin(), email.end());
                
                // inserting name in starting with the help of unique id
                email.insert(email.begin(), accounts[it.first][0]);
                
                ans.push_back(email);
            }
        return ans;
    }
};
