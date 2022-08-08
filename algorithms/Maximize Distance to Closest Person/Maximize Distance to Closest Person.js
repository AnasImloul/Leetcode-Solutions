/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
    let arr = seats.join('').split('1');
    for(let i = 0; i < arr.length;i++){
        if(arr[i] == '')
            arr[i] = 0;
        else{
            let middle = true;
            if(i == 0 || i == arr.length-1){
                arr[i] = arr[i].length;
            }else {
                arr[i] = Math.ceil(arr[i].length/2);
            } 
        }
    }
    return arr.sort((a,b) => (a >= b)?-1:1)[0]
};