// Runtime: 0 ms (Top 100.0%) | Memory: 6.70 MB (Top 11.82%)

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int start = 0;
        
        for(int i =0; i<k ;i++){
            if(blocks[i]=='B')
                start++;
        }
        
        // window variable
        int temp = start;
        
        for(int i =0, j = k; j<blocks.size(); i++, j++ ){
            
            if(blocks[i]=='B')
                temp--;
            if(blocks[j]=='B')
                temp++;
            
            start = max(start,temp);
        }
        
        return k-start;            
        
    }
};
