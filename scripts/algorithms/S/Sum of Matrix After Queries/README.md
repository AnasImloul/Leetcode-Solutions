<h3 align="left"> 2718. Sum of Matrix After Queries</h3>
<div><p>You are given an integer <code>n</code> and a <strong>0-indexed</strong>&nbsp;<strong>2D array</strong> <code>queries</code> where <code>queries[i] = [type<sub>i</sub>, index<sub>i</sub>, val<sub>i</sub>]</code>.</p>

<p>Initially, there is a <strong>0-indexed</strong> <code>n x n</code> matrix filled with <code>0</code>&#39;s. For each query, you must apply one of the following changes:</p>

<ul>
	<li>if <code>type<sub>i</sub> == 0</code>, set the values in the row with <code>index<sub>i</sub></code> to <code>val<sub>i</sub></code>, overwriting any previous values.</li>
	<li>if <code>type<sub>i</sub> == 1</code>, set the values in the column with <code>index<sub>i</sub></code> to <code>val<sub>i</sub></code>, overwriting any previous values.</li>
</ul>

<p>Return <em>the sum of integers in the matrix after all queries are applied</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/11/exm1.png" style="width: 681px; height: 161px;" />
<pre>
<strong>Input:</strong> n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/11/exm2.png" style="width: 681px; height: 331px;" />
<pre>
<strong>Input:</strong> n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 &lt;= type<sub>i</sub> &lt;= 1</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>
