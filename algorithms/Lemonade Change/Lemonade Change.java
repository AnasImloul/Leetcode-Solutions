class Solution {
    public boolean lemonadeChange(int[] bills) {
        int count5 = 0, count10 = 0;
        for(int p : bills){
            if(p == 5){
                count5++;
            }
            else if(p == 10){
                if(count5 > 0){
                    count5--;
                    count10++;
                }
                else{
                    return false;
                }
            }
            else if(p == 20){
                if(count5 > 0 && count10 > 0){
                    count5--;
                    count10--;
                }
                else if(count5 == 0){
                    return false;
                }
                else if(count5<3){
                    return false;
                }
                else{
                    count5 -= 3;
                }
            }
        }
        return true;
    }
}
