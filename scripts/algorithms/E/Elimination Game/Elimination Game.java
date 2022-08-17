class Solution {
    public int lastRemaining(int n) {
        int head = 1;
        int remain = n;
        boolean left = true;
        int step =1;
        
        while(remain > 1){
            if(left || remain%2==1){
                head = head + step;
            }
            remain /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
}
