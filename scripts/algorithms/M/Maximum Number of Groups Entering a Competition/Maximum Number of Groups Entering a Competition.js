/**
 * @param {number[]} grades
 * @return {number}
 */
var maximumGroups = function(grades) {
    let c = grades.length*2;
    return Math.floor((-1+Math.sqrt(1+4*c))/2)
};
