<h3 align="left"> 497. Random Point in Non-overlapping Rectangles</h3>
<div><p>You are given an array of non-overlapping axis-aligned rectangles <code>rects</code> where <code>rects[i] = [a<sub>i</sub>, b<sub>i</sub>, x<sub>i</sub>, y<sub>i</sub>]</code> indicates that <code>(a<sub>i</sub>, b<sub>i</sub>)</code> is the bottom-left corner point of the <code>i<sup>th</sup></code> rectangle and <code>(x<sub>i</sub>, y<sub>i</sub>)</code> is the top-right corner point of the <code>i<sup>th</sup></code> rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.</p>

<p>Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.</p>

<p><strong>Note</strong> that an integer point is a point that has integer coordinates.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(int[][] rects)</code> Initializes the object with the given rectangles <code>rects</code>.</li>
	<li><code>int[] pick()</code> Returns a random integer point <code>[u, v]</code> inside the space covered by one of the given rectangles.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/24/lc-pickrandomrec.jpg" style="width: 419px; height: 539px;">
<pre><strong>Input</strong>
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
<strong>Output</strong>
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

<strong>Explanation</strong>
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rects.length &lt;= 100</code></li>
	<li><code>rects[i].length == 4</code></li>
	<li><code>-10<sup>9</sup> &lt;= a<sub>i</sub> &lt; x<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= b<sub>i</sub> &lt; y<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>x<sub>i</sub> - a<sub>i</sub> &lt;= 2000</code></li>
	<li><code>y<sub>i</sub> - b<sub>i</sub> &lt;= 2000</code></li>
	<li>All the rectangles do not overlap.</li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>pick</code>.</li>
</ul>
</div>