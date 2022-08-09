class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int count=0;
        int c1=capacityA,c2=capacityB;
        for(int start=0,end=plants.length-1;start<=plants.length/2&&end>=plants.length/2;start++,end--){
            if(start==end||start>end)break;
            if(c1>=plants[start]){
                c1-=plants[start];
            }
            else{
                count++;
                c1=capacityA;
                c1-=plants[start];
            }
            if(c2>=plants[end]){
                c2-=plants[end];
            }
            else{
                count++;
                c2=capacityB;
                c2-=plants[end];
            }
        }
        if((c1>c2||c1==c2)&&plants.length%2!=0){
            if(plants[plants.length/2]>c1)count++;
        }
        else if(c1<c2&&plants.length%2!=0){
            if(plants[plants.length/2]>c2)count++;
        }
        return count;
    }
}
