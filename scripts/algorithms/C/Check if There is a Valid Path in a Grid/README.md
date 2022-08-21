<h3 align="left"> 1391. Check if There is a Valid Path in a Grid</h3>
<div><p>You are given an <code>m x n</code> <code>grid</code>. Each cell of <code>grid</code> represents a street. The street of <code>grid[i][j]</code> can be:</p>

<ul>
	<li><code>1</code> which means a street connecting the left cell and the right cell.</li>
	<li><code>2</code> which means a street connecting the upper cell and the lower cell.</li>
	<li><code>3</code> which means a street connecting the left cell and the lower cell.</li>
	<li><code>4</code> which means a street connecting the right cell and the lower cell.</li>
	<li><code>5</code> which means a street connecting the left cell and the upper cell.</li>
	<li><code>6</code> which means a street connecting the right cell and the upper cell.</li>
</ul>
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/main.png" style="width: 450px; height: 708px;">
<p>You will initially start at the street of the upper-left cell <code>(0, 0)</code>. A valid path in the grid is a path that starts from the upper left cell <code>(0, 0)</code> and ends at the bottom-right cell <code>(m - 1, n - 1)</code>. <strong>The path should only follow the streets</strong>.</p>

<p><strong>Notice</strong> that you are <strong>not allowed</strong> to change any street.</p>

<p>Return <code>true</code><em> if there is a valid path in the grid or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/e1.png" style="width: 455px; height: 311px;">
<pre><strong>Input:</strong> grid = [[2,4,3],[6,5,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/05/e2.png" style="width: 455px; height: 293px;">
<pre><strong>Input:</strong> grid = [[1,2,1],[1,2,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 6</code></li>
</ul>
</div>