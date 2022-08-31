// Runtime: 123 ms (Top 25.53%) | Memory: 43.7 MB (Top 74.47%)
var partitionLabels = function(s) {
    let last = 0, first = 0;

    let arr = [...new Set(s)], ss = [];
    let temp = '';

    first = s.indexOf(arr[0]);
    last = s.lastIndexOf(arr[0]);

    for(let i = 1; i<arr.length; i++){
        if(s.indexOf(arr[i]) < last){
            if(last < s.lastIndexOf(arr[i])){
            last = s.lastIndexOf(arr[i]);
            }
        }
        else{
            temp = s.slice(first,last+1);
            ss.push(temp.length);
            first = s.indexOf(arr[i]);
            last = s.lastIndexOf(arr[i]);
        }
    }

    temp = s.slice(first,last+1);
    ss.push(temp.length);
    return ss;
};