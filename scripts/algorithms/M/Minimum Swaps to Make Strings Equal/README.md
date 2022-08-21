<h3 align="left"> 1247. Minimum Swaps to Make Strings Equal</h3>
<div><p>You are given two strings <code>s1</code> and <code>s2</code> of equal length consisting of letters <code>"x"</code> and <code>"y"</code> <strong>only</strong>. Your task is to make these two strings equal to each other. You can swap any two characters that belong to <strong>different</strong> strings, which means: swap <code>s1[i]</code> and <code>s2[j]</code>.</p>

<p>Return the minimum number of swaps required to make <code>s1</code> and <code>s2</code> equal, or return <code>-1</code> if it is impossible to do so.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "xx", s2 = "yy"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "xy", s2 = "yx"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "xx", s2 = "xy"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1, s2</code> only contain <code>'x'</code> or <code>'y'</code>.</li>
</ul>
</div>