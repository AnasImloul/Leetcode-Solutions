// Runtime: 1 ms (Top 100.00%) | Memory: 42 MB (Top 28.32%)
class Solution {
    int count;
    public int numSquarefulPerms(int[] nums) {
        int n = nums.length;
        if(n<2)
            return count;
        backtrack(nums,n,0);
        return count;

    }

    void backtrack(int [] nums,int n, int start)
    {
        if(start==n)
        {
            count++;
        }
       Set <Integer> set = new HashSet <>();
        for(int i = start;i<n;i++)
        {
            if(set.contains(nums[i])) continue;
            swap(nums,start,i);
            if(start == 0 || isPerfectSq(nums[start],nums[start-1]))
                backtrack(nums,n,start+1);
            swap(nums,start,i);
            set.add(nums[i]);
        }
    }

    void swap(int [] A,int a, int b)
    {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;

    }

    boolean isPerfectSq(int a, int b)
    {
        int x = a+b;
        double sqrt = Math.sqrt(x);
        return (sqrt - (int)sqrt) == 0 ?true:false;
    }
}