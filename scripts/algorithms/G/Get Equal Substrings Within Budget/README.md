<h3 align="left"> 1208. Get Equal Substrings Within Budget</h3>
<div><p>You are given two strings <code>s</code> and <code>t</code> of the same length and an integer <code>maxCost</code>.</p>

<p>You want to change <code>s</code> to <code>t</code>. Changing the <code>i<sup>th</sup></code> character of <code>s</code> to <code>i<sup>th</sup></code> character of <code>t</code> costs <code>|s[i] - t[i]|</code> (i.e., the absolute difference between the ASCII values of the characters).</p>

<p>Return <em>the maximum length of a substring of </em><code>s</code><em> that can be changed to be the same as the corresponding substring of </em><code>t</code><em> with a cost less than or equal to </em><code>maxCost</code>. If there is no substring from <code>s</code> that can be changed to its corresponding substring from <code>t</code>, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "bcdf", maxCost = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "cdef", maxCost = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> Each character in s costs 2 to change to character in t,  so the maximum length is 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "acde", maxCost = 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> You cannot make any change, so the maximum length is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>0 &lt;= maxCost &lt;= 10<sup>6</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of only lowercase English letters.</li>
</ul>
</div>