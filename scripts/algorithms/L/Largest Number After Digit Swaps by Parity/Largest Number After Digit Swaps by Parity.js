/**
 * @param {number} num
 * @return {number}
 */
var largestInteger = function(num) {
    var nums = num.toString().split("");//splitting the numbers into an array
    var odd=[];//helps keep a track of odd numbers
    var even =[];//helps keep a track of even numbers
    for(var i=0;i<nums.length;i++){
        if(nums[i]%2===0) //pushing even numbers to even array
            even.push(nums[i]);
        else//pushing odd numbers to odd array
            odd.push(nums[i]);
    }
    odd.sort((a,b)=>a-b);//sorting the arrays in ascending order
    even.sort((a,b)=>a-b);
    var ans =[];
    for(var i=0;i<nums.length;i++){
        if(nums[i]%2===0){//replacing even with even
            ans.push(even[even.length-1]);//pushing the greatest even number in the ans
            even.pop();//popping the used number
        }
        else{//replacing odd with odd
            ans.push(odd[odd.length-1]);//pushing the greatest odd number in the ans
            odd.pop();//popping the used number
        }
    }
    var ans2 = parseInt(ans.join(""));//converting the ans array into an int number
    return ans2;

};
