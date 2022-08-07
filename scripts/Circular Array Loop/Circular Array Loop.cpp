class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        unordered_set<int>us;
        for(int i{0};i<nums.size() && us.find(i)==us.end();i++){
            unordered_map<int,int>um;
            int index=0;
            int j=i;
            um[i];
            bool flag1=0,flag2=0;
            while(true){
                if(nums.at(i)<0){
                    index=(nums.size()+nums.at(j)+j)%nums.size();
                    flag1=1;
                }else{
                    index=(nums.at(j)+j)%nums.size();
                    flag2=1;
                }
                if(nums.at(index)>0 && flag1==1){
                    break;
                }else if(nums.at(index)<0 && flag2==1){
                    break;
                }
                if(um.find(index)==um.end()){
                    um[index];
                    us.insert(index);
                }else{
                    if(j==index){
                        break;
                    }
                    if(um.size()>1){
                        return true;
                    }else{
                        break;
                    }
                }
                j=index;
            }            
        }
        return false;
    }
};
