// Runtime: 0 ms (Top 100.0%) | Memory: 45.10 MB (Top 7.1%)

class Solution {
    public double calculateTax(int[][] brackets, int income) {
        int prevIncome = 0;
        double res = 0;
        for(int i =0; i<brackets.length; i++){
            double diff = brackets[i][0] - prevIncome;
            if(diff > income){
                res += (income*brackets[i][1]/100.0);
                income = 0;
            }else{
                res += (diff*brackets[i][1])/100;
                income -= diff;
            }
            prevIncome = brackets[i][0];
            if(income == 0) return res;
            //System.out.println(prevIncome+" "+res+ " "+ income +" "+ diff + "  "+(diff*brackets[i][1]/100));
        }
        return res;
    }
}
