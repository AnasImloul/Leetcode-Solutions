<h3 align="left"> 1156. Swap For Longest Repeated Character Substring</h3>
<div><p>You are given a string <code>text</code>. You can swap two of the characters in the <code>text</code>.</p>

<p>Return <em>the length of the longest substring with repeated characters</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "ababa"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "aaabaaa"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "aaaaa"
<strong>Output:</strong> 5
<strong>Explanation:</strong> No need to swap, longest repeated character substring is "aaaaa" with length is 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>text</code> consist of lowercase English characters only.</li>
</ul>
</div>