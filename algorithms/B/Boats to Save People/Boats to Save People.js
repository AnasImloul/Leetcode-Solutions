/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
    people = people.sort((a,b) => a - b)

    let left = 0
    let right = people.length - 1
    let res = 0
    
    while (left <= right) {
       if (people[left] + people[right] <= limit) {
           res++
           right--
           left++
       } else if (people[right] <= limit) {
           res++ 
           right--
       }
    }
    
    return res
};
