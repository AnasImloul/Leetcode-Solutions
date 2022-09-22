// Runtime: 81 ms (Top 98.19%) | Memory: 47.9 MB (Top 80.14%)
var generateTrees = function(n) {
    if(n <= 0){
        return [];
    }
    return generateRec(1, n);

};

function generateRec(start, end){
    let result = [];

    if(start > end){
        result.push(null);
        return result;
    }

    for(let i = start; i <end+1; i++){
        let left = generateRec(start, i-1);
        let right = generateRec(i+1, end);

        for(let l = 0; l < left.length; l++){
            for(let r = 0; r < right.length; r++){
                let root = new TreeNode(i,left[l], right[r]);
                result.push(root);
            }
        }

    }
    return result;

}