// Runtime: 149 ms (Top 9.09%) | Memory: 44.8 MB (Top 18.89%)
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, color) {
    const pixelsToCheck = [[sr, sc]]
    const startingPixelColor = image[sr][sc]
    const directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    const seenPixels = new Set()

    if (
        startingPixelColor === undefined ||
        startingPixelColor === color
    ) return image

    for (const pixel of pixelsToCheck) {
        const currentPixelColor = image[pixel[0]]?.[pixel[1]]

        if (
            currentPixelColor === undefined ||
            startingPixelColor !== currentPixelColor
        ) continue

        image[pixel[0]][pixel[1]] = color

        for (const direction of directions) {
            const newPixel = [pixel[0] + direction[0], pixel[1] + direction[1]]
            const pixelString = newPixel.join()

            if (seenPixels.has(pixelString)) continue

            pixelsToCheck.push(newPixel)
            seenPixels.add(pixelString)
        }
    }

    return image
};