<h3 align="left"> 1320. Minimum Distance to Type a Word Using Two Fingers</h3>
<div><img alt="" src="https://assets.leetcode.com/uploads/2020/01/02/leetcode_keyboard.png" style="width: 349px; height: 209px;">
<p>You have a keyboard layout as shown above in the <strong>X-Y</strong> plane, where each English uppercase letter is located at some coordinate.</p>

<ul>
	<li>For example, the letter <code>'A'</code> is located at coordinate <code>(0, 0)</code>, the letter <code>'B'</code> is located at coordinate <code>(0, 1)</code>, the letter <code>'P'</code> is located at coordinate <code>(2, 3)</code> and the letter <code>'Z'</code> is located at coordinate <code>(4, 1)</code>.</li>
</ul>

<p>Given the string <code>word</code>, return <em>the minimum total <strong>distance</strong> to type such string using only two fingers</em>.</p>

<p>The <strong>distance</strong> between coordinates <code>(x<sub>1</sub>, y<sub>1</sub>)</code> and <code>(x<sub>2</sub>, y<sub>2</sub>)</code> is <code>|x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|</code>.</p>

<p><strong>Note</strong> that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "CAKE"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -&gt; cost = 0 
Finger 1 on letter 'A' -&gt; cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -&gt; cost = 0 
Finger 2 on letter 'E' -&gt; cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "HAPPY"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -&gt; cost = 0
Finger 1 on letter 'A' -&gt; cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -&gt; cost = 0
Finger 2 on letter 'P' -&gt; cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -&gt; cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= word.length &lt;= 300</code></li>
	<li><code>word</code> consists of uppercase English letters.</li>
</ul>
</div>