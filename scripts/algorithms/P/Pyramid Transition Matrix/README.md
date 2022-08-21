<h3 align="left"> 756. Pyramid Transition Matrix</h3>
<div><p>You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains <strong>one less block</strong> than the row beneath it and is centered on top.</p>

<p>To make the pyramid aesthetically pleasing, there are only specific <strong>triangular patterns</strong> that are allowed. A triangular pattern consists of a <strong>single block</strong> stacked on top of <strong>two blocks</strong>. The patterns are given&nbsp;as a list of&nbsp;three-letter strings <code>allowed</code>, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.</p>

<ul>
	<li>For example, <code>"ABC"</code> represents a triangular pattern with a <code>'C'</code> block stacked on top of an <code>'A'</code> (left) and <code>'B'</code> (right) block. Note that this is different from <code>"BAC"</code> where <code>'B'</code> is on the left bottom and <code>'A'</code> is on the right bottom.</li>
</ul>

<p>You start with a bottom row of blocks <code>bottom</code>, given as a single string, that you <strong>must</strong> use as the base of the pyramid.</p>

<p>Given <code>bottom</code> and <code>allowed</code>, return <code>true</code><em> if you can build the pyramid all the way to the top such that <strong>every triangular pattern</strong> in the pyramid is in </em><code>allowed</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/26/pyramid1-grid.jpg" style="width: 600px; height: 232px;">
<pre><strong>Input:</strong> bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
<strong>Output:</strong> true
<strong>Explanation:</strong> The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/26/pyramid2-grid.jpg" style="width: 600px; height: 359px;">
<pre><strong>Input:</strong> bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
<strong>Output:</strong> false
<strong>Explanation:</strong> The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= bottom.length &lt;= 6</code></li>
	<li><code>0 &lt;= allowed.length &lt;= 216</code></li>
	<li><code>allowed[i].length == 3</code></li>
	<li>The letters in all input strings are from the set <code>{'A', 'B', 'C', 'D', 'E', 'F'}</code>.</li>
	<li>All the values of <code>allowed</code> are <strong>unique</strong>.</li>
</ul>
</div>