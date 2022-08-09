class Solution {
    public int clumsy(int n) {
        List<Integer> res = new LinkedList<>();
        int i = n;
        int count = 0;
        while(i > 0){
            // find chain of multiplication and division
            int ans = i;
            if(count%4 == 0 && (i-1) > 0){
                ans = (i*(i-1));
                count++;
                i--;
            }
            if(count%4 == 1 && (i-1) > 0){
                ans = (int) Math.floor(ans/(i-1));
                i--;
                count++;
            }
            i--;
            count++;
            res.add(ans);
        }
        int ans = res.get(0);
        for(int j = 0; j < res.size()-1; j++){
            if(j%2 == 0){
                ans += res.get(j+1);
            }else{
                ans -= res.get(j+1);
            }
        }
        // System.out.println(res);
        return ans;
    }
}
