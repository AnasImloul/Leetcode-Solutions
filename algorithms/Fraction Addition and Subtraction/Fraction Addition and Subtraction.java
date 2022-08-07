class Solution {
    //Great Common Divisor 
    private int gcd(int a,int b) {
        int r=b%a;
        if (r==0) return a;
        return gcd(r,a);
    }
    private int[] add(int[] a,int[] b){
        if(a[0]==0) return b;
        if(b[0]==0) return a;
        int[] ret=new int[]{a[0]*b[1]+b[0]*a[1],a[1]*b[1]};
        if(ret[0]==0){
           ret[1]=1;
           return ret; 
        }
        int sign=ret[0]<0?-1:1;
        ret[0]*=sign;
        int g=gcd(Math.min(ret[0],ret[1]),Math.max(ret[0],ret[1]));
        if(g>1) {
           ret[0]/=g;
           ret[1]/=g; 
        }
        ret[0]*=sign;
        return ret;
    }
    public String fractionAddition(String expression) {
        return Stream.of(
        expression.replaceAll("\\-","+-").split("\\+")).filter(s->s.length()>0).map(
        s->s.split("/")).map(
        a->new int[]{Integer.parseInt(a[0]),Integer.parseInt(a[1])}).reduce((a,b)->add(a,b)).map(p->p[0]+"/"+p[1]).get();
       
    }
}
