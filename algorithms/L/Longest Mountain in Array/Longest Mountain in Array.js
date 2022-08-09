var longestMountain = function(arr) {
    let len=arr.length;
    let climbUp=false;
    let climbDown=false;
    let countUp=0;
    let countDown=0;
    let distance=0;
    let max=0; 
    if(len<3){
        return 0;
    }
    for(i=0;i<len;i++){
        if(arr[i-1]<arr[i]){
        countUp++;
        climbUp=true;   
        }else if(arr[i-1]>arr[i] && climbUp){
        countDown++; 
        climbDown=true;
        }
        if((arr[i-1]>=arr[i] && arr[i]<=arr[i+1]) || (i==len-1 && climbDown==true)){
            distance=countUp+countDown+1;
            if(max<distance && climbUp && climbDown){
                max=distance;
            }
            countUp=0;
            countDown=0;
            climbUp=false;
            climbDown=false;
        }
        if(arr[i+1]==arr[i]){
            climbUp=false;
            climbDown=false;
        }
    }
   return(max<3?0:max)
};
