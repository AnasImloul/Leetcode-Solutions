<h3 align="left"> 655. Print Binary Tree</h3>
<div><p>Given the <code>root</code> of a binary tree, construct a <strong>0-indexed</strong> <code>m x n</code> string matrix <code>res</code> that represents a <strong>formatted layout</strong> of the tree. The formatted layout matrix should be constructed using the following rules:</p>

<ul>
	<li>The <strong>height</strong> of the tree is <code>height</code>&nbsp;and the number of rows <code>m</code> should be equal to <code>height + 1</code>.</li>
	<li>The number of columns <code>n</code> should be equal to <code>2<sup>height+1</sup> - 1</code>.</li>
	<li>Place the <strong>root node</strong> in the <strong>middle</strong> of the <strong>top row</strong> (more formally, at location <code>res[0][(n-1)/2]</code>).</li>
	<li>For each node that has been placed in the matrix at position <code>res[r][c]</code>, place its <strong>left child</strong> at <code>res[r+1][c-2<sup>height-r-1</sup>]</code> and its <strong>right child</strong> at <code>res[r+1][c+2<sup>height-r-1</sup>]</code>.</li>
	<li>Continue this process until all the nodes in the tree have been placed.</li>
	<li>Any empty cells should contain the empty string <code>""</code>.</li>
</ul>

<p>Return <em>the constructed matrix </em><code>res</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/print1-tree.jpg" style="width: 141px; height: 181px;">
<pre><strong>Input:</strong> root = [1,2]
<strong>Output:</strong> 
[["","1",""],
&nbsp;["2","",""]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/print2-tree.jpg" style="width: 207px; height: 302px;">
<pre><strong>Input:</strong> root = [1,2,3,null,4]
<strong>Output:</strong> 
[["","","","1","","",""],
&nbsp;["","2","","","","3",""],
&nbsp;["","","4","","","",""]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 2<sup>10</sup>]</code>.</li>
	<li><code>-99 &lt;= Node.val &lt;= 99</code></li>
	<li>The depth of the tree will be in the range <code>[1, 10]</code>.</li>
</ul>
</div>