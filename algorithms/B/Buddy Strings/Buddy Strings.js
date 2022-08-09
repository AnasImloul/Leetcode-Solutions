/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var buddyStrings = function(s, goal) {
    if (s.length !== goal.length) return false;
	// if there are same chars in s and s is the same as goal, s is the buddy string.
	// Because we can swap this char to keep the string same as origin
    if (s === goal) return s.length > new Set(s).size;
    const temp = [];
    for (let i = 0; i < goal.length; i++) {
        if (s[i] !== goal[i]) {
            temp.push(s[i], goal[i]);
        }
    }
	// If it's buddy string, we can get the array, which has four chars.
	// [ s[n], goal[n], s[m], goal[m] ]
    //  if s ="xxabxx", goal="xxbaxx", we will get [ a, b, b, a] for example
	// Because after we swap the char in n and char in m, we can get the same string
	// If it's buddy string, s[n] is different with goal[n] and s[m], which means s[n] === goal[m] and s[m] === goal[n];
    return temp.length === 4 && temp[0] === temp[3] && temp[1] === temp[2];
};
