/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function(answers) {
    
    var totalRabbits = 0;
    var sumOfLikeAnswers = new Array(1000).fill(0);
    
    for (let i = 0; i < answers.length; i++) {
        sumOfLikeAnswers[answers[i]] += 1;
    }
    
    for (let i = 0; i < sumOfLikeAnswers.length; i++) {
        totalRabbits += Math.ceil(sumOfLikeAnswers[i] / (i+1)) * (i+1);
    }
    
    return totalRabbits;
};
