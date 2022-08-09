var maxValue = function(n, index, maxSum) {
    function getSum(len,v){
        var sum = 0;
        if(len<=v)
        {
            sum = (2*v-len+1) * len / 2;
        }
        else
        {
             sum = (1+v)*v/2 + len - v;
        }
        return sum;
    }
    function isValid(mid)
    {
        var curSum = getSum(leftLen,mid) + getSum(rightLen, mid) - mid;
        return curSum<=maxSum;
    }
    var l = 0;
    var r = 1000000000;
    var leftLen = (index+1);
    var rightLen = n-index;
    while(l<r)
    {
        var mid = Math.ceil((l+r)/2); // handle dead loop when l===r & l=mid
        if(!isValid(mid))
        {
            r = mid-1;
        }
        else
        {
            l = mid;
        }
    }
    return l;
};
