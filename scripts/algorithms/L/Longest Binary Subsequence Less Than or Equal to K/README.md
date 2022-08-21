<h3 align="left"> 2311. Longest Binary Subsequence Less Than or Equal to K</h3>
<div><p>You are given a binary string <code>s</code> and a positive integer <code>k</code>.</p>

<p>Return <em>the length of the <strong>longest</strong> subsequence of </em><code>s</code><em> that makes up a <strong>binary</strong> number less than or equal to</em> <code>k</code>.</p>

<p>Note:</p>

<ul>
	<li>The subsequence can contain <strong>leading zeroes</strong>.</li>
	<li>The empty string is considered to be equal to <code>0</code>.</li>
	<li>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1001010", k = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00101001", k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
</div>