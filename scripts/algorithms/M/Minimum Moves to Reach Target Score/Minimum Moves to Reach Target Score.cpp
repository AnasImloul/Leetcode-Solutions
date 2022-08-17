class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while(target>1 && maxDoubles>0){
            if(target%2==0){
                cnt++;
                maxDoubles--;
                target = target/2;
            }
            else{
                cnt++;
                target--;
            }
        }
        return cnt + (target-1);
    }
};
