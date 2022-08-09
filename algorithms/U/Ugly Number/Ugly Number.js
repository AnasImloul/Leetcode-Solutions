var isUgly = function(n) {
    let condition = true;
    if(n == 0)  // 0 has infinite factors. So checking if the number is 0 or not
        return false;
    while(condition){   //applying for true until 2, 3, 5 gets removed from the number
        if(n % 2 == 0)
            n = n / 2;
        else if(n % 3 == 0)
            n = n / 3;
        else if(n % 5 == 0)
            n = n / 5;
        else
        condition = false; //if the number doesnt have 2, 3, 5 in it anymore, this part will execute and will end the while loop
    }
    return n == 1 ? true : false;//checking if the number only had 2, 3, 5 in it or had something else in it as well
};
