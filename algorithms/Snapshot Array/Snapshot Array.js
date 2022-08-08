var SnapshotArray = function(length) {
    this.snaps = []
    this.currentIndex = 0
    this.currentSnaps = []
}

SnapshotArray.prototype.set = function(index, val) {
    this.currentSnaps[index] = val
}

SnapshotArray.prototype.snap = function() {
    this.snaps[this.currentIndex] = [...this.currentSnaps]
    
    return this.currentIndex++
}

SnapshotArray.prototype.get = function(index, snap_id) {
    const res = this.snaps[snap_id]
    
    if (res[index] === undefined) return 0
    
    return res[index]
}
