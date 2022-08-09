class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence) ;
        string word = "" ;
        int idx = 1 ;
        
        while(iss >> word){
            for(int sz = 1 ; sz <= size(word) ; ++sz ){
                if(searchWord == word.substr(0,sz)) return idx ;
            }
            ++idx ;
        }
        
        return -1 ;
    }
};
