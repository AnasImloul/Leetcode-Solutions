// Runtime: 96 ms (Top 43.16%) | Memory: 42.5 MB (Top 14.74%)
var removeComments = function(source) {
    let result = [];
    let multi_line_comment = false;
    let str = "";

    source.forEach(line => {
        for(let idx=0; idx < line.length; ++idx) {
            // if /* is not ongoing, check for start of a comment or not
            if(!multi_line_comment) {
                // if comment is //, ignore the rest of the line
                if(line[idx] + line[idx+1] === '//') {
                    break;
                }
                // if comment if /*, set multi-line flag and move to next index
                else if(line[idx] + line[idx+1] === '/*') {
                    multi_line_comment = true;
                    ++idx;
                }
                // if not a comment start, add to string to be added to result
                else {
                    str += line[idx];
                }
            }
            // if /* comment is ongoing
            else {
                // if closing comment */ is encountered, set multi-line flag off and move to next index
                if(line[idx] + line[idx+1] === '*/') {
                    multi_line_comment = false;
                    ++idx;
                }
            }
        }
        // if /* comment is not ongoing and str is not empty, add to result as one code line
        if(str.length && !multi_line_comment) {
            result.push(str);
            str = ""; //reset the str
        }
    })
    return result;
}
