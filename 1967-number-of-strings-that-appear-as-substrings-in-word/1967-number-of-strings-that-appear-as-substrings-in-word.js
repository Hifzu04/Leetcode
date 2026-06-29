/**
 * @param {string[]} patterns
 * @param {string} word
 * @return {number}
 */
var numOfStrings = function(patterns, word) {
    let ans =0 ;
    for(let pattern of patterns){
        if(word.includes(pattern)){
            ans++;
        }
    }
    return ans; 
};