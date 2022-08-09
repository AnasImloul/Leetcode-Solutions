class Solution {
public:
    
    void rangeOfChar(pair<int, int> startEnd[], string s, int visited[]){
        int n = s.length();
        
        for(int i=n-1; i>=0; i--){
            auto asciiInd = s[i]-'a';
            auto rangeInd = startEnd[asciiInd];
            visited[asciiInd] = i;
            if(rangeInd.first == i){
                for(int j=0; j<26; j++){
                    auto rangeLookup = startEnd[j];
                    if(rangeLookup.first != -1 
                       && rangeLookup.first <= i
                       && rangeLookup.second >= rangeInd.first
                       && rangeInd.second >= rangeLookup.second){
                        rangeInd.first = min(rangeLookup.first,rangeInd.first);
                        rangeInd.second = max(rangeLookup.second, rangeInd.second);
                    }else if(visited[j] != -1 
                             && visited[j] < rangeInd.second){
                        rangeInd.first = min(rangeLookup.first, rangeInd.first);
                        rangeInd.second = max(rangeLookup.second, rangeInd.second);
                    }    
                }
            }
            
            startEnd[asciiInd] = rangeInd;
        }
    }
    
    vector<string> maxNumOfSubstrings(string s) {
        
        pair<int, int> startEnd[26];
        for(int i=0;i<26; i++)startEnd[i] = {-1,-1};
        int visited[26];
        memset(visited, -1, sizeof(visited));
        int n = s.length();
        vector<string> ans;
        
        for(int i=0; i<n; i++) {
            int charIndex = s[i] - 'a';
            if(startEnd[charIndex].first == -1){
                startEnd[charIndex].first = i;
            }
            startEnd[charIndex].second = i;            
        }
        
        rangeOfChar(startEnd, s, visited);
        
        int lastIndex = -1;
        
        for(int i=0; i<n; i++){
            if(startEnd[s[i]-'a'].first<i)continue;
            auto range = startEnd[s[i]-'a'];
            //cout<<range.first<<" "<<range.second<<" "<<s[i]<<endl;
            if(range.first == -1)continue;
            if(range.second < lastIndex){
                ans.pop_back();
            }
            lastIndex = range.second;
            ans.push_back(s.substr(range.first, range.second-range.first+1));
        }
        
        return ans;
    }
};
