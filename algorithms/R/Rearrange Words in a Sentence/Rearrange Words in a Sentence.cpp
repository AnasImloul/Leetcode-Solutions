class Solution {
public:
    vector<pair<string,int>> words ;
    string arrangeWords(string text) {
        //convert to lowercase alphabet 
        text[0] += 32 ;
        
        istringstream iss(text) ;
        string word = "" ;
		
		//pos is the index of each word in text.
        int pos = 0 ;
        
        while(iss >> word){
            words.push_back({word,pos});
            ++pos ;
        }
        
		//sort by length and pos.
        sort(begin(words),end(words),[&](const pair<string,int> &p1 , const pair<string,int> &p2)->bool{
            if(size(p1.first) == size(p2.first)) return p1.second < p2.second ;
            return size(p1.first) < size(p2.first);
        });
        
        string ans = "" ;
        for(auto &x : words) ans += x.first + " " ;
        ans.pop_back() ;
        
        //convert to uppercase alphabet 
        ans[0] -= 32 ;
        return ans ;
        
        
    }
};
