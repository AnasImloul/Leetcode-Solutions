/**
 * @param {number[]} piles
 * @param {number} k
 * @return {number}
 */

var minStoneSum = function(piles, k) {
    var heapArr = [];
    for (let i=0; i<piles.length; i++){
        heapArr.push(piles[i]);
        heapifyUp();
    }

    function heapifyUp(){
        let currIndex = heapArr.length-1;
        while (heapArr[currIndex] > heapArr[Math.floor((currIndex-1)/2)]){
            swap(currIndex, Math.floor((currIndex-1)/2));
            currIndex = Math.floor((currIndex-1)/2);
        }
    }
    
    function heapifyDown(){
        let currIndex = 0;
        let bigger = currIndex;
        while (heapArr[currIndex*2+1]){
            if (heapArr[currIndex] < heapArr[currIndex*2+1]){
                bigger = currIndex * 2 + 1;
            }
            
            if (heapArr[bigger] < heapArr[currIndex*2+2]){
                bigger = currIndex * 2 + 2;
            }
            
            if (bigger === currIndex){
                break;
            }
            swap(currIndex, bigger);
            currIndex = bigger;
        }
    }
    
    function swap(currIndex, otherIndex){
        let temp = heapArr[currIndex];
        heapArr[currIndex] = heapArr[otherIndex];
        heapArr[otherIndex] = temp;
    }
    
    while (k > 0){
        heapArr[0] -= Math.floor(heapArr[0]/2);
        heapifyDown();
        k--;
    }
    
    return heapArr.reduce((a,num) => a+num, 0);
};
