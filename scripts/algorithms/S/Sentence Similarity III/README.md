<h3 align="left"> 1813. Sentence Similarity III</h3>
<div><p>A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, <code>"Hello World"</code>, <code>"HELLO"</code>, <code>"hello world hello world"</code> are all sentences. Words consist of <strong>only</strong> uppercase and lowercase English letters.</p>

<p>Two sentences <code>sentence1</code> and <code>sentence2</code> are <strong>similar</strong> if it is possible to insert an arbitrary sentence <strong>(possibly empty)</strong> inside one of these sentences such that the two sentences become equal. For example, <code>sentence1 = "Hello my name is Jane"</code> and <code>sentence2 = "Hello Jane"</code> can be made equal by inserting <code>"my name is"</code> between <code>"Hello"</code> and <code>"Jane"</code> in <code>sentence2</code>.</p>

<p>Given two sentences <code>sentence1</code> and <code>sentence2</code>, return <code>true</code> <em>if </em><code>sentence1</code> <em>and </em><code>sentence2</code> <em>are similar.</em> Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence1 = "My name is Haley", sentence2 = "My Haley"
<strong>Output:</strong> true
<strong>Explanation:</strong> sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence1 = "of", sentence2 = "A lot of words"
<strong>Output:</strong> false
<strong>Explanation: </strong>No single sentence can be inserted inside one of the sentences to make it equal to the other.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sentence1 = "Eating right now", sentence2 = "Eating"
<strong>Output:</strong> true
<strong>Explanation:</strong> sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 100</code></li>
	<li><code>sentence1</code> and <code>sentence2</code> consist of lowercase and uppercase English letters and spaces.</li>
	<li>The words in <code>sentence1</code> and <code>sentence2</code> are separated by a single space.</li>
</ul>
</div>