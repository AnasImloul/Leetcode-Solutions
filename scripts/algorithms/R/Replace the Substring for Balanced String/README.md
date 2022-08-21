<h3 align="left"> 1234. Replace the Substring for Balanced String</h3>
<div><p>You are given a string s of length <code>n</code> containing only four kinds of characters: <code>'Q'</code>, <code>'W'</code>, <code>'E'</code>, and <code>'R'</code>.</p>

<p>A string is said to be <strong>balanced</strong><em> </em>if each of its characters appears <code>n / 4</code> times where <code>n</code> is the length of the string.</p>

<p>Return <em>the minimum length of the substring that can be replaced with <strong>any</strong> other string of the same length to make </em><code>s</code><em> <strong>balanced</strong></em>. If s is already <strong>balanced</strong>, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "QWER"
<strong>Output:</strong> 0
<strong>Explanation:</strong> s is already balanced.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "QQWE"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "QQQW"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can replace the first "QQ" to "ER". 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>4 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> is a multiple of <code>4</code>.</li>
	<li><code>s</code> contains only <code>'Q'</code>, <code>'W'</code>, <code>'E'</code>, and <code>'R'</code>.</li>
</ul>
</div>