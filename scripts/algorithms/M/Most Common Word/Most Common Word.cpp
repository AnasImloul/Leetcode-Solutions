class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string temp;
        vector<string> words;
        for(char c:paragraph){
            if(isalpha(c) && !isspace(c)) temp+=tolower(c);
            else{
                if(temp.length()) words.push_back(temp);
                temp="";
            }
        }
        if(temp.length()) words.push_back(temp);
        
        map<string,int> mp;
        for(string i:words) mp[i]++;
        for(string i:banned) mp[i]=0;
        string ans;
        int maxUsedFreq=0;
        for(auto i:mp){
            if(i.second>maxUsedFreq){ 
                ans=i.first;
                maxUsedFreq=i.second;
            }
        }
        return ans;
    }
};