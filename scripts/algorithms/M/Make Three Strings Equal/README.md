<h3 align="left"> 2937. Make Three Strings Equal</h3>
<div><p>You are given three strings: <code>s1</code>, <code>s2</code>, and <code>s3</code>. In one operation you can choose one of these strings and delete its <strong>rightmost</strong> character. Note that you <strong>cannot</strong> completely empty a string.</p>

<p>Return the <em>minimum number of operations</em> required to make the strings equal<em>. </em>If it is impossible to make them equal, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s1 = &quot;abc&quot;, s2 = &quot;abb&quot;, s3 = &quot;ab&quot;</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">2</span></p>

<p><strong>Explanation:&nbsp;</strong>Deleting the rightmost character from both <code>s1</code> and <code>s2</code> will result in three equal strings.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s1 = &quot;dac&quot;, s2 = &quot;bac&quot;, s3 = &quot;cac&quot;</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">-1</span></p>

<p><strong>Explanation:</strong> Since the first letters of <code>s1</code> and <code>s2</code> differ, they cannot be made equal.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length, s3.length &lt;= 100</code></li>
	<li><font face="monospace"><code>s1</code>,</font> <code><font face="monospace">s2</font></code><font face="monospace"> and</font> <code><font face="monospace">s3</font></code> consist only of lowercase English letters.</li>
</ul>
</div>
