<h3 align="left"> 2781. Length of the Longest Valid Substring</h3>
<div><p>You are given a string <code>word</code> and an array of strings <code>forbidden</code>.</p>

<p>A string is called <strong>valid</strong> if none of its substrings are present in <code>forbidden</code>.</p>

<p>Return <em>the length of the <strong>longest valid substring</strong> of the string </em><code>word</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string, possibly empty.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;cbaaaabc&quot;, forbidden = [&quot;aaa&quot;,&quot;cb&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 11 valid substrings in word: &quot;c&quot;, &quot;b&quot;, &quot;a&quot;, &quot;ba&quot;, &quot;aa&quot;, &quot;bc&quot;, &quot;baa&quot;, &quot;aab&quot;, &quot;ab&quot;, &quot;abc&quot; and &quot;aabc&quot;. The length of the longest valid substring is 4. 
It can be shown that all other substrings contain either &quot;aaa&quot; or &quot;cb&quot; as a substring. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;leetcode&quot;, forbidden = [&quot;de&quot;,&quot;le&quot;,&quot;e&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 11 valid substrings in word: &quot;l&quot;, &quot;t&quot;, &quot;c&quot;, &quot;o&quot;, &quot;d&quot;, &quot;tc&quot;, &quot;co&quot;, &quot;od&quot;, &quot;tco&quot;, &quot;cod&quot;, and &quot;tcod&quot;. The length of the longest valid substring is 4.
It can be shown that all other substrings contain either &quot;de&quot;, &quot;le&quot;, or &quot;e&quot; as a substring. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= forbidden.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= forbidden[i].length &lt;= 10</code></li>
	<li><code>forbidden[i]</code> consists only of lowercase English letters.</li>
</ul>
</div>
