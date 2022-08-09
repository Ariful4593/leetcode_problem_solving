class Stack {
    constructor() {
        this.items = [];
        this.count = 0;
    }
    push(element) {
        this.items[this.count] = element;
        this.count++;
        return this.count - 1
    }


    pop() {
        if (this.count === 0) return undefined;
        let deleteItems = this.items[this.count - 1]
        // console.log(`${deleteItems} removed`)
        this.count--
        return deleteItems
    }
}

const isPalindrome = (element) => {
    const stack = new Stack();

    for (let index = 0; index < element.length; index++) {
        stack.push(element[index])
    }

    let reword = '';
    while (stack.count > 0) {
        reword += stack.pop()
    }
    if (reword === element) {
        return true
    } else {
        return false
    }
}
if(isPalindrome('racecar')){
    console.log('Palindrome')
}else{
    console.log('Not palindrome')
}
