<h3 align="left"> 2014. Longest Subsequence Repeated k Times</h3>
<div><p>You are given a string <code>s</code> of length <code>n</code>, and an integer <code>k</code>. You are tasked to find the <strong>longest subsequence repeated</strong> <code>k</code> times in string <code>s</code>.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>A subsequence <code>seq</code> is <strong>repeated</strong> <code>k</code> times in the string <code>s</code> if <code>seq * k</code> is a subsequence of <code>s</code>, where <code>seq * k</code> represents a string constructed by concatenating <code>seq</code> <code>k</code> times.</p>

<ul>
	<li>For example, <code>"bba"</code> is repeated <code>2</code> times in the string <code>"bababcba"</code>, because the string <code>"bbabba"</code>, constructed by concatenating <code>"bba"</code> <code>2</code> times, is a subsequence of the string <code>"<strong><u>b</u></strong>a<strong><u>bab</u></strong>c<strong><u>ba</u></strong>"</code>.</li>
</ul>

<p>Return <em>the <strong>longest subsequence repeated</strong> </em><code>k</code><em> times in string </em><code>s</code><em>. If multiple such subsequences are found, return the <strong>lexicographically largest</strong> one. If there is no such subsequence, return an <strong>empty</strong> string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example 1" src="https://assets.leetcode.com/uploads/2021/08/30/longest-subsequence-repeat-k-times.png" style="width: 457px; height: 99px;">
<pre><strong>Input:</strong> s = "letsleetcode", k = 2
<strong>Output:</strong> "let"
<strong>Explanation:</strong> There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "bb", k = 2
<strong>Output:</strong> "b"
<strong>Explanation:</strong> The longest subsequence repeated 2 times is "b".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "ab", k = 2
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no subsequence repeated 2 times. Empty string is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n, k &lt;= 2000</code></li>
	<li><code>2 &lt;= n &lt; k * 8</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>