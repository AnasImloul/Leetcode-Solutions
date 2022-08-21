<h3 align="left"> 999. Available Captures for Rook</h3>
<div><p>On an <code>8 x 8</code> chessboard, there is <strong>exactly one</strong> white rook <code>'R'</code> and some number of white bishops <code>'B'</code>, black pawns <code>'p'</code>, and empty squares <code>'.'</code>.</p>

<p>When the rook moves, it chooses one of four cardinal directions (north, east, south, or west), then moves in that direction until it chooses to stop, reaches the edge of the board, captures a black pawn, or is blocked by a white bishop. A rook is considered <strong>attacking</strong> a pawn if the rook can capture the pawn on the rook's turn. The <strong>number of available captures</strong> for the white rook is the number of pawns that the rook is <strong>attacking</strong>.</p>

<p>Return <em>the <strong>number of available captures</strong> for the white rook</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/20/1253_example_1_improved.PNG" style="width: 300px; height: 305px;">
<pre><strong>Input:</strong> board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, the rook is attacking all the pawns.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/19/1253_example_2_improved.PNG" style="width: 300px; height: 306px;">
<pre><strong>Input:</strong> board = [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The bishops are blocking the rook from attacking any of the pawns.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/20/1253_example_3_improved.PNG" style="width: 300px; height: 305px;">
<pre><strong>Input:</strong> board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The rook is attacking the pawns at positions b5, d6, and f5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 8</code></li>
	<li><code>board[i].length == 8</code></li>
	<li><code>board[i][j]</code> is either <code>'R'</code>, <code>'.'</code>, <code>'B'</code>, or <code>'p'</code></li>
	<li>There is exactly one cell with <code>board[i][j] == 'R'</code></li>
</ul>
</div>