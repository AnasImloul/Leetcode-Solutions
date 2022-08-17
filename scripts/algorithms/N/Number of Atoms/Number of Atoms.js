var countOfAtoms = function(formula) {
    function getElementCount(flatFormula) {
        const reElementCount = /([A-Z][a-z]*)(\d*)/g;
        let matches = flatFormula.matchAll(reElementCount);
        
        let output = new Map();
        
        for (let [match, element, count] of matches) {
            count = count === '' ? 1 : +count;
            
            if (output.has(element)) {
                output.set(element, output.get(element) + count);
            } else {
                output.set(element, count);
            }
        }
        
        return output;
    }
    
    function flattenElementCount(elCountMap) {
        let arr = [...elCountMap.entries()].sort();
        
        return arr.reduce( (str, item) => {
            let num = item[1] === 1 ? '' : item[1];
            return str + item[0] + num;
        }, '' );
    }
    
    function unnest(fullMatch, innerFormula, multiplier) {
        let elementCount = getElementCount(innerFormula);
        multiplier = multiplier === '' ? 1 : +multiplier;
        
        for (let [element, count] of elementCount) {
            elementCount.set(element, elementCount.get(element) * multiplier);
        }
        
        return flattenElementCount(elementCount);
    }
    
    function flattenFormula(formula) {
        const reNested = /\((\w+)\)(\d*)/g;
        
        while (reNested.test(formula)) {
            formula = formula.replaceAll(reNested, unnest);
        }
        
        return formula;
    }
    
    let flatFormula = flattenFormula(formula);    
    
    return flattenElementCount(getElementCount(flatFormula));
};
