var countPairs = function(nums, low, high) {
    function insert(num){
        var node = root;
        for(i = 14; i>=0; i--)
        {
            var bit = (num >> i) & 1;
            if(!node.children[bit])
            {
                node.children[bit] = new TrieNode();
            }
            node.children[bit].cnt += 1;
            node = node.children[bit];
        }
    }
    function countSmallerNums(num, limit)
    {
        var cnt = 0;
        // count pairs with num strictly smaller than limit
        var node = root;
        for(i = 14; i>=0 && node; i--)
        {
            var lbit = (limit>>i) & 1;
            var nbit = (num >> i) & 1;
            if(lbit===1)
            {
                // we can decrease on 1 bit
                if(node.children[nbit])
                {
                     cnt += node.children[nbit].cnt;
                }
                // go to another way to find next bit count
                node = node.children[1-nbit];
            }
            else
            {
                // cannot increase the lbit === 0,
                // find the same Nbit to XOR to be '0'
                node = node.children[nbit];
            }
        }
        return cnt;
    }
    // starts here
    var root = new TrieNode();
    var res =0;
    for(var num of nums)
    {
        res += countSmallerNums(num, high+1) -  countSmallerNums(num, low);
        insert(num);
    }
    return res;
};

class TrieNode{
    constructor()
    {
        this.cnt = 0;
        this.children = new Array(2).fill(null);
    }
}
