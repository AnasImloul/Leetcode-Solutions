// Runtime: 799 ms (Top 28.57%) | Memory: 86.3 MB (Top 42.86%)
/**
 * @param {number[]} packages
 * @param {number[][]} boxes
 * @return {number}
 */
var minWastedSpace = function(packages, boxes) {
    let count=0,b,minWastage,totalPackagesSize=0n,minBoxesAreaForAnySupplier=BigInt(Number.MAX_SAFE_INTEGER),boxesArea=0n,p,coverdPackagesIndex,totalBoxesAreaForSupplier;
    packages.sort(function(a,b){return a-b});
    for(let i=0;i<packages.length;i++){
        totalPackagesSize+=BigInt(packages[i]);
    }

    for(let i=0;i<boxes.length;i++){
        boxes[i].sort(function(a,b){return a-b});
        p=0;
        totalBoxesAreaForSupplier=0n;
        if(boxes[i][boxes[i].length-1]<packages[packages.length-1]){//This supplier is not big enough box for the largest package, hence this supplier can't be used.
            continue;
        }
        for(let b=0;b<boxes[i].length;b++){
            coverdPackagesIndex = binaryLowerBound(packages,p,packages.length-1,boxes[i][b]);
            if(coverdPackagesIndex!==-1){
                totalBoxesAreaForSupplier+=BigInt(boxes[i][b])*BigInt(coverdPackagesIndex-p+1);
                p=coverdPackagesIndex+1;
                if(p===packages.length){
                    break;
                }
            }
        }
        if(p===packages.length){//Check if the current supplier was able to pack all the packages.
            if(totalBoxesAreaForSupplier<minBoxesAreaForAnySupplier){
                minBoxesAreaForAnySupplier = totalBoxesAreaForSupplier;
            }
        }
    }
    if(minBoxesAreaForAnySupplier!==BigInt(Number.MAX_SAFE_INTEGER)){
        return (minBoxesAreaForAnySupplier-totalPackagesSize)%1000000007n;
    }else{
        return -1;
    }

    function binaryLowerBound(arr,left,right,key){
        let mid,ans=-1;
        while(left<=right){
            mid = left + Math.floor((right-left)/2);
            if(arr[mid]<=key){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};