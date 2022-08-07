/**
 * The recursive solution with memoization.
 * This solution doesn't use `string.slice()`, but pass substring boundaries directly to function calls.
 * 
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n^2)
 * 
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
	return checkScramble(s1, 0, s1.length, s2, 0, s2.length)
}


function checkScramble(string1, i1, j1, string2, i2, j2, memory = {}) {
	const n   = j1 - i1
	const key = 1e9 * i1 + 1e6 * j1 + 1e3 * i2 + 1e0 * j2

	if (key in memory) {
		return memory[key]
	}

	let codesum = 0

	for (let i = 0; i < n; i++) {
		codesum += string1.charCodeAt(i1 + i) ** 2 - string2.charCodeAt(i2 + i) ** 2
	}

	if (codesum !== 0) {
		return memory[key] = false
	}

	if (n === 1) {
		return memory[key] = true
	}

	for (let i = 1; i < n; i++) {
		if (
			checkScramble(string1, i1, i1 + i, string2, i2, i2 + i, memory)
			&&
			checkScramble(string1, i1 + i, j1, string2, i2 + i, j2, memory)
		) {
			return memory[key] = true
		}

		if (
			checkScramble(string1, i1, i1 + i, string2, j2 - i, j2, memory)
			&&
			checkScramble(string1, i1 + i, j1, string2, i2, j2 - i, memory)
		) {
			return memory[key] = true
		}
	}    

	return memory[key] = false
}
