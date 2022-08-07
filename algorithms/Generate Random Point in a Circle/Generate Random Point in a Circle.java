class Solution {
    double radius;
    double x_center;
    double y_center;
    Random r=new Random();
    public Solution(double radius, double x_center, double y_center) {
        this.radius=radius;
        this.x_center=x_center;
        this.y_center=y_center;
    }
    
    public double[] randPoint() {
        double angle=r.nextDouble(Math.PI*2);
		//For probability is inversely proportional to radius, we use sqrt of random number.
        double rad=Math.sqrt(r.nextDouble())*radius;
        double[] ret=new double[2];
        ret[0]=rad*Math.cos(angle)+x_center;
        ret[1]=rad*Math.sin(angle)+y_center;
        return ret;
    }
}

