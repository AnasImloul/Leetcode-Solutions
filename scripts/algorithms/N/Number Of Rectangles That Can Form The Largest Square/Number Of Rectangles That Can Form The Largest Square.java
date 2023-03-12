class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        List<Integer> list=new LinkedList<Integer>();
        int max=0,count=0;
        for(int i = 0 ; i < rectangles.length ; i++){
            if(rectangles[i][0]>rectangles[i][1]){
                list.add(rectangles[i][1]);
                if(max<rectangles[i][1])
                max=rectangles[i][1];
            }
            else{
                list.add(rectangles[i][0]);
                if(max<rectangles[i][0])
                max=rectangles[i][0];
            }
        }
        for(Integer i:list){
            if(i==max)
            count++;
        }
        return count;
    }
}