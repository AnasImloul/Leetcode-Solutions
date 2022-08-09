class Solution {
    public int sum(int num1, int num2) {
        int l = -200, r = 200;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid == num1 + num2) { return mid; }
            if (mid <  num1 + num2) l = mid + 1;
            if (mid >  num1 + num2) r = mid - 1;
        }
        return l;
    }
}
        
