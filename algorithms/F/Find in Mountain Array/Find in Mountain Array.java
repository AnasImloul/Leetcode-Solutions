class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeak(mountainArr);
        
        int left =binary(0,peak,mountainArr,target,true);
            if(left!=-1){
                return left;
            }
        int right= binary(peak+1,mountainArr.length()-1,mountainArr, target,false);
        return right;  
    }
    
    static int findPeak(MountainArray mountainArr){
        int start=0;
        int end =mountainArr.length()-1;
        
        while(start<end){
            int mid=start+((end-start)/2);
            
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return start;
    }
    
    static int binary(int low, int high, MountainArray arr,int target, boolean left){
            while(low<=high){
                int mid=low+((high-low)/2);
                if(target<arr.get(mid)){
                    if(left){
                        high=mid-1;
                    }else{
                         low=mid+1;
                    }   
                }else if(target>arr.get(mid)){
                    if(left){
                        low=mid+1;
                    }else{
                       high=mid-1; 
                    }    
                }else{
                    return mid;
                }
            } 
        return -1;
    }
}
