<h3 align="left"> 2255. Count Prefixes of a Given String</h3>
<div><p>You are given a string array <code>words</code> and a string <code>s</code>, where <code>words[i]</code> and <code>s</code> comprise only of <strong>lowercase English letters</strong>.</p>

<p>Return <em>the <strong>number of strings</strong> in</em> <code>words</code> <em>that are a <strong>prefix</strong> of</em> <code>s</code>.</p>

<p>A <strong>prefix</strong> of a string is a substring that occurs at the beginning of the string. A <b>substring</b> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["a","b","c","ab","bc","abc"], s = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The strings in words which are a prefix of s = "abc" are:
"a", "ab", and "abc".
Thus the number of strings in words which are a prefix of s is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a","a"], s = "aa"
<strong>Output:</strong> 2
<strong>Explanation:
</strong>Both of the strings are a prefix of s. 
Note that the same string can occur multiple times in words, and it should be counted each time.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, s.length &lt;= 10</code></li>
	<li><code>words[i]</code> and <code>s</code> consist of lowercase English letters <strong>only</strong>.</li>
</ul>
</div>