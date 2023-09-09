// Runtime: 65 ms (Top 58.3%) | Memory: 50.03 MB (Top 41.6%)

var maximumGroups = function(grades) {
    var count=1, length=grades.length;
    while(length-count > count) length-=count++;
    return count;
};