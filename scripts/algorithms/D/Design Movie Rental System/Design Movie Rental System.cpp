// Runtime: 1596 ms (Top 70.59%) | Memory: 410.3 MB (Top 60.51%)

int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class MovieRentingSystem {
public:

    #define pppi pair<int, pair <int, int>>

    set < pppi > unrented,rented;

    map < pair <int, int>, int > mp;

    // facilitates search by storing the prices and shops a particular movie is associated with
    unordered_map <int, set < pair <int, int> > > movies;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(int i = 0; i < entries.size(); i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];

            // initially all movies are unrented
            unrented.insert({price, {shop, movie}});

            // store the price for each pair of {shop,movie}. remember this pair is unique as given in the problem statement
            mp[{shop,movie}] = price;

            // store all the movies with their price and shop
            movies[movie].insert({price,shop});
        }
    }

    vector<int> search(int movie) {

        // return a list of 5 cheapest shops that have the given movie

        vector <int> ans;

        for(auto x : movies[movie])
        {
            if((int)ans.size()==5)
                break;

            ans.push_back(x.second);
        }

        return ans;
    }

    void rent(int shop, int movie) {
        // remove the movie from the given shop

        int price = mp[{shop,movie}];

        // add this movie in rented
        rented.insert({price, {shop, movie}});

        // remove this movie from unrented
        unrented.erase({price, {shop, movie}});

        // also, erase this shop from the movies, since this movie will be no longer present in the given shop
        movies[movie].erase(movies[movie].find({price,shop}));
    }

    void drop(int shop, int movie) {
        // return or add

        int price = mp[{shop,movie}];

        // add in unrented as movie is back in the shop
        unrented.insert({price, {shop, movie}});

        movies[movie].insert({price,shop});

        // remove from rented
        rented.erase({price, {shop, movie}});
    }

    vector<vector<int>> report() {
        // return the 5 cheapest rented movies as {shop, movie}

        // here comes the use of rented data structure, since we can quickly select 5 cheapest movies that are rented
        vector<vector<int>> ans;

        for(auto x : rented)
        {
            if(ans.size() == 5)
                break;

            int shop = x.second.first;
            int movie = x.second.second;

            ans.push_back({shop,movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */