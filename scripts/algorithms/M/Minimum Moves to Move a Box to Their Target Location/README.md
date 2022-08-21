<h3 align="left"> 1263. Minimum Moves to Move a Box to Their Target Location</h3>
<div><p>A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.</p>

<p>The game is represented by an <code>m x n</code> grid of characters <code>grid</code> where each element is a wall, floor, or box.</p>

<p>Your task is to move the box <code>'B'</code> to the target position <code>'T'</code> under the following rules:</p>

<ul>
	<li>The character <code>'S'</code> represents the player. The player can move up, down, left, right in <code>grid</code> if it is a floor (empty cell).</li>
	<li>The character <code>'.'</code> represents the floor which means a free cell to walk.</li>
	<li>The character <code>'#' </code>represents the wall which means an obstacle (impossible to walk there).</li>
	<li>There is only one box <code>'B'</code> and one target cell <code>'T'</code> in the <code>grid</code>.</li>
	<li>The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a <strong>push</strong>.</li>
	<li>The player cannot walk through the box.</li>
</ul>

<p>Return <em>the minimum number of <strong>pushes</strong> to move the box to the target</em>. If there is no way to reach the target, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png" style="width: 500px; height: 335px;">
<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#",".","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We return only the number of times the box is pushed.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#","#","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
<strong>Output:</strong> -1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [["#","#","#","#","#","#"],
               ["#","T",".",".","#","#"],
               ["#",".","#","B",".","#"],
               ["#",".",".",".",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> push the box down, left, left, up and up.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>grid</code> contains only characters <code>'.'</code>, <code>'#'</code>, <code>'S'</code>, <code>'T'</code>, or <code>'B'</code>.</li>
	<li>There is only one character <code>'S'</code>, <code>'B'</code>, and <code>'T'</code> in the <code>grid</code>.</li>
</ul>
</div>