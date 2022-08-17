class Solution {
    public int numberOfBoomerangs(int[][] points) {
        
        int answer = 0;
        
        for (int p=0; p<points.length;p++) {
            
            int[] i = points[p];
            
            HashMap<Double, Integer> hm = new HashMap<Double, Integer>();
            
            for (int q=0;q<points.length;q++) {
                
                if (q==p) {
                    continue;
                }
                
                int[] j = points[q];
                
                double distance = Math.sqrt(Math.pow(j[0]-i[0], 2) + Math.pow(j[1]-i[1], 2));
                
                if (distance > 0) {
                    if (hm.containsKey(distance)) {
                        hm.put(distance, hm.get(distance) + 1);
                    } else {
                        hm.put(distance, 1);
                    }
                }
                
            }
            
            for (Double dist : hm.keySet()) {
                int occ = hm.get(dist);
                if (occ > 1) {
                    answer = answer + ((occ) * (occ - 1));
                }
            }
        }
        
        return answer;
    }
}
