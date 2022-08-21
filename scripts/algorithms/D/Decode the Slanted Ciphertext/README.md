<h3 align="left"> 2075. Decode the Slanted Ciphertext</h3>
<div><p>A string <code>originalText</code> is encoded using a <strong>slanted transposition cipher</strong> to a string <code>encodedText</code> with the help of a matrix having a <strong>fixed number of rows</strong> <code>rows</code>.</p>

<p><code>originalText</code> is placed first in a top-left to bottom-right manner.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/07/exa11.png" style="width: 300px; height: 185px;">
<p>The blue cells are filled first, followed by the red cells, then the yellow cells, and so on, until we reach the end of <code>originalText</code>. The arrow indicates the order in which the cells are filled. All empty cells are filled with <code>' '</code>. The number of columns is chosen such that the rightmost column will <strong>not be empty</strong> after filling in <code>originalText</code>.</p>

<p><code>encodedText</code> is then formed by appending all characters of the matrix in a row-wise fashion.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/07/exa12.png" style="width: 300px; height: 200px;">
<p>The characters in the blue cells are appended first to <code>encodedText</code>, then the red cells, and so on, and finally the yellow cells. The arrow indicates the order in which the cells are accessed.</p>

<p>For example, if <code>originalText = "cipher"</code> and <code>rows = 3</code>, then we encode it in the following manner:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/25/desc2.png" style="width: 281px; height: 211px;">
<p>The blue arrows depict how <code>originalText</code> is placed in the matrix, and the red arrows denote the order in which <code>encodedText</code> is formed. In the above example, <code>encodedText = "ch ie pr"</code>.</p>

<p>Given the encoded string <code>encodedText</code> and number of rows <code>rows</code>, return <em>the original string</em> <code>originalText</code>.</p>

<p><strong>Note:</strong> <code>originalText</code> <strong>does not</strong> have any trailing spaces <code>' '</code>. The test cases are generated such that there is only one possible <code>originalText</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> encodedText = "ch   ie   pr", rows = 3
<strong>Output:</strong> "cipher"
<strong>Explanation:</strong> This is the same example described in the problem description.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/26/exam1.png" style="width: 250px; height: 168px;">
<pre><strong>Input:</strong> encodedText = "iveo    eed   l te   olc", rows = 4
<strong>Output:</strong> "i love leetcode"
<strong>Explanation:</strong> The figure above denotes the matrix that was used to encode originalText. 
The blue arrows show how we can find originalText from encodedText.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/26/eg2.png" style="width: 300px; height: 51px;">
<pre><strong>Input:</strong> encodedText = "coding", rows = 1
<strong>Output:</strong> "coding"
<strong>Explanation:</strong> Since there is only 1 row, both originalText and encodedText are the same.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= encodedText.length &lt;= 10<sup>6</sup></code></li>
	<li><code>encodedText</code> consists of lowercase English letters and <code>' '</code> only.</li>
	<li><code>encodedText</code> is a valid encoding of some <code>originalText</code> that <strong>does not</strong> have trailing spaces.</li>
	<li><code>1 &lt;= rows &lt;= 1000</code></li>
	<li>The testcases are generated such that there is <strong>only one</strong> possible <code>originalText</code>.</li>
</ul>
</div>