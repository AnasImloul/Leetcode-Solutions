<h3 align="left"> 883. Projection Area of 3D Shapes</h3>
<div><p>You are given an <code>n x n</code> <code>grid</code> where we place some <code>1 x 1 x 1</code> cubes that are axis-aligned with the <code>x</code>, <code>y</code>, and <code>z</code> axes.</p>

<p>Each value <code>v = grid[i][j]</code> represents a tower of <code>v</code> cubes placed on top of the cell <code>(i, j)</code>.</p>

<p>We view the projection of these cubes onto the <code>xy</code>, <code>yz</code>, and <code>zx</code> planes.</p>

<p>A <strong>projection</strong> is like a shadow, that maps our <strong>3-dimensional</strong> figure to a <strong>2-dimensional</strong> plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.</p>

<p>Return <em>the total area of all three projections</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/02/shadow.png" style="width: 800px; height: 214px;">
<pre><strong>Input:</strong> grid = [[1,2],[3,4]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[2]]
<strong>Output:</strong> 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,2]]
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>
</div>