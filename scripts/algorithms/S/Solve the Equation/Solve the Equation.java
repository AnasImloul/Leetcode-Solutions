class Solution {
    public int[] simplifyEqn(String eqn){
        int prevSign = 1;
        int sumX = 0;
        int sumNums = 0;
        for(int i=0;i<eqn.length();){
            int coEff = 0;
            int j = i;
            while(j<eqn.length() && Character.isDigit(eqn.charAt(j))){
                coEff = coEff*10 + (eqn.charAt(j)-'0');
                j++;
            }
            if(j<eqn.length() && eqn.charAt(j)=='x'){
                if(i==j)
                    coEff = 1;
                sumX += prevSign*coEff;
                j++;
            }
            else{
                sumNums += prevSign*coEff; 
            }
            if(j<eqn.length() && eqn.charAt(j)=='+')
                prevSign = 1;
            else if(j<eqn.length() && eqn.charAt(j)=='-')
                prevSign = -1;
            i=++j;
        }
        return new int[] {sumX, sumNums};
    }
    public String solveEquation(String equation) {
        String[] leftNRight = equation.split("=");
        String left = leftNRight[0], right = leftNRight[1];
        int[] leftEqn = simplifyEqn(left);
        int[] rightEqn = simplifyEqn(right);
        int x = leftEqn[0]-rightEqn[0];
        int num = rightEqn[1]-leftEqn[1];
        if(x==0)
            if(num==0)
                return "Infinite solutions";
            else
                return "No solution";
        return "x="+num/x;
    }
}