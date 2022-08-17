class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<int> tables;
        set<string> foodItems;
        
        for (const auto& order : orders)
        {
            tables.insert(stoi(order[1]));
            foodItems.insert(order[2]);
        }
        
        int pos = 1;
        unordered_map<int,int> t_pos;
        for (const auto& t : tables)
        {
            t_pos[t] = pos;
            pos++;
        }
        
        pos = 1;
        unordered_map<string,int> f_pos;
        for (const auto& f : foodItems)
        {
            f_pos[f] = pos;
            pos++;
        }
        
        vector<vector<string>> displayTable(tables.size()+1, vector<string>(foodItems.size()+1,"0"));
        
        displayTable[0][0] = "Table";
        
        auto it = tables.begin();
        for (int x = 1; x < displayTable.size(); x++)
        {
            displayTable[x][0] = to_string(*it);
            it++;
        }
        
        auto it_ = foodItems.begin();
        for (int y = 1; y < displayTable[0].size(); y++)
        {
            displayTable[0][y] = *it_;
            it_++;
        }
        
        for (const auto& order : orders)
        {
            int t = t_pos[stoi(order[1])];
            int f = f_pos[order[2]];
            
            int dec = stoi(displayTable[t][f]);
            dec++;
            displayTable[t][f] = to_string(dec);
        }
        
        return displayTable;
    }
};
