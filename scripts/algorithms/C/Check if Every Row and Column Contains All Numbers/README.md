<h3 align="left"> 2133. Check if Every Row and Column Contains All Numbers</h3>
<div><p>An <code>n x n</code> matrix is <strong>valid</strong> if every row and every column contains <strong>all</strong> the integers from <code>1</code> to <code>n</code> (<strong>inclusive</strong>).</p>

<p>Given an <code>n x n</code> integer matrix <code>matrix</code>, return <code>true</code> <em>if the matrix is <strong>valid</strong>.</em> Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png" style="width: 250px; height: 251px;">
<pre><strong>Input:</strong> matrix = [[1,2,3],[3,1,2],[2,3,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png" style="width: 250px; height: 251px;">
<pre><strong>Input:</strong> matrix = [[1,1,1],[1,2,3],[1,2,3]]
<strong>Output:</strong> false
<strong>Explanation:</strong> In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= matrix[i][j] &lt;= n</code></li>
</ul>
</div>