// Runtime: 0 ms (Top 100.0%) | Memory: 6.30 MB (Top 95.82%)

/*
                    h( AAB , -1 , 0 )              LEVEL=0 ie 0 length substring
                    /               \
            h('A'AB,0,1)           h('B'AA,6,1)    LEVEL=1 ie 1 length substrings ("A","B")
            /         \              /
        h('AA'B,1,2) h('AB'A,4,2) h('BA'A,7,2)     LEVEL=2 ie 2 length substrings ("AB","BA","AA")
        /            /             /
    h('AAB',2,3)    h('ABA',5,2)  h('BAA',8,3)     LEVEL=3 ie 3 length substrings 
                                                   ("AAB", "ABA", "BAA")
*/
class Solution {
    
    void backtrack(string tiles, int level, int &count)
    {
        count++;
        for(int i=level; i<tiles.length(); i++){
            
            if(i!=level && tiles[i]==tiles[level])
                continue;   // to skip same characters
            swap(tiles[i], tiles[level]);
            backtrack(tiles, level+1, count);
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        
        int count=-1;
        sort(tiles.begin(), tiles.end()); 
        
        backtrack(tiles, 0, count); //level = susbstring length
        
        return count;
    }
};

