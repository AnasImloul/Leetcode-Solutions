import java.math.BigInteger;
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int i;
        int hMax=horizontalCuts[0];
        for(i=1;i<horizontalCuts.length;i++)
            // if(hMax < horizontalCuts[i]-horizontalCuts[i-1])
                hMax=Math.max(hMax,horizontalCuts[i]-horizontalCuts[i-1]);
        if(h-horizontalCuts[horizontalCuts.length-1] > hMax)
            hMax= h-horizontalCuts[horizontalCuts.length-1];
        int vMax=verticalCuts[0];
        for(i=1;i<verticalCuts.length;i++)
            // if(vMax < verticalCuts[i]-verticalCuts[i-1])
                vMax=Math.max(vMax,verticalCuts[i]-verticalCuts[i-1]);
        if(w-verticalCuts[verticalCuts.length-1] > vMax)
            vMax= w-verticalCuts[verticalCuts.length-1];
        return (int)((long)hMax*vMax%1000000007);
    }
}
