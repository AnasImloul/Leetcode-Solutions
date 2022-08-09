class Solution {
    private int binarySearch(int ans, int x, CustomFunction func){
        int left = 1, right =1000;
        while(left <= right){
            int mid = left + (right -left)/2;
            
            int res = func.f(x, mid);
            
            if(res == ans){
                return mid;
            }
            if(res < ans){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();

        for(int i=1; i<=1000; i++){
            int ans = binarySearch(z, i, customfunction);
            if(ans != -1){
                List<Integer> temp = new ArrayList<>();
                temp.add(i);
                temp.add(ans);
                res.add(temp);
            }
            if(customfunction.f(i,1) > z){
                break;
            }
        }
        return res;
    }
}
