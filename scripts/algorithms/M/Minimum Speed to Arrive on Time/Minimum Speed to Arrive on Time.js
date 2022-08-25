// Runtime: 154 ms (Top 97.67%) | Memory: 53.7 MB (Top 79.07%)
var minSpeedOnTime = function(dist, hour) {
    let left=1,right=10000000,speed,sum,ans=-1;
    while(left<=right){
        //We need to return the minimum positive integer speed (in kilometers per hour) that all the trains must travel. So speed will always be an integer ranging from 1 to 10000000 as per the question description.
        speed = left + Math.floor((right-left)/2);
        sum=0;
        for(let i=0;i<dist.length-1;i++){
            sum += Math.ceil((dist[i]/speed));
        }
        sum += (dist[dist.length-1]/speed);//For the last train we need not to do Math.ceil
        if(sum<=hour){//sum(time taken is less than the required time, so it can be our answer, but we will keep looking for the another smaller speed until left<=right)
            ans=speed;
            right = speed-1;
        }else{
            left=speed+1;
        }
    }
    return ans;
};