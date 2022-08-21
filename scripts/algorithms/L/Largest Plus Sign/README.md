<h3 align="left"> 764. Largest Plus Sign</h3>
<div><p>You are given an integer <code>n</code>. You have an <code>n x n</code> binary grid <code>grid</code> with all values initially <code>1</code>'s except for some indices given in the array <code>mines</code>. The <code>i<sup>th</sup></code> element of the array <code>mines</code> is defined as <code>mines[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> where <code>grid[x<sub>i</sub>][y<sub>i</sub>] == 0</code>.</p>

<p>Return <em>the order of the largest <strong>axis-aligned</strong> plus sign of </em>1<em>'s contained in </em><code>grid</code>. If there is none, return <code>0</code>.</p>

<p>An <strong>axis-aligned plus sign</strong> of <code>1</code>'s of order <code>k</code> has some center <code>grid[r][c] == 1</code> along with four arms of length <code>k - 1</code> going up, down, left, and right, and made of <code>1</code>'s. Note that there could be <code>0</code>'s or <code>1</code>'s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for <code>1</code>'s.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/plus1-grid.jpg" style="width: 404px; height: 405px;">
<pre><strong>Input:</strong> n = 5, mines = [[4,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In the above grid, the largest plus sign can only be of order 2. One of them is shown.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/plus2-grid.jpg" style="width: 84px; height: 85px;">
<pre><strong>Input:</strong> n = 1, mines = [[0,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no plus sign, so return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= mines.length &lt;= 5000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt; n</code></li>
	<li>All the pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are <strong>unique</strong>.</li>
</ul>
</div>