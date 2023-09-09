// Runtime: 408 ms (Top 22.2%) | Memory: 128.88 MB (Top 44.4%)

/**
 * @param {string[]} creators
 * @param {string[]} ids
 * @param {number[]} views
 * @return {string[][]}
 */
var mostPopularCreator = function(creators, ids, views) {
    dict = {}
    let maxViews = 0;
    let mostPopularCreators = [];
    let mostViewedVideos = [];
    for (let i = 0; i < creators.length; i++) {
        let name = creators[i]
        
        if (dict[name] === undefined) {    
            dict[name] = {
                totalViews: views[i],
                mostViewed: views[i],
                mostPopular: ids[i]
            };
        } else {
            dict[name].totalViews += views[i];
            if (views[i] > dict[name].mostViewed) {
                dict[name].mostPopular = ids[i]
            } else if (views[i] == dict[name].mostViewed) {
                console.log([dict[name].mostPopular, ids[i]].sort())
                dict[name].mostPopular = [dict[name].mostPopular, ids[i]].sort()[0]
            }
            dict[name].mostViewed = [Math.max(dict[name].mostViewed, views[i])]
        }
        maxViews = Math.max(dict[name].totalViews, maxViews);
    }

    for (let name in dict) {
        if (dict[name].totalViews === maxViews) {
            mostPopularCreators.push(name);
            mostViewedVideos.push(dict[name].mostPopular)
        }
    }

    let result = [];
    for (let i = 0; i < mostPopularCreators.length; i++) {
        result.push([mostPopularCreators[i], mostViewedVideos[i]])
    }
    return result;
};