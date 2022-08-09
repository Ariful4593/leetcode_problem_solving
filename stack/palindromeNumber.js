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
    const newElement = element.toString();

    for (let index = 0; index < newElement.length; index++) {
        stack.push(newElement[index])
    }

    let reword = '';
    while (stack.count > 0) {
        reword += stack.pop()
    }
    if (reword === newElement) {
        return true
    } else {
        return false
    }
}
if (isPalindrome(121)) {
    console.log('Palindrome')
} else {
    console.log('Not palindrome')
}
