// Runtime: 11 ms (Top 11.73%) | Memory: 6.7 MB (Top 59.28%)
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>sk;
        vector<int>res;
        vector<int>temp;
        int ss=0;
        int mins;
        for(int i=0;i<s.length();i++){
            if(s[i]==c)
            //storing all the c character location i.e 'e' in sk i.e [3,5,6,11]
             sk.push_back(i);
        }
        for(int i=0;i<s.length();i++){
            for(int j=0;j<sk.size();j++){
            //now subtracting every i value with all value of character locations and storing the minimum in res vector.

                mins=abs(sk[j]-i);
                temp.push_back(mins);
            }
                //in first iteration [3-0=3,5-0=5,6-0=6,11-0=0] so removing the minimum elemnet from this that is 3 and stroing is res.
            int min=temp[0];
            for(auto i:temp){
                if(i<min){
                    min=i;
                }
            }
            res.push_back(min);
            temp.clear();

        }

        return res;
    }
};