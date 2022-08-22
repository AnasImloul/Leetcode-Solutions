// Runtime: 1005 ms (Top 57.89%) | Memory: 120.3 MB (Top 22.81%)
var bloodList = function(name, parent = null) {
    return {
        name,
        children: []
    };
}

var ThroneInheritance = function(kingName) {
    this.nameMap = new Map();
    this.nameMap.set(kingName, bloodList(kingName));
    this.king = kingName;
    this.deadList = new Set();
};

/**
 * @param {string} parentName
 * @param {string} childName
 * @return {void}
 */
ThroneInheritance.prototype.birth = function(parentName, childName) {
    const parent = this.nameMap.get(parentName);
    const childId = bloodList(childName, parent);
    this.nameMap.set(childName, childId);
    parent.children.push(childId);
};

/**
 * @param {string} name
 * @return {void}
 */
ThroneInheritance.prototype.death = function(name) {
    this.deadList.add(name);
};

/**
 * @return {string[]}
 */
function updateList(list, nameId, deadList) {
    if (!deadList.has(nameId.name))
        list.push(nameId.name);

    for (let child of nameId.children) {
        updateList(list, child, deadList);
    }
}

ThroneInheritance.prototype.getInheritanceOrder = function() {
    let list = [];
    updateList(list, this.nameMap.get(this.king), this.deadList);
    return list;
};