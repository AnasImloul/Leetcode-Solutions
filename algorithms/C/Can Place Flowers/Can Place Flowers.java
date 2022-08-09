class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(flowerbed[0] != 1){
            n--;
            flowerbed[0] = 1;   
        }
        for(int i = 1; i < flowerbed.length; i++){
            if(flowerbed[i - 1] == 1 && flowerbed[i] == 1){
                flowerbed[i - 1] = 0;
                n++;
            }
            if(flowerbed[i - 1] != 1 && flowerbed[i] != 1){
                flowerbed[i] = 1;
                n--;
            }
        }
        return (n <= 0) ? true: false;
    }
}
