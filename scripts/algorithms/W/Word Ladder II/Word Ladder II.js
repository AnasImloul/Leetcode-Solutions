// Runtime: 101 ms (Top 95.15%) | Memory: 44.2 MB (Top 99.56%)
const isMatch = (currWord, nextWord) => {
    let mismatch = 0;
    for(let i = 0; i < nextWord.length; i += 1) {
        if(nextWord[i] !== currWord[i]) {
            mismatch += 1;
        }
    }

    return mismatch === 1;
}

const getNextWords = (lastRung, dictionary) => {
    const nextWords = [];
    for(const word of dictionary) {
        if(isMatch(word, lastRung)) {
            nextWords.push(word);
        }
    }

    return nextWords;
}

const updateLadders = (ladders, dictionary) => {
    const updatedLadders = [];
    const nextRung = new Set();

    for(const ladder of ladders) {
        const nextWords = getNextWords(ladder[ladder.length - 1], dictionary);
        for(const nextWord of nextWords) {
            updatedLadders.push([...ladder, nextWord]);
            nextRung.add(nextWord);
        }
    }

    return [updatedLadders, nextRung];
}

const updateDictionary = (dictionary, nextRung) => {
    return dictionary.filter((word) => !nextRung.has(word));
}

// BFS traversal from endWord to beginWord
// This limits the paths that we'll need to consider during our traversal from beingWord to endWord
const getDictionary = (wordList, endWord, beginWord) => {
    const dictionary = new Set();

    let currRung = [endWord];
    while(currRung.length > 0) {
        const nextRung = new Set();
        if(!wordList.includes(beginWord)) break;

        while(currRung.length > 0) {
            const currWord = currRung.pop();
            dictionary.add(currWord);

            for(const nextWord of wordList) {
                if(isMatch(currWord, nextWord)) {
                    nextRung.add(nextWord);
                }
            }
        }

        currRung = [...nextRung];
        wordList = wordList.filter((word) => !nextRung.has(word));
    }

    return [...dictionary];
}

var findLadders = function(beginWord, endWord, wordList) {
    if(!wordList.includes(endWord)) return [];
    if(!wordList.includes(beginWord)) wordList.push(beginWord);

    const result = [];
    const saveResult = (ladders) => {
        for(const ladder of ladders) {
            if(ladder[ladder.length - 1] === endWord) {
                result.push(ladder);
            }
        }
    }

    let ladders = [[beginWord]];
    let dictionary = getDictionary(wordList, endWord, beginWord);
    while(ladders.length > 0) {
        if(!dictionary.includes(endWord)) {
            saveResult(ladders);
            break;
        }

        const [updatedLadders, nextRung] = updateLadders(ladders, dictionary);
        ladders = updatedLadders;
        dictionary = updateDictionary(dictionary, nextRung);
    }

    return result;
};