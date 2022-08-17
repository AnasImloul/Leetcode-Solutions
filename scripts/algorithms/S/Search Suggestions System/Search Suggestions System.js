function TrieNode(key) {
  this.key = key
  this.parent = null
  this.children  = {}
  this.end = false
  
  this.getWord = function() {
    let output = []
    let node = this
    
    while(node !== null) {
      output.unshift(node.key)
      node = node.parent
    }
    
    return output.join('')
  }
} 

function Trie() {
  this.root = new TrieNode(null)
  
  this.insert = function(word) {
    let node = this.root
    
    for (let i = 0; i < word.length; i++) {
      if (!node.children[word[i]]) {
        node.children[word[i]] = new TrieNode(word[i])
        node.children[word[i]].parent = node
      }
      
      node = node.children[word[i]]
      
      if (i === word.length - 1) {
        node.end = true
      }
    }
  }
  
  this.findAllWords = function (node, arr) {
    if (node.end) {
      arr.unshift(node.getWord());
    }

    for (let child in node.children) {
      this.findAllWords(node.children[child], arr);
    }
  }
  
  this.find  = function(prefix) {
    let node = this.root
    let output = []

    for(let i = 0; i < prefix.length; i++) {
      if (node.children[prefix[i]]) {
        node = node.children[prefix[i]]
      } else {
        return output
      }
    }

    this.findAllWords(node, output)
    
    output.sort()

    return output.slice(0, 3)
  }
  
  this.search = function(word) {
    let node = this.root
    let output = []
    
    for (let i = 0; i < word.length; i++) {
      output.push(this.find(word.substring(0, i + 1)))
    }
    
    return output
  }
}

/**
 * @param {string[]} products
 * @param {string} searchWord
 * @return {string[][]}
 */
var suggestedProducts = function(products, searchWord) {
  let trie = new Trie()
  
  for (let product of products) {
    trie.insert(product)
  }
  
  return trie.search(searchWord)
};
