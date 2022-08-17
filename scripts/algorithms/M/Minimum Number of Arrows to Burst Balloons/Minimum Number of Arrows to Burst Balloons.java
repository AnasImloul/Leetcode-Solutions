class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(a,b)->{
            if(a[0]>b[0]){
                return 1;
            }else if(a[0]==b[0]){
                return 0;
            }else{
                return -1;
            }
        });

        int max=Integer.MAX_VALUE;
        int count=0;
        for(int []e:points){
            if(max<e[0]){
                count++;
                max=e[1];
            }
            else{
                max=Math.min(max,e[1]);
            }
        }
        return count+1;
    }
}