/**
 * @param {number[]} cards
 * @return {boolean}
1487
7-1 8-4
 */
var judgePoint24 = function(cards) {
    let minV = 0.00000001;
    let numL = [];
    cards.forEach(card=>numL.push(card));
    function judge(nums){
        if(nums.length === 1) return Math.abs(nums[0]-24)<=minV;
        else{
            for(let i = 0 ;i<nums.length;i++){
                for(let j = 0 ;j<i;j++){
                    let a = nums[i] ,b = nums[j];
                    let val =[a + b, a - b, b - a, a * b, a / b, b / a];
                    let copy =[...nums];
                    copy.splice(i,1);
                    copy.splice(j,1);
                    for(let v of val){
                        copy.push(v);
                        if (judge(copy)) {
                            return true;
                        }
                        copy.pop();
                    }
                }
            }
            return false;
        }
    }
    return judge(numL);
};
