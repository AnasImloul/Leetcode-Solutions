<h3 align="left"> 1625. Lexicographically Smallest String After Applying Operations</h3>
<div><p>You are given a string <code>s</code> of <strong>even length</strong> consisting of digits from <code>0</code> to <code>9</code>, and two integers <code>a</code> and <code>b</code>.</p>

<p>You can apply either of the following two operations any number of times and in any order on <code>s</code>:</p>

<ul>
	<li>Add <code>a</code> to all odd indices of <code>s</code> <strong>(0-indexed)</strong>. Digits post <code>9</code> are cycled back to <code>0</code>. For example, if <code>s = "3456"</code> and <code>a = 5</code>, <code>s</code> becomes <code>"3951"</code>.</li>
	<li>Rotate <code>s</code> to the right by <code>b</code> positions. For example, if <code>s = "3456"</code> and <code>b = 1</code>, <code>s</code> becomes <code>"6345"</code>.</li>
</ul>

<p>Return <em>the <strong>lexicographically smallest</strong> string you can obtain by applying the above operations any number of times on</em> <code>s</code>.</p>

<p>A string <code>a</code> is lexicographically smaller than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>. For example, <code>"0158"</code> is lexicographically smaller than <code>"0190"</code> because the first position they differ is at the third letter, and <code>'5'</code> comes before <code>'9'</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "5525", a = 9, b = 2
<strong>Output:</strong> "2050"
<strong>Explanation:</strong> We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
​​​​​​​Add:    "2050"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "2050".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "74", a = 5, b = 1
<strong>Output:</strong> "24"
<strong>Explanation:</strong> We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "24".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0011", a = 4, b = 2
<strong>Output:</strong> "0011"
<strong>Explanation:</strong> There are no sequence of operations that will give us a lexicographically smaller string than "0011".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s.length</code> is even.</li>
	<li><code>s</code> consists of digits from <code>0</code> to <code>9</code> only.</li>
	<li><code>1 &lt;= a &lt;= 9</code></li>
	<li><code>1 &lt;= b &lt;= s.length - 1</code></li>
</ul>
</div>