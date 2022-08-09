class Solution {
public:
    

    bool canChange(string start, string target) {
        
        
        vector<pair<char,int >> v;
        for(int i =0 ;i  < start.size();i++)
        {
            if(start[i] == 'L' || start[i] == 'R')
            {
                v.push_back({start[i],i});
            }
        }
        
        int i = 0;
        for(int j = 0;j < target.size();j++)
        {
            if(target[j] == 'L' || target[j] == 'R') // lets find its corresponding Element in start
            {
                if(i >= v.size() || v[i].first != target[j]) // Not found or Different found
                {
                    return false;
                }else 
                {
                   
                    if(v[i].first == 'L' && v[i].second < j) // Condition a unsatisfied
                        return false;
                     if(v[i].first == 'R' && v[i].second > j) // Condition b unsatisfied
                        return false;
                     else 
                        i++; // all good we move ahead in start;
                }
               
                
            }
        }
        
        return i == v.size();// all elements accounted for in start
    }
};
