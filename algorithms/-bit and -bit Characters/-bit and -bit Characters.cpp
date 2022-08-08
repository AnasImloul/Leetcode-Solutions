class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i =0;
        while(i<bits.size()){
            if( bits[i] == 1 and bits[i+1] == 0){
                if(i+1 == bits.size()-1)
                    return false;
                else
                    i+=2;
            }
            else if( bits[i]==1 and bits[i+1] == 1){
                i+=2;
            }
            else if(bits[i] == 0){
                i+=1;
            }
        }
        return true;
    }
    
};
