// Runtime: 19 ms (Top 100.00%) | Memory: 22 MB (Top 65.01%)
class Solution {
public:
    bool simplified(int n, int i){
        while(i>0){
            n-=i;
            if(i>n)swap(n,i);
        }
        if(n>1) return false;
        else return true;
    }

    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        while(n>1){
            int i=1;
            while(i<n){
                if(simplified(n, i)){
                    string fraction;
                    int num=i;
                    while(num>0){
                        fraction.push_back(num%10+'0');
                        num/=10;
                    }
                    fraction.push_back('/');
                    num = n;
                    while(num>0){
                        fraction.push_back(num%10+'0');
                        num/=10;
                    }
                    if(i>9) swap(fraction[0],fraction[1]);
                    if(n>99) swap(fraction[fraction.size()-1],fraction[fraction.size()-3]);
                    else if(n>9) swap(fraction[fraction.size()-1],fraction[fraction.size()-2]);
                    ans.push_back(fraction);
                }
                i++;
            }
            n--;
        }
        return ans;
    }
};