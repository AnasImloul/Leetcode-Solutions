<h3 align="left"> 1190. Reverse Substrings Between Each Pair of Parentheses</h3>
<div><p>You are given a string <code>s</code> that consists of lower case English letters and brackets.</p>

<p>Reverse the strings in each pair of matching parentheses, starting from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any brackets.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
<strong>Explanation:</strong> The substring "love" is reversed first, then the whole string is reversed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong> First, we reverse the substring "oc", then "etco", and finally, the whole string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It is guaranteed that all parentheses are balanced.</li>
</ul>
</div>