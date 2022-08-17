var minimumCardPickup = function(cards) {
    let cardsSeen = {};
    let minPicks = Infinity;
    for (let i = 0; i < cards.length; i++) {
        if (!(cards[i] in cardsSeen)) {
            cardsSeen[cards[i]] = i;
        } else {
            const temp = i - cardsSeen[cards[i]] + 1;
            minPicks = Math.min(minPicks, temp);
            cardsSeen[cards[i]] = i;
        }
    }
    return minPicks === Infinity ? -1 : minPicks;
};
