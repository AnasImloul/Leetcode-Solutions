<h3 align="left"> 1278. Palindrome Partitioning III</h3>
<div><p>You are given a string <code>s</code> containing lowercase letters and an integer <code>k</code>. You need to :</p>

<ul>
	<li>First, change some characters of <code>s</code> to other lowercase English letters.</li>
	<li>Then divide <code>s</code> into <code>k</code> non-empty disjoint substrings such that each substring is a palindrome.</li>
</ul>

<p>Return <em>the minimal number of characters that you need to change to divide the string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abc", k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabbc", k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;You can split the string into "aa", "bb" and "c", all of them are palindrome.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", k = 8
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 100</code>.</li>
	<li><code>s</code> only contains lowercase English letters.</li>
</ul>
</div>