<h3 align="left"> 777. Swap Adjacent in LR String</h3>
<div><p>In a string composed of <code>'L'</code>, <code>'R'</code>, and <code>'X'</code> characters, like <code>"RXXLRXRXL"</code>, a move consists of either replacing one occurrence of <code>"XL"</code> with <code>"LX"</code>, or replacing one occurrence of <code>"RX"</code> with <code>"XR"</code>. Given the starting string <code>start</code> and the ending string <code>end</code>, return <code>True</code> if and only if there exists a sequence of moves to transform one string to the other.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> start = "RXXLRXRXL", end = "XRLXXRRLX"
<strong>Output:</strong> true
<strong>Explanation:</strong> We can transform start to end following these steps:
RXXLRXRXL -&gt;
XRXLRXRXL -&gt;
XRLXRXRXL -&gt;
XRLXXRRXL -&gt;
XRLXXRRLX
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> start = "X", end = "L"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= start.length&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li><code>start.length == end.length</code></li>
	<li>Both <code>start</code> and <code>end</code> will only consist of characters in <code>'L'</code>, <code>'R'</code>, and&nbsp;<code>'X'</code>.</li>
</ul>
</div>