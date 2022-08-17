class Solution {     
    public int maxHeight(int[][] cuboids) {
		/* You can use Arrays.sort(int[]) for int[] in cuboids */
        /* We have only three elments in array */
        for(int[] el: cuboids){
            if(el[0] > el[2]){
                int temp = el[0];
                el[0] = el[2];
                el[2] = temp;
            }
            if(el[1] > el[2]){
                int temp = el[1];
                el[1] = el[2];
                el[2] = temp;
            }
            if(el[0] > el[1]){
                int temp = el[0];
                el[0] = el[1];
                el[1] = temp;
            }
        }
        /* Sort by height, width, length in order */
        Arrays.sort(cuboids, new Comparator<int[]>(){
            @Override
            public int compare(int[] b, int[] a){
                if(a[2] != b[2]){
                    return b[2] - a[2];
                }
                if(a[1] != b[1]){
                    return b[1] - a[1];
                }
                return b[0] - a[0];
            }
        });
        int n = cuboids.length;
        int[] dp = new int[n];
        int res = -1;
	    /* Longest increasing subsequence */
		for(int j = 0; j < n; j++){
            dp[j] = cuboids[j][2];
            for(int i = 0; i < j; i++){
				 /* Dont track index, track Sum */
                if(cuboids[i][1] <= cuboids[j][1] && cuboids[i][0] <= cuboids[j][0]){
                    dp[j] = Math.max(dp[j], dp[i] + cuboids[j][2]);   
                }
            }
            res = Math.max(res, dp[j]);
        }
        return res;
    }
}
