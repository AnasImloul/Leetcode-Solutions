// Runtime: 57 ms (Top 56.3%) | Memory: 50.05 MB (Top 68.1%)

class Solution {
    
    Random random;
    TreeMap<Integer,int[]> map;
    int areaSum = 0;
    
    public Solution(int[][] rects) {
        this.random = new Random();
        this.map = new TreeMap<>();
        
        for(int i = 0; i < rects.length; i++){
            int [] rectangeCoordinates = rects[i];
            int length = rectangeCoordinates[2] - rectangeCoordinates[0] + 1 ; // +1 as we need to consider edges also.
            int breadth = rectangeCoordinates[3] - rectangeCoordinates[1] + 1 ;
            
            areaSum += length * breadth;
            
            map.put(areaSum,rectangeCoordinates);
            
        }
        
    }
    
    public int[] pick() {
        int key = map.ceilingKey(random.nextInt(areaSum) + 1); //Don't forget to +1 here, because we need [1,area] while nextInt generates [0,area-1]
        
        int [] rectangle = map.get(key);
        
        int length = rectangle[2] - rectangle[0] + 1 ; // +1 as we need to consider edges also.
        int breadth = rectangle[3] - rectangle[1] + 1 ;
        
        int x = rectangle[0] + random.nextInt(length); //return random length from starting position of x
        int y = rectangle[1] + random.nextInt(breadth); // return random breadth from starting position of y
        
        return new int[]{x,y};
        
    }
}
