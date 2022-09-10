// Runtime: 267 ms (Top 50.74%) | Memory: 54.4 MB (Top 57.18%)
var findAllRecipes = function(recipes, ingredients, supplies) {
    const setOfIngredients = new Set(supplies);
    const recipesWithIngredients = new Map();
    const progress = new Map();
    //map recipes to it's ingredients and set each recipe to false in another map called progress
    for(let i = 0; i < recipes.length; i++) {
        recipesWithIngredients.set(recipes[i], ingredients[i]);
        progress.set(recipes[i], false)
    }

    const result = [];

    for(const rec of recipes) {
        if(recurse(rec, recipesWithIngredients, setOfIngredients, progress)) {
            result.push(rec);
            setOfIngredients.add(rec);
        }
    }

    return result;
};

function recurse(rec, recipesWithIngredients, setOfIngredients, progress) {
    const currentIngredients = recipesWithIngredients.get(rec);
    for(const ingredient of currentIngredients) {
        if(setOfIngredients.has(rec)) continue;
        if(setOfIngredients.has(ingredient)) continue;

        else if(recipesWithIngredients.has(ingredient)) {
            if(progress.get(ingredient)) return false;
            progress.set(ingredient, true);
            let hasCycle = recurse(ingredient, recipesWithIngredients, setOfIngredients, progress);
            if(!hasCycle) return false;
            setOfIngredients.add(ingredient);
        } else {
            return false;
        }
    }
    return true;
}