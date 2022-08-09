var checkString = function(s) {
    
    // a cannot come after b
    let violation = "ba";
    
    return s.indexOf(violation, 0) == -1;
};
