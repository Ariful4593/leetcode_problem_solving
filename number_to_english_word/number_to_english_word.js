const underTwenty = ['One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'];

const tens = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'];

const chunks = ['Thousand', 'Million', 'Billion', 'Trillion'];

const getString = (number) => {
    if (number == 0) {
        return "";
    }

    if (number < 20) {
        return underTwenty[number - 1];
    }

    if (number < 100) {
        return tens[Math.floor(number / 10) - 2] + " " + getString(number % 10);
    }

    if (number < 1000) {
        const quotient = Math.floor(number / 100);
        const remainder = number % 100;
        return underTwenty[quotient - 1] + " Hundred " + getString(remainder);
    }

    for (let pow = 1; pow <= chunks.length; pow++) {
        const chunk = chunks[pow - 1];
        if (number < Math.pow(1000, pow + 1)) {
            const quotient = Math.floor(number / Math.pow(1000, pow));
            const remainder = number % Math.pow(1000, pow);
            return getString(quotient) + chunk + " " + getString(remainder) + " ";
        }
    }

}

function test(num) {
    if (num == 0) {
        return "Zero";
    }
    const result = getString(num);
    console.log(result.trim())
};
const num = 1559;
test(num)
