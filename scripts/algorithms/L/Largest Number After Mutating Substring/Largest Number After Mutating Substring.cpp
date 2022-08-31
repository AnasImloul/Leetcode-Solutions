// Runtime: 98 ms (Top 46.69%) | Memory: 28.5 MB (Top 100.00%)
//change first longest encountered substring from left which can make string greater in value
class Solution {
public:
    string maximumNumber(string num, vector<int>& change){
        int n=num.size();
        for(int i=0;i<n;i++){
            int x=num[i]-'0';
            if(x < change[x]){//checking whether mutating this char will increment the value or not
            //the mutation continues till mutating the char will increase the value
                while(i<n and num[i]-'0'<=change[num[i]-'0']){
                    num[i++]=change[num[i]-'0']+'0';
                }
                //break the loop when substring ends
                break;
            }
        }
        return num;
    }
};