/**
 * @param {number[]} arr
 * @param {number} start
 * @return {boolean}
 */
var canReach = function(arr, start) {
        let queue = [start];
        while(queue.length) {
            let index = queue.shift();
            if(index >= 0 && index < arr.length && arr[index] >=0 ){
                if(arr[index] === 0)return true;
                let move = arr[index]
                arr[index] = -1   
                queue.push(index +move , index-move)
            }
        }
    return false;
};