class Solution {
    public double[] sampleStats(int[] count) {
        double[]ans=new double[5];
        ans[0]=-1;
        ans[1]=-1;
        int place=0;
        while(ans[0]==-1){
            if(count[place]>0)
                ans[0]=place;
            place++;
        }
        place=count.length-1;
        while(ans[1]==-1){
             if(count[place]>0)
                ans[1]=place;
            place--;
        }
        int countEl=count[0];
        int max=count[0];
        for(int i=1;i<count.length;i++){
            countEl+=count[i];
            if(count[i]>max){
                max=count[i];
                ans[4]=i;
            }
        }
        for(int i=0;i<count.length;i++){
            if(count[i]>0){
                double tmp=count[i];
                tmp/=countEl;
                ans[2]+=tmp*i;
            }
        }
        place=0;
        int whereToStop=0;
        while(whereToStop<countEl/2){
            whereToStop+=count[place];
            place++;
        }
        place--;
        if(countEl%2==1){
            if(whereToStop==countEl/2){
                place++;
                while(count[place]==0)
                    place++;
            }
                
            ans[3]=place;
        }
        else{
            double tmp=place;
            if(whereToStop==countEl/2){
                place++;
                while(count[place]==0)
                    place++;
            }
            tmp+=place;
            ans[3]=tmp/2;
        }
        return ans;
    }
}