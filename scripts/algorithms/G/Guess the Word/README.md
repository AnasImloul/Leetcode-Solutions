<h3 align="left"> 843. Guess the Word</h3>
<div><p>You are given an array of unique strings <code>words</code> where <code>words[i]</code> is six letters long. One word of <code>words</code> was chosen as a secret word.</p>

<p>You are also given the helper object <code>Master</code>. You may call <code>Master.guess(word)</code> where <code>word</code> is a six-letter-long string, and it must be from <code>words</code>. <code>Master.guess(word)</code> returns:</p>

<ul>
	<li><code>-1</code> if <code>word</code> is not from <code>words</code>, or</li>
	<li>an integer representing the number of exact matches (value and position) of your guess to the secret word.</li>
</ul>

<p>There is a parameter <code>allowedGuesses</code> for each test case where <code>allowedGuesses</code> is the maximum number of times you can call <code>Master.guess(word)</code>.</p>

<p>For each test case, you should call <code>Master.guess</code> with the secret word without exceeding the maximum number of allowed guesses. You will get:</p>

<ul>
	<li><strong><code>"Either you took too many guesses, or you did not find the secret word."</code></strong> if you called <code>Master.guess</code> more than <code>allowedGuesses</code> times or if you did not call <code>Master.guess</code> with the secret word, or</li>
	<li><strong><code>"You guessed the secret word correctly."</code></strong> if you called <code>Master.guess</code> with the secret word with the number of calls to <code>Master.guess</code> less than or equal to <code>allowedGuesses</code>.</li>
</ul>

<p>The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
<strong>Output:</strong> You guessed the secret word correctly.
<strong>Explanation:</strong>
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess, and one of them was the secret, so we pass the test case.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
<strong>Output:</strong> You guessed the secret word correctly.
<strong>Explanation:</strong> Since there are two words, you can guess both.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>words[i].length == 6</code></li>
	<li><code>words[i]</code> consist of lowercase English letters.</li>
	<li>All the strings of <code>wordlist</code> are <strong>unique</strong>.</li>
	<li><code>secret</code> exists in <code>words</code>.</li>
	<li><code>10 &lt;= allowedGuesses &lt;= 30</code></li>
</ul>
</div>