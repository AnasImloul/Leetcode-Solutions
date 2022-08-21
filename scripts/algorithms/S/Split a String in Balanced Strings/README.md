<h3 align="left"> 1221. Split a String in Balanced Strings</h3>
<div><p><strong>Balanced</strong> strings are those that have an equal quantity of <code>'L'</code> and <code>'R'</code> characters.</p>

<p>Given a <strong>balanced</strong> string <code>s</code>, split it into some number of substrings such that:</p>

<ul>
	<li>Each substring is balanced.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of balanced strings you can obtain.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "RLRRLLRLRL"
<strong>Output:</strong> 4
<strong>Explanation:</strong> s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "RLRRRLLRLL"
<strong>Output:</strong> 2
<strong>Explanation:</strong> s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2<sup>nd</sup> and 5<sup>th</sup> substrings are not balanced.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "LLLLRRRR"
<strong>Output:</strong> 1
<strong>Explanation:</strong> s can be split into "LLLLRRRR".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'L'</code> or <code>'R'</code>.</li>
	<li><code>s</code> is a <strong>balanced</strong> string.</li>
</ul>
</div>