<h3 align="left"> 2911. Minimum Changes to Make K Semi-palindromes</h3>
<div><p>Given a string <code>s</code> and an integer <code>k</code>, partition <code>s</code> into <code>k</code> <strong><span data-keyword="substring-nonempty">substrings</span></strong> such that the letter changes needed to make each substring a <strong>semi-palindrome</strong>&nbsp;are minimized.</p>

<p>Return the <em><strong>minimum</strong> number of letter changes</em> required<em>.</em></p>

<p>A <strong>semi-palindrome</strong> is a special type of string that can be divided into <strong><span data-keyword="palindrome">palindromes</span></strong> based on a repeating pattern. To check if a string is a semi-palindrome:​</p>

<ol>
	<li>Choose a positive divisor <code>d</code> of the string&#39;s length. <code>d</code> can range from <code>1</code> up to, but not including, the string&#39;s length. For a string of length <code>1</code>, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.</li>
	<li>For a given divisor <code>d</code>, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length <code>d</code>. Specifically, the first group consists of characters at positions <code>1</code>, <code>1 + d</code>, <code>1 + 2d</code>, and so on; the second group includes characters at positions <code>2</code>, <code>2 + d</code>, <code>2 + 2d</code>, etc.</li>
	<li>The string is considered a semi-palindrome if each of these groups forms a palindrome.</li>
</ol>

<p>Consider the string <code>&quot;abcabc&quot;</code>:</p>

<ul>
	<li>The length of <code>&quot;abcabc&quot;</code> is <code>6</code>. Valid divisors are <code>1</code>, <code>2</code>, and <code>3</code>.</li>
	<li>For <code>d = 1</code>: The entire string <code>&quot;abcabc&quot;</code> forms one group. Not a palindrome.</li>
	<li>For <code>d = 2</code>:
	<ul>
		<li>Group 1 (positions <code>1, 3, 5</code>): <code>&quot;acb&quot;</code></li>
		<li>Group 2 (positions <code>2, 4, 6</code>): <code>&quot;bac&quot;</code></li>
		<li>Neither group forms a palindrome.</li>
	</ul>
	</li>
	<li>For <code>d = 3</code>:
	<ul>
		<li>Group 1 (positions <code>1, 4</code>): <code>&quot;aa&quot;</code></li>
		<li>Group 2 (positions <code>2, 5</code>): <code>&quot;bb&quot;</code></li>
		<li>Group 3 (positions <code>3, 6</code>): <code>&quot;cc&quot;</code></li>
		<li>All groups form palindromes. Therefore, <code>&quot;abcabc&quot;</code> is a semi-palindrome.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> s = &quot;abcac&quot;, k = 2 </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 1 </span></p>

<p><strong>Explanation: </strong> Divide <code>s</code> into <code>&quot;ab&quot;</code> and <code>&quot;cac&quot;</code>. <code>&quot;cac&quot;</code> is already semi-palindrome. Change <code>&quot;ab&quot;</code> to <code>&quot;aa&quot;</code>, it becomes semi-palindrome with <code>d = 1</code>.</p>
</div>

<p><strong class="example">Example 2: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> s = &quot;abcdef&quot;, k = 2 </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 2 </span></p>

<p><strong>Explanation: </strong> Divide <code>s</code> into substrings <code>&quot;abc&quot;</code> and <code>&quot;def&quot;</code>. Each&nbsp;needs one change to become semi-palindrome.</p>
</div>

<p><strong class="example">Example 3: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> s = &quot;aabbaa&quot;, k = 3 </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 0 </span></p>

<p><strong>Explanation: </strong> Divide <code>s</code> into substrings <code>&quot;aa&quot;</code>, <code>&quot;bb&quot;</code> and <code>&quot;aa&quot;</code>.&nbsp;All are already semi-palindromes.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= s.length / 2</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>
</div>
