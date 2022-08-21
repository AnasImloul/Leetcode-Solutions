<h3 align="left"> 730. Count Different Palindromic Subsequences</h3>
<div><p>Given a string s, return <em>the number of different non-empty palindromic subsequences in</em> <code>s</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A subsequence of a string is obtained by deleting zero or more characters from the string.</p>

<p>A sequence is palindromic if it is equal to the sequence reversed.</p>

<p>Two sequences <code>a<sub>1</sub>, a<sub>2</sub>, ...</code> and <code>b<sub>1</sub>, b<sub>2</sub>, ...</code> are different if there is some <code>i</code> for which <code>a<sub>i</sub> != b<sub>i</sub></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bccb"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
<strong>Output:</strong> 104860361
<strong>Explanation:</strong> There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10<sup>9</sup> + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'a'</code>, <code>'b'</code>, <code>'c'</code>, or <code>'d'</code>.</li>
</ul>
</div>