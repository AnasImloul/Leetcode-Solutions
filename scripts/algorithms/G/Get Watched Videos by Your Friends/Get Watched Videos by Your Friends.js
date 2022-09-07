// Runtime: 300 ms (Top 33.33%) | Memory: 55.7 MB (Top 66.67%)
/**
 * @param {string[][]} watchedVideos
 * @param {number[][]} friends
 * @param {number} id
 * @param {number} level
 * @return {string[]}
 */
var watchedVideosByFriends = function(watchedVideos, friends, id, level) {
  const queue = [];
  queue.push([id, 0]);
  const seen = new Set();
  const map = {};

  while (queue.length > 0) {
    const [id, _level] = queue.shift();
    if (seen.has(id)) {
      continue;
    }
    seen.add(id);
    if (_level == level) {
      for (const video of watchedVideos[id]) {
        if (!map[video]) {
          map[video] = 1
        } else {
          map[video] += 1;
        }
      }
      continue;
    }

    for (const f of friends[id]) {
      queue.push([f, _level + 1]);
    }
  }

  return Object.keys(map).sort((a, b) => {
    const diff = map[a] - map[b];
    if (diff == 0) {
      return a.localeCompare(b);
    }
    return diff;
  })
};