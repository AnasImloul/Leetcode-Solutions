// Runtime: 112 ms (Top 15.11%) | Memory: 42.1 MB (Top 57.33%)
var countStudents = function(students, sandwiches) {
while (students.length>0 && students.indexOf(sandwiches[0])!=-1) {
    if (students[0] == sandwiches[0]) {
        students.shift();
        sandwiches.shift();
    }
    else students.push(students.shift());
}
return students.length
};