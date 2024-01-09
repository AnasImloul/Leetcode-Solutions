// Runtime: 0 ms (Top 100.0%) | Memory: 6.80 MB (Top 47.46%)

class Solution {
public:
    string makeLargestSpecial(string s) {
        
        if(s.length()==0)
            return ""; //return null string if size is zero

        vector<string> ans; //list to store all current special substrings
        int count=0,i=0; //keep track of special substring starting index using "i" and 
                         //"count" to keep the track of special substring is over or not

        for(int j=0;j<s.size();j++){
            if(s[j] == '1')
                count++;
            else
                count--;
            
            if(count==0){
                //call recursively using mid special substring

                ans.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) + '0');
                i = j+1;
            }
        }
        //sort current substring stored list to fulfill the question demand

        sort(ans.begin(),ans.end(),greater<string>());
        string finalString = "";
        for(i=0;i<ans.size();i++){
            finalString += ans[i];
        }
        return finalString;
    }
};
