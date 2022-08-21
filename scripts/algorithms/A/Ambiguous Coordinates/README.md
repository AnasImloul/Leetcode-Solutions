<h3 align="left"> 816. Ambiguous Coordinates</h3>
<div><p>We had some 2-dimensional coordinates, like <code>"(1, 3)"</code> or <code>"(2, 0.5)"</code>. Then, we removed all commas, decimal points, and spaces and ended up with the string s.</p>

<ul>
	<li>For example, <code>"(1, 3)"</code> becomes <code>s = "(13)"</code> and <code>"(2, 0.5)"</code> becomes <code>s = "(205)"</code>.</li>
</ul>

<p>Return <em>a list of strings representing all possibilities for what our original coordinates could have been</em>.</p>

<p>Our original representation never had extraneous zeroes, so we never started with numbers like <code>"00"</code>, <code>"0.0"</code>, <code>"0.00"</code>, <code>"1.0"</code>, <code>"001"</code>, <code>"00.01"</code>, or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like <code>".1"</code>.</p>

<p>The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(123)"
<strong>Output:</strong> ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(0123)"
<strong>Output:</strong> ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
<strong>Explanation:</strong> 0.0, 00, 0001 or 00.01 are not allowed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(00011)"
<strong>Output:</strong> ["(0, 0.011)","(0.001, 1)"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>4 &lt;= s.length &lt;= 12</code></li>
	<li><code>s[0] == '('</code> and <code>s[s.length - 1] == ')'</code>.</li>
	<li>The rest of <code>s</code> are digits.</li>
</ul>
</div>