class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> ump;
    for(auto i:t){
        ump[i]++;
    }

    int i =0,j =0,count =0;
    int ans =INT_MAX,answer =0;
    for (;j < s.size();j++)
    {
        if(ump[s[j]]>0) {
            count++;
         }
        ump[s[j]]--;
        if(count==t.size()){

            while (i < j && ump[s[i]]<0)
            {
                ump[s[i]]++;
                i++;
            }
            if(ans > j-i+1){
                ans  = j-i+1;
                answer = i;
            }
            ump[s[i]]++;
            i++;
            count--;
        }
    }
    return ans==INT_MAX?"":s.substr(answer,ans);
    }
};
