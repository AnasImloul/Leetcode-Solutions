var sortEvenOdd = function(nums) {

let odd= nums.filter((num,i,arr)=> i%2!=0).sort((a,b)=> b-a);  //decreasing order
let even= nums.filter((num,i,arr)=> i%2==0).sort((a,b)=> a-b); //increasing order
let x=0,y=0;
    
   nums.forEach((num,i,nums)=> {
        nums[i]= i%2==0 ? even[x++] : odd[y++];       //refilling the array 
    });
    return nums;
};




