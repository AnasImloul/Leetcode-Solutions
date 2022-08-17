var isThree = function(n) {
    var set = new Set();
    for(var i = 1; i<=Math.sqrt(n) && set.size <= 3; i++)
    {
        if(n % i === 0)
        {
            set.add(i);
            set.add(n / i);
        }
    }
    return set.size===3;  
};
