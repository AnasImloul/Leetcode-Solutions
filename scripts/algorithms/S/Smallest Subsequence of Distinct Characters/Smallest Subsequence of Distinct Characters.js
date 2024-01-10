// Runtime: 50 ms (Top 94.83%) | Memory: 42.10 MB (Top 87.93%)

var smallestSubsequence = function(s) {
    // Initialize an empty stack to store the result
    let stack = [];

    // Iterate through each character in the input string
    for (let i = 0; i < s.length; i++) {
        let char = s[i];

        // If the character is already in the stack, skip it
        if (stack.indexOf(char) > -1) continue;

        // Check and pop elements from the stack to maintain lexicographical order
        while (
            stack.length > 0 &&
            stack[stack.length - 1] > char &&
            s.indexOf(stack[stack.length - 1], i) > i
        ) {
            stack.pop();
        }

        // Push the current character onto the stack
        stack.push(char);
    }

    // Join the characters in the stack to form the smallest subsequence
    return stack.join('');
};
