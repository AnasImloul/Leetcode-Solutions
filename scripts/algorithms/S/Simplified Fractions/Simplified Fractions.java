// Runtime: 42 ms (Top 52.04%) | Memory: 73.5 MB (Top 36.20%)
class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> list = new ArrayList<>() ;

        for(int numerator = 1; numerator< n ; numerator++) {
            for(int denominator = numerator+1; denominator<=n; denominator++) {
                if(gcd(numerator,denominator) == 1) {
                    list.add(numerator+"/"+denominator);
// System.out.println(numerator+"/"+denominator);
                }
            }
        }
        return list ;
    }

    static int gcd(int a, int b)
    {
// euclidean algo

        if(a==0) {
            return b ;
        }
        return gcd(b%a,a);
    }
}