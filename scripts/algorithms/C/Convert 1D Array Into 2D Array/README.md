<h3 align="left"> 2022. Convert 1D Array Into 2D Array</h3>
<div><p>You are given a <strong>0-indexed</strong> 1-dimensional (1D) integer array <code>original</code>, and two integers, <code>m</code> and <code>n</code>. You are tasked with creating a 2-dimensional (2D) array with <code> m</code> rows and <code>n</code> columns using <strong>all</strong> the elements from <code>original</code>.</p>

<p>The elements from indices <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>) of <code>original</code> should form the first row of the constructed 2D array, the elements from indices <code>n</code> to <code>2 * n - 1</code> (<strong>inclusive</strong>) should form the second row of the constructed 2D array, and so on.</p>

<p>Return <em>an </em><code>m x n</code><em> 2D array constructed according to the above procedure, or an empty 2D array if it is impossible</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/08/26/image-20210826114243-1.png" style="width: 500px; height: 174px;">
<pre><strong>Input:</strong> original = [1,2,3,4], m = 2, n = 2
<strong>Output:</strong> [[1,2],[3,4]]
<strong>Explanation:</strong> The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> original = [1,2,3], m = 1, n = 3
<strong>Output:</strong> [[1,2,3]]
<strong>Explanation:</strong> The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> original = [1,2], m = 1, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= original.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= original[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li>
</ul>
</div>