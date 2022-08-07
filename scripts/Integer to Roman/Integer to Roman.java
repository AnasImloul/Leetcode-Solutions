class Solution {
    public String intToRoman(int num) {
        int Num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        String roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        String Roman="";
        int a=12;
        while(num>0)
        {
            while(num/Num[a] >0)
            {
                Roman+=roman[a];
                num-=Num[a];
            }
            a--;
        }
        return Roman;
    }
}
