<h3 align="left"> 1348. Tweet Counts Per Frequency</h3>
<div><p>A social media company is trying to monitor activity on their site by analyzing the number of tweets that occur in select periods of time. These periods can be partitioned into smaller <strong>time chunks</strong> based on a certain frequency (every <strong>minute</strong>, <strong>hour</strong>, or <strong>day</strong>).</p>

<p>For example, the period <code>[10, 10000]</code> (in <strong>seconds</strong>) would be partitioned into the following <strong>time chunks</strong> with these frequencies:</p>

<ul>
	<li>Every <strong>minute</strong> (60-second chunks): <code>[10,69]</code>, <code>[70,129]</code>, <code>[130,189]</code>, <code>...</code>, <code>[9970,10000]</code></li>
	<li>Every <strong>hour</strong> (3600-second chunks): <code>[10,3609]</code>, <code>[3610,7209]</code>, <code>[7210,10000]</code></li>
	<li>Every <strong>day</strong> (86400-second chunks): <code>[10,10000]</code></li>
</ul>

<p>Notice that the last chunk may be shorter than the specified frequency's chunk size and will always end with the end time of the period (<code>10000</code> in the above example).</p>

<p>Design and implement an API to help the company with their analysis.</p>

<p>Implement the <code>TweetCounts</code> class:</p>

<ul>
	<li><code>TweetCounts()</code> Initializes the <code>TweetCounts</code> object.</li>
	<li><code>void recordTweet(String tweetName, int time)</code> Stores the <code>tweetName</code> at the recorded <code>time</code> (in <strong>seconds</strong>).</li>
	<li><code>List&lt;Integer&gt; getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime)</code> Returns a list of integers representing the number of tweets with <code>tweetName</code> in each <strong>time chunk</strong> for the given period of time <code>[startTime, endTime]</code> (in <strong>seconds</strong>) and frequency <code>freq</code>.
	<ul>
		<li><code>freq</code> is one of <code>"minute"</code>, <code>"hour"</code>, or <code>"day"</code> representing a frequency of every <strong>minute</strong>, <strong>hour</strong>, or <strong>day</strong> respectively.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<pre><strong>Input</strong>
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

<strong>Output</strong>
[null,null,null,null,[2],[2,1],null,[4]]

<strong>Explanation</strong>
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);                              // New tweet "tweet3" at time 0
tweetCounts.recordTweet("tweet3", 60);                             // New tweet "tweet3" at time 60
tweetCounts.recordTweet("tweet3", 10);                             // New tweet "tweet3" at time 10
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]; chunk [0,59] had 2 tweets
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2,1]; chunk [0,59] had 2 tweets, chunk [60,60] had 1 tweet
tweetCounts.recordTweet("tweet3", 120);                            // New tweet "tweet3" at time 120
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]; chunk [0,210] had 4 tweets
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= time, startTime, endTime &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= endTime - startTime &lt;= 10<sup>4</sup></code></li>
	<li>There will be at most <code>10<sup>4</sup></code> calls <strong>in total</strong> to <code>recordTweet</code> and <code>getTweetCountsPerFrequency</code>.</li>
</ul>
</div>