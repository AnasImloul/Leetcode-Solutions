// Runtime: 70 ms (Top 74.0%) | Memory: 37.30 MB (Top 38.8%)

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int min=INT_MAX;
       unordered_map<string,int>un;
        vector<string>v;
        for(int i=0;i<list1.size();i++){
            un[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(un.count(list2[i])!=0){
              int sum=i+un[list2[i]];
                if(sum<min){
                    min=sum;
                    v.clear();
                    v.push_back(list2[i]);
                }else if(sum==min){
                     v.push_back(list2[i]);
                }
            }
        }
        return v;
        
        
    }
    };
