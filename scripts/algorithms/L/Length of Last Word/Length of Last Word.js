var lengthOfLastWord = function(s) {
    s = s.split(" ");
    if(s[s.length-1] == ``)
    {
        for(var i = s.length-1; i >= 0; i-- )
        {
            if(s[i].length > 0)
            {
                return s[i].length;
            }
        }
    }
    else
    {
        return s[s.length-1].length;
    }
};
