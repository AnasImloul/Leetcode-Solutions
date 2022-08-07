class Solution {
    public int magicalString(int n) {
        if(n <= 3)
            return 1;
        Magical m = new Magical();
        int ans = 1;
        for(int i = 3; i < n; ++i)
            if(m.next() == 1)
                ++ans;
        return ans;
    }
}

class Magical{
    
    private Deque<Integer> nums;
    private int n;
    
    public Magical(){
        nums = new ArrayDeque<>();
        nums.offerLast(1);
        nums.offerLast(1);
        n = 1;
    }
    
    public int next(){
        if(n-- < 0){
            int c = nums.pollFirst();
            n = c - 2;
            int curr = 3 - nums.peekLast();
            for(; c > 0; --c)
                nums.offerLast(curr);
            return curr;
        }
        return nums.peekLast();
    }
}
