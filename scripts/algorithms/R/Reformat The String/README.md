<h3 align="left"> 1417. Reformat The String</h3>
<div><p>You are given an alphanumeric string <code>s</code>. (<strong>Alphanumeric string</strong> is a string consisting of lowercase English letters and digits).</p>

<p>You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.</p>

<p>Return <em>the reformatted string</em> or return <strong>an empty string</strong> if it is impossible to reformat the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "a0b1c2"
<strong>Output:</strong> "0a1b2c"
<strong>Explanation:</strong> No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> ""
<strong>Explanation:</strong> "leetcode" has only characters so we cannot separate them by digits.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1229857369"
<strong>Output:</strong> ""
<strong>Explanation:</strong> "1229857369" has only digits so we cannot separate them by characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of only lowercase English letters and/or digits.</li>
</ul>
</div>