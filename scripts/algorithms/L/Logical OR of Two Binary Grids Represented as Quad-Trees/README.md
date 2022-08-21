<h3 align="left"> 558. Logical OR of Two Binary Grids Represented as Quad-Trees</h3>
<div><p>A Binary Matrix is a matrix in which all the elements are either <strong>0</strong> or <strong>1</strong>.</p>

<p>Given <code>quadTree1</code> and <code>quadTree2</code>. <code>quadTree1</code> represents a <code>n * n</code> binary matrix and <code>quadTree2</code> represents another <code>n * n</code> binary matrix.</p>

<p>Return <em>a Quad-Tree</em> representing the <code>n * n</code> binary matrix which is the result of <strong>logical bitwise OR</strong> of the two binary matrixes represented by <code>quadTree1</code> and <code>quadTree2</code>.</p>

<p>Notice that you can assign the value of a node to <strong>True</strong> or <strong>False</strong> when <code>isLeaf</code> is <strong>False</strong>, and both are <strong>accepted</strong> in the answer.</p>

<p>A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:</p>

<ul>
	<li><code>val</code>: True if the node represents a grid of 1's or False if the node represents a grid of 0's.</li>
	<li><code>isLeaf</code>: True if the node is leaf node on the tree or False if the node has the four children.</li>
</ul>

<pre>class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}</pre>

<p>We can construct a Quad-Tree from a two-dimensional area using the following steps:</p>

<ol>
	<li>If the current grid has the same value (i.e all <code>1's</code> or all <code>0's</code>) set <code>isLeaf</code> True and set <code>val</code> to the value of the grid and set the four children to Null and stop.</li>
	<li>If the current grid has different values, set <code>isLeaf</code> to False and set <code>val</code> to any value and divide the current grid into four sub-grids as shown in the photo.</li>
	<li>Recurse for each of the children with the proper sub-grid.</li>
</ol>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/new_top.png" style="width: 777px; height: 181px;">
<p>If you want to know more about the Quad-Tree, you can refer to the <a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>.</p>

<p><strong>Quad-Tree format:</strong></p>

<p>The input/output represents the serialized format of a Quad-Tree using level order traversal, where <code>null</code> signifies a path terminator where no node exists below.</p>

<p>It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list <code>[isLeaf, val]</code>.</p>

<p>If the value of <code>isLeaf</code> or <code>val</code> is True we represent it as <strong>1</strong> in the list <code>[isLeaf, val]</code> and if the value of <code>isLeaf</code> or <code>val</code> is False we represent it as <strong>0</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qt1.png" style="width: 550px; height: 196px;"> <img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qt2.png" style="width: 550px; height: 278px;">
<pre><strong>Input:</strong> quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
, quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>Output:</strong> [[0,0],[1,1],[1,1],[1,1],[1,0]]
<strong>Explanation:</strong> quadTree1 and quadTree2 are shown above. You can see the binary matrix which is represented by each Quad-Tree.
If we apply logical bitwise OR on the two binary matrices we get the binary matrix below which is represented by the result Quad-Tree.
Notice that the binary matrices shown are only for illustration, you don't have to construct the binary matrix to get the result tree.
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qtr.png" style="width: 777px; height: 222px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> quadTree1 = [[1,0]], quadTree2 = [[1,0]]
<strong>Output:</strong> [[1,0]]
<strong>Explanation:</strong> Each tree represents a binary matrix of size 1*1. Each matrix contains only zero.
The resulting matrix is of size 1*1 with also zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>quadTree1</code> and <code>quadTree2</code> are both <strong>valid</strong> Quad-Trees each representing a <code>n * n</code> grid.</li>
	<li><code>n == 2<sup>x</sup></code> where <code>0 &lt;= x &lt;= 9</code>.</li>
</ul>
</div>