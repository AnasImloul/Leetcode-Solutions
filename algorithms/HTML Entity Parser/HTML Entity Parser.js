/**
 * @param {string} text
 * @return {string}
 */
var entityParser = function(text) {
    const entityMap = {
        '&quot;': `"`,
        '&apos;': `'`,
        '&amp;': `&`,
        '&gt;': `>`,
        '&lt;': `<`,
        '&frasl;': `/`
    }
    
    stack = [], entity = "";
    
    for(const char of text) {
        stack.push(char);
        if(char == '&') {
            if(entity.length > 0) entity = "";
            entity += char;
        }
        else if(char == ';' && entity.length > 0) {
            entity += char;
            
            if(entity in entityMap) {
                while(stack.length && stack[stack.length - 1] !== '&') {
                    stack.pop();
                }
                stack.pop();
                stack.push(entityMap[entity]);
            }
            
            entity = "";
        }
        else if(entity.length > 0) {
            entity += char;
        }
    }
    
    return stack.join('');
};
