/**
 * @param {string} s
 * @return {string[]}
 */

 var printVertically = function(s)
{
    let arr = s.split(' '),
        max = arr.reduce((last, curr) => Math.max(last, curr.length), 0),
        ans = [];

    arr = arr.map(el => el + ' '.repeat(max - el.length));

    for (let i = 0; i < max; i++)
    {
        let word = '';

        for (let j = 0; j < arr.length; j++)
            word += arr[j][i];

        ans.push(word.replace(new RegExp('\\s+$'), ''));
    }

    return ans;
};
