<h3 align="left"> 966. Vowel Spellchecker</h3>
<div><p>Given a <code>wordlist</code>, we want to implement a spellchecker that converts a query word into a correct word.</p>

<p>For a given <code>query</code> word, the spell checker handles two categories of spelling mistakes:</p>

<ul>
	<li>Capitalization: If the query matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the case in the wordlist.

	<ul>
		<li>Example: <code>wordlist = ["yellow"]</code>, <code>query = "YellOw"</code>: <code>correct = "yellow"</code></li>
		<li>Example: <code>wordlist = ["Yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "Yellow"</code></li>
		<li>Example: <code>wordlist = ["yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "yellow"</code></li>
	</ul>
	</li>
	<li>Vowel Errors: If after replacing the vowels <code>('a', 'e', 'i', 'o', 'u')</code> of the query word with any vowel individually, it matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the match in the wordlist.
	<ul>
		<li>Example: <code>wordlist = ["YellOw"]</code>, <code>query = "yollow"</code>: <code>correct = "YellOw"</code></li>
		<li>Example: <code>wordlist = ["YellOw"]</code>, <code>query = "yeellow"</code>: <code>correct = ""</code> (no match)</li>
		<li>Example: <code>wordlist = ["YellOw"]</code>, <code>query = "yllw"</code>: <code>correct = ""</code> (no match)</li>
	</ul>
	</li>
</ul>

<p>In addition, the spell checker operates under the following precedence rules:</p>

<ul>
	<li>When the query exactly matches a word in the wordlist (<strong>case-sensitive</strong>), you should return the same word back.</li>
	<li>When the query matches a word up to capitlization, you should return the first such match in the wordlist.</li>
	<li>When the query matches a word up to vowel errors, you should return the first such match in the wordlist.</li>
	<li>If the query has no matches in the wordlist, you should return the empty string.</li>
</ul>

<p>Given some <code>queries</code>, return a list of words <code>answer</code>, where <code>answer[i]</code> is the correct word for <code>query = queries[i]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
<strong>Output:</strong> ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> wordlist = ["yellow"], queries = ["YellOw"]
<strong>Output:</strong> ["yellow"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length, queries.length &lt;= 5000</code></li>
	<li><code>1 &lt;= wordlist[i].length, queries[i].length &lt;= 7</code></li>
	<li><code>wordlist[i]</code> and <code>queries[i]</code> consist only of only English letters.</li>
</ul>
</div>