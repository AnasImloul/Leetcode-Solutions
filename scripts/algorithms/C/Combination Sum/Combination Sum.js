// Runtime: 113 ms (Top 76.66%) | Memory: 45.7 MB (Top 51.16%)
function recursion(index, list, target, res, arr){
    if(index == arr.length){
        if(target == 0){
            res.push([...list]);
        }
        return;
    }

    if(arr[index] <= target){

         list.push(arr[index]);

         recursion(index, list, target - arr[index], res, arr);

         list.pop();

    }

    recursion(index + 1, list, target, res, arr);

}
var combinationSum = function(candidates, target) {
    let res = [];
    recursion(0, [], target, res, candidates);
    return res;
};