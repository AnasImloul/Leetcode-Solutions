// Runtime: 38 ms (Top 16.51%) | Memory: 44.40 MB (Top 27.52%)

class Solution {
    private int gcd(int x, int y){
        return x!=0?gcd(y%x, x):Math.abs(y);
    }

    public String fractionAddition(String exp) {
        Scanner sc = new Scanner(exp).useDelimiter("/|(?=[-+])");

        int A=0, B=1;
        while(sc.hasNext()){
            int a = sc.nextInt(), b=sc.nextInt();
            A = A * b + B * a;
            B *= b;

            int gcdX = gcd(A, B);
            A/=gcdX;
            B/=gcdX;
        }
        return A+"/"+B;
    }
}
