var memLeak = function(memory1, memory2) {
    var count=1;
    while(true)
        {
            if(memory1>=memory2 && memory1>=count)
                memory1-=count;
            else if(memory2>=memory1 && memory2>=count)
                memory2-=count
            else
                return [count, memory1, memory2];
            count++;
        }
};
