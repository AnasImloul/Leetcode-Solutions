/**
 * @param {number[]} values
 * @return {number}
 */
var maxScoreSightseeingPair = function(values) {
    let n=values.length,
        prevIndexMaxAddition=values[n-1],
        maxValue=-2;
    for(let i=n-2;i>-1;i--){
        let curIndexMaxAddition=Math.max(values[i],prevIndexMaxAddition-1);
        let curIndexMaxValue=values[i]+prevIndexMaxAddition-1;
        if(maxValue<curIndexMaxValue){
            maxValue=curIndexMaxValue;
        }
        prevIndexMaxAddition=curIndexMaxAddition;
    }
    return maxValue;
};
