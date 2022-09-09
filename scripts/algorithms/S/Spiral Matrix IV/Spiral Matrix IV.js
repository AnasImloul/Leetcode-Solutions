// Runtime: 1122 ms (Top 6.48%) | Memory: 103.4 MB (Top 52.52%)

 var spiralMatrix = function(m, n, head) {
    var matrix = new Array(m).fill().map(()=> new Array(n).fill(-1))
    var row=0, col=0;
    var direction="right";
    while(head)
        {
            matrix[row][col]=head.val;
            if(direction=="right")
                {
                    if(col+1 == n || matrix[row][col+1] != -1)
                        {
                            direction="down"
                            row++;
                        }
                    else
                        col++
                }
            else if(direction=="down")
                {
                    if(row+1 == m || matrix[row+1][col] != -1)
                        {
                            direction="left"
                            col--;
                        }
                    else
                        row++
                }
            else if(direction=="left")
                {
                    if(col == 0 || matrix[row][col-1] != -1)
                        {
                            direction="up"
                            row--;
                        }
                    else
                        col--
                }
            else if(direction=="up")
                {
                    if(row == 0 || matrix[row-1][col] != -1)
                        {
                            direction="right"
                            col++;
                        }
                    else
                        row--
                }
            head = head.next;
        }
    return matrix;
};