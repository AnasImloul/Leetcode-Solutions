class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

    vector<vector<string>>ans;
    map<int,map<string,int>>m;
    set<string>s; //Sets are useful as they dont contain duplicates as well arranges the strings in order.
    for(auto row:orders)
    {
        s.insert(row[2]);
        m[stoi(row[1])][row[2]]++;
    }

    vector<string>dem;
    dem.push_back("Table");
    for(auto a:s)
    {
        dem.push_back(a);
    }//For the  first row only

    ans.push_back(dem);
    for(auto it:m)
    {
        vector<string>row;
        row.push_back(to_string(it.first));
        auto dummy=it.second;
        for(auto st:s)//we use set here as it has food names stored in asc order.
        {
            row.push_back(to_string(dummy[st]));//we access the number of orders.
        }

        ans.push_back(row);

    }

    return ans;


    }
};