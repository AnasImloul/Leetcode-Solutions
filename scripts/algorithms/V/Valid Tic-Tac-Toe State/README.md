<h3 align="left"> 794. Valid Tic-Tac-Toe State</h3>
<div><p>Given a Tic-Tac-Toe board as a string array <code>board</code>, return <code>true</code> if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.</p>

<p>The board is a <code>3 x 3</code> array that consists of characters <code>' '</code>, <code>'X'</code>, and <code>'O'</code>. The <code>' '</code> character represents an empty square.</p>

<p>Here are the rules of Tic-Tac-Toe:</p>

<ul>
	<li>Players take turns placing characters into empty squares <code>' '</code>.</li>
	<li>The first player always places <code>'X'</code> characters, while the second player always places <code>'O'</code> characters.</li>
	<li><code>'X'</code> and <code>'O'</code> characters are always placed into empty squares, never filled ones.</li>
	<li>The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.</li>
	<li>The game also ends if all squares are non-empty.</li>
	<li>No more moves can be played if the game is over.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> board = ["O  ","   ","   "]
<strong>Output:</strong> false
<strong>Explanation:</strong> The first player always plays "X".
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> board = ["XOX"," X ","   "]
<strong>Output:</strong> false
<strong>Explanation:</strong> Players take turns making moves.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe4-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> board = ["XOX","O O","XOX"]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 3</code></li>
	<li><code>board[i].length == 3</code></li>
	<li><code>board[i][j]</code> is either <code>'X'</code>, <code>'O'</code>, or <code>' '</code>.</li>
</ul>
</div>