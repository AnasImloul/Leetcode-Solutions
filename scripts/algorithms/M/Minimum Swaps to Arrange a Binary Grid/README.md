<h3 align="left"> 1536. Minimum Swaps to Arrange a Binary Grid</h3>
<div><p>Given an <code>n x n</code> binary <code>grid</code>, in one step you can choose two <strong>adjacent rows</strong> of the grid and swap them.</p>

<p>A grid is said to be <strong>valid</strong> if all the cells above the main diagonal are <strong>zeros</strong>.</p>

<p>Return <em>the minimum number of steps</em> needed to make the grid valid, or <strong>-1</strong> if the grid cannot be valid.</p>

<p>The main diagonal of a grid is the diagonal that starts at cell <code>(1, 1)</code> and ends at cell <code>(n, n)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/28/fw.jpg" style="width: 750px; height: 141px;">
<pre><strong>Input:</strong> grid = [[0,0,1],[1,1,0],[1,0,0]]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/16/e2.jpg" style="width: 270px; height: 270px;">
<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> All rows are similar, swaps have no effect on the grid.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/16/e3.jpg" style="width: 200px; height: 200px;">
<pre><strong>Input:</strong> grid = [[1,0,0],[1,1,0],[1,1,1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code> <code>== grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code></li>
</ul>
</div>