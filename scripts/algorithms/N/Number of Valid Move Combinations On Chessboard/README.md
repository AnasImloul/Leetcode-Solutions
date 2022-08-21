<h3 align="left"> 2056. Number of Valid Move Combinations On Chessboard</h3>
<div><p>There is an <code>8 x 8</code> chessboard containing <code>n</code> pieces (rooks, queens, or bishops). You are given a string array <code>pieces</code> of length <code>n</code>, where <code>pieces[i]</code> describes the type (rook, queen, or bishop) of the <code>i<sup>th</sup></code> piece. In addition, you are given a 2D integer array <code>positions</code> also of length <code>n</code>, where <code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> indicates that the <code>i<sup>th</sup></code> piece is currently at the <strong>1-based</strong> coordinate <code>(r<sub>i</sub>, c<sub>i</sub>)</code> on the chessboard.</p>

<p>When making a <strong>move</strong> for a piece, you choose a <strong>destination</strong> square that the piece will travel toward and stop on.</p>

<ul>
	<li>A rook can only travel <strong>horizontally or vertically</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c)</code>, <code>(r-1, c)</code>, <code>(r, c+1)</code>, or <code>(r, c-1)</code>.</li>
	<li>A queen can only travel <strong>horizontally, vertically, or diagonally</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c)</code>, <code>(r-1, c)</code>, <code>(r, c+1)</code>, <code>(r, c-1)</code>, <code>(r+1, c+1)</code>, <code>(r+1, c-1)</code>, <code>(r-1, c+1)</code>, <code>(r-1, c-1)</code>.</li>
	<li>A bishop can only travel <strong>diagonally</strong> from <code>(r, c)</code> to the direction of <code>(r+1, c+1)</code>, <code>(r+1, c-1)</code>, <code>(r-1, c+1)</code>, <code>(r-1, c-1)</code>.</li>
</ul>

<p>You must make a <strong>move</strong> for every piece on the board simultaneously. A <strong>move combination</strong> consists of all the <strong>moves</strong> performed on all the given pieces. Every second, each piece will instantaneously travel <strong>one square</strong> towards their destination if they are not already at it. All pieces start traveling at the <code>0<sup>th</sup></code> second. A move combination is <strong>invalid</strong> if, at a given time, <strong>two or more</strong> pieces occupy the same square.</p>

<p>Return <em>the number of <strong>valid</strong> move combinations</em>​​​​​.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li><strong>No two pieces</strong> will start in the<strong> same</strong> square.</li>
	<li>You may choose the square a piece is already on as its <strong>destination</strong>.</li>
	<li>If two pieces are <strong>directly adjacent</strong> to each other, it is valid for them to <strong>move past each other</strong> and swap positions in one second.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a1.png" style="width: 215px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["rook"], positions = [[1,1]]
<strong>Output:</strong> 15
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a2.png" style="width: 215px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["queen"], positions = [[1,1]]
<strong>Output:</strong> 22
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/23/a3.png" style="width: 214px; height: 215px;">
<pre><strong>Input:</strong> pieces = ["bishop"], positions = [[4,3]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The image above shows the possible squares the piece can move to.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == pieces.length </code></li>
	<li><code>n == positions.length</code></li>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>pieces</code> only contains the strings <code>"rook"</code>, <code>"queen"</code>, and <code>"bishop"</code>.</li>
	<li>There will be at most one queen on the chessboard.</li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 8</code></li>
	<li>Each <code>positions[i]</code> is distinct.</li>
</ul>
</div>