class Solution {
public:
    void recur(vector<string> &ans, string tiles, int index, int &res)
    {
        res++;

        for(int i=index; i<tiles.size(); i++)
        {
            if(i != index && tiles[i] == tiles[index])
                continue;
            swap(tiles[i], tiles[index]);
            recur(ans, tiles, index+1, res);
        }

    }
    
    int numTilePossibilities(string tiles) {
        
        vector<string> ans;
        sort(tiles.begin(), tiles.end());
        int res = 0;
        recur(ans, tiles, 0, res);
        return res - 1;
    }
};
