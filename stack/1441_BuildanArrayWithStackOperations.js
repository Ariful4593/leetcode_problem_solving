// Input: target = [1,3], n = 3
// Output: ["Push","Push","Pop","Push"]
const test = (list, n) => {
    let i = 0, counter = 1;
    let newList = [];
    while (i < list.length) {
        if (counter === list[i]) {
            newList.push('Push');
            i++;
        } else {
            newList.push('Push');
            newList.push('Pop');
        }
        counter++;
    }
    return newList;
}
console.log(test([1, 3], 3))
