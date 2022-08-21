<h3 align="left"> 858. Mirror Reflection</h3>
<div><p>There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered <code>0</code>, <code>1</code>, and <code>2</code>.</p>

<p>The square room has walls of length <code>p</code>&nbsp;and a laser ray from the southwest corner first meets the east wall at a distance <code>q</code> from the <code>0<sup>th</sup></code> receptor.</p>

<p>Given the two integers <code>p</code> and <code>q</code>, return <em>the number of the receptor that the ray meets first</em>.</p>

<p>The test cases are guaranteed so that the ray will meet a receptor eventually.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png" style="width: 218px; height: 217px;">
<pre><strong>Input:</strong> p = 2, q = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The ray meets receptor 2 the first time it gets reflected back to the left wall.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> p = 3, q = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= q &lt;= p &lt;= 1000</code></li>
</ul>
</div>