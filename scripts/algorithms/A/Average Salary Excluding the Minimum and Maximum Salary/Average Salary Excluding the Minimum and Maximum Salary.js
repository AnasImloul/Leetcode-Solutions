// Runtime: 53 ms (Top 99.20%) | Memory: 42 MB (Top 50.52%)
var average = function(salary) {
    let max = salary[0], min = salary[salary.length-1], sum = 0;
    for(let i = 0; i < salary.length; i++) {
        if(salary[i] > max) {
            max = salary[i];
        }
        else if(salary[i] < min) {
            min = salary[i];
        }
        sum += salary[i];
    }
    return (sum-min-max)/(salary.length-2);
};