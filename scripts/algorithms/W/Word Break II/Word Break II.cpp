class Solution {
public:
    void helper(string s, unordered_set<string>& dict,int start, int index,string current,vector<string>& ans){
        if(start==s.size()){
            ans.push_back(current);
            return;
        }
        if(index==s.size()) return;

        string sub=s.substr(start,index-start+1);

        if(dict.count(sub)>0){
            string recursion;
            if(current.size()==0) recursion=sub;
            else recursion=current+" "+sub; 
            helper(s,dict,index+1,index+1,recursion,ans);
        }
        helper(s,dict,start,index+1,current,ans);
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0;i<wordDict.size();i++){
                dict.insert(wordDict[i]);
        }
        vector<string> ans;
        helper(s,dict,0,0,"",ans);
        return ans;
        
    }
};