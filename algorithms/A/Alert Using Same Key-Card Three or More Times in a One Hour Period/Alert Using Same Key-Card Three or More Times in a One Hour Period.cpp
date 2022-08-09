class Solution {
public:
    bool timeDiff(vector<string> timestamp, int index){
        int time1 = ((timestamp[index][0]-'0') * 10 + (timestamp[index][1]-'0')) * 60 + ((timestamp[index][3]-'0') * 10 + (timestamp[index][4]-'0'));
        int time2 = ((timestamp[index+2][0]-'0') * 10 + (timestamp[index+2][1]-'0')) * 60 + ((timestamp[index+2][3]-'0') * 10 + (timestamp[index+2][4]-'0'));
        
        if(abs(time2-time1)<=60) return true;
        return false;
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<string>> ht;
        
        for(int i=0; i<keyName.size(); i++)
            ht[keyName[i]].push_back(keyTime[i]);
        
        vector<string> result;
        for(auto time : ht){
            sort(time.second.begin(), time.second.end());
            for(int i=0; i+2<time.second.size(); i++)
                if(timeDiff(time.second, i)){
                    result.push_back(time.first);
                    break;
                }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};

/*
Algorithm Outline
1. store in HT as vector
2. Check for each, 1st & 3rd in range. True if Yes
*/
