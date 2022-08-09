class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>(new Comparator<double[]>(){
            public int compare(double[] a, double[] b){
                double adiff = (a[0]+1)/(a[1]+1) - (a[0]/a[1]);                
                double bdiff = (b[0]+1)/(b[1]+1) - (b[0]/b[1]);
                if(adiff==bdiff) return 0;
                return adiff>bdiff? -1:1;
            }
        });
        
        for(int[] c:classes) pq.add(new double[]{c[0],c[1]});
        
        for(int i =0;i<extraStudents;i++){
            double[] curr = pq.poll();
            pq.add(new double[]{curr[0]+1,curr[1]+1});
        }
        
        double sum = 0;
        while(!pq.isEmpty()){
            double[] curr = pq.poll();
            sum+=curr[0]/curr[1];
        }
        
        return sum/classes.length;
    }
}
