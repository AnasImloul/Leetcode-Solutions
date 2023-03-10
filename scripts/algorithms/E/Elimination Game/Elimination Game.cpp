class Solution {
public:
    int lastRemaining(int n) {
        bool left=true;
        int head=1,step=1;//step is the difference between adjacent elements.
        while(n>1){
            if(left || (n&1)){//(n&1)->odd
                head=head+step;
            }
            step=step*2;
            n=n/2;
            left=!left;
        }
        return head;
    }
};