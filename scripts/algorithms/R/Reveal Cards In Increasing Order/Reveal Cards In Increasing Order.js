// Runtime: 54 ms (Top 86.08%) | Memory: 44.10 MB (Top 46.84%)

var deckRevealedIncreasing = function(deck) {
    let result = [];
    deck = deck.sort((a,b) => b - a);
    for (let i = 0; i < deck.length; i++) {
      result.unshift(deck[i]);
      if (i !== deck.length-1) result.unshift(result.pop());
    }
    return result;
};
