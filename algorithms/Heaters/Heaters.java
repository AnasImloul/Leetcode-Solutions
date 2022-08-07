//few test cases need to fixed
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        // radius[i] means radius required to heat house i 
        long[] radius = new long[houses.length];
        Arrays.fill(radius, Long.MAX_VALUE);
        int hIndex = 0;
        
        //A house can be heated from a heater on the left or a heater on the right, whichever is closer.
        
        //First let us fill radius array such that every house is heated from the left side heater.
        for(int i = 0; i < houses.length; i++) {
            // There may be multiple heaters on the left of a house, we need to choose only the closest.
            // So we are increasing heater index until it's position <= house's position.
            while(hIndex < heaters.length - 1 && heaters[hIndex+1] <= houses[i]) {
                hIndex++;
            }
            //if the heater is on the left of the house, calculate raidus and store in raidus[i], we filled array 
            // with Integer.MAX_VALUE, so we must need to use Math.min 
            if(heaters[hIndex] <= houses[i]) {
                radius[i] = Math.min(radius[i],houses[i] - heaters[hIndex]);
            }
        }
        
        //Same as what we did on in prev loop, now we will do it from right to left. 
        long ans = 0;
        hIndex = heaters.length - 1;
        for(int i = houses.length - 1; i >= 0; i--) {
             while(hIndex > 0 && heaters[hIndex-1] >= houses[i]) {
                hIndex--;
            }
            if(houses[i] <= heaters[hIndex]) {
                radius[i] = Math.min(radius[i], heaters[hIndex] - houses[i]);
            }
            ans = Math.max(ans, radius[i]);
        }
        
        return (int)ans;
    }
}
