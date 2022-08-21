<h3 align="left"> 2030. Smallest K-Length Subsequence With Occurrences of a Letter</h3>
<div><p>You are given a string <code>s</code>, an integer <code>k</code>, a letter <code>letter</code>, and an integer <code>repetition</code>.</p>

<p>Return <em>the <strong>lexicographically smallest</strong> subsequence of</em> <code>s</code><em> of length</em> <code>k</code> <em>that has the letter</em> <code>letter</code> <em>appear <strong>at least</strong></em> <code>repetition</code> <em>times</em>. The test cases are generated so that the <code>letter</code> appears in <code>s</code> <strong>at least</strong> <code>repetition</code> times.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>A string <code>a</code> is <strong>lexicographically smaller</strong> than a string <code>b</code> if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leet", k = 3, letter = "e", repetition = 1
<strong>Output:</strong> "eet"
<strong>Explanation:</strong> There are four subsequences of length 3 that have the letter 'e' appear at least 1 time:
- "lee" (from "<strong><u>lee</u></strong>t")
- "let" (from "<strong><u>le</u></strong>e<u><strong>t</strong></u>")
- "let" (from "<u><strong>l</strong></u>e<u><strong>et</strong></u>")
- "eet" (from "l<u><strong>eet</strong></u>")
The lexicographically smallest subsequence among them is "eet".
</pre>

<p><strong>Example 2:</strong></p>
<img alt="example-2" src="https://assets.leetcode.com/uploads/2021/09/13/smallest-k-length-subsequence.png" style="width: 339px; height: 67px;">
<pre><strong>Input:</strong> s = "leetcode", k = 4, letter = "e", repetition = 2
<strong>Output:</strong> "ecde"
<strong>Explanation:</strong> "ecde" is the lexicographically smallest subsequence of length 4 that has the letter "e" appear at least 2 times.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "bb", k = 2, letter = "b", repetition = 2
<strong>Output:</strong> "bb"
<strong>Explanation:</strong> "bb" is the only subsequence of length 2 that has the letter "b" appear at least 2 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= repetition &lt;= k &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>letter</code> is a lowercase English letter, and appears in <code>s</code> at least <code>repetition</code> times.</li>
</ul>
</div>