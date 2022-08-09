/**
 * @param {number[]} deck
 * @return {number[]}
 */
var deckRevealedIncreasing = function(deck) {
    // simulate the stack with the last revealed card at the top of the stack (index = 0)
    // => sort the deck in descending order
    let stack = deck.sort((a, b) => b - a)
    let queue = [stack.shift()]
        
    while (stack.length > 0) {
        // reverse the operation by shifting the last card of the queue to the start of the queue
        queue.unshift(queue.pop())
        // put the top card of the stack on the start of the queue
        queue.unshift(stack.shift())
    }
    
    return queue
    
};
