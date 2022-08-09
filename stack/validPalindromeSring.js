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
        let deleteItems = this.items[this.count - 1];
        this.count--
        return deleteItems
    }
}

const isPalindrome = (element) => {
    const newElement = element.toString().toLowerCase().replace(/[^a-z0-9]/gi, '');
    const stack = new Stack();

    for (let index = 0; index < newElement.length; index++) {
        stack.push(newElement[index]);
    }

    let rword = ''
    while (stack.count > 0) {
        rword += stack.pop();
    }

    if (rword === newElement) {
        return true
    } else {
        return false
    }
}

console.log(isPalindrome('A man, a plan, a canal: Panama'))

const test = 'arif';