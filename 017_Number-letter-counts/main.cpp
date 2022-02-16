#include <iostream>



/*
 * LEN = 1
 *
 * 1 => 3
 * 2 => 3
 * 3 => 5
 * 4 => 4
 * 5 => 4
 * 6 => 3
 * 7 => 5
 * 8 => 5
 * 9 => 4
 *
 *  LEN = 2
 *
 * 10 => 3
 * 11 => 6
 * 12 => 6
 * 13 => 8
 * 14 => 8
 * 15 => 7
 * 16 => 7
 * 17 => 9
 * 18 => 8
 * 19 => 8
 * 2* => 6 + *
 * [4679]* => *+2 + *
 * 3* => 6 + *
 * 5* => 5 + *
 * 8* => 6 + *
 * 0* => 0 + *
 *
 *  LEN = 3
 *
 * [1-9]** => *+(10, when ** != 00 else 7) + **
 *
 *  LEN = 4
 *
 *  1000 => 11
 */


static int len1(const int num) {
/*
 * LEN = 1
 *
 * 1 => 3
 * 2 => 3
 * 3 => 5
 * 4 => 4
 * 5 => 4
 * 6 => 3
 * 7 => 5
 * 8 => 5
 * 9 => 4
 */
    switch (num) {
    case 0: return 0;
    case 1: return 3;
    case 2: return 3;
    case 3: return 5;
    case 4: return 4;
    case 5: return 4;
    case 6: return 3;
    case 7: return 5;
    case 8: return 5;
    case 9: return 4;
    default: throw std::invalid_argument("Weird");
    }
}

static int len2(const int num) {
/*  LEN = 2
 *
 * 10 => 3
 * 11 => 6
 * 12 => 6
 * 13 => 8
 * 14 => 8
 * 15 => 7
 * 16 => 7
 * 17 => 9
 * 18 => 8
 * 19 => 8
 * 2* => 6 + *
 * [679]* => *+2 + *
 * 3* => 6 + *
 * 5* => 5 + *
 * 8* => 6 + *
 */
    const char x_times_ten = std::to_string(num)[0];
    if (x_times_ten == '1') {
        switch (num % 10) {
        case 0: return 3;
        case 1: return 6;
        case 2: return 6;
        case 3: return 8;
        case 4: return 8;
        case 5: return 7;
        case 6: return 7;
        case 7: return 9;
        case 8: return 8;
        case 9: return 8;
        default: throw std::invalid_argument("Weird");
        }
    } else if (x_times_ten == '2' || x_times_ten == '3' || x_times_ten == '8') {
        return 6 + len1(num%10);
    } else if (x_times_ten == '5' || x_times_ten == '4') {
        return 5 + len1(num%10);
    } else {
        return len1((int) num/10.0) + 2 + len1(num%10);
    }
}

static int len3(const int num) {
/*  LEN = 3
 *
 * [1-9]** => *+(10, when ** != 00 else 7) + **
 */
    if (num % 100 == 0) return len1(num%10) + 7;
    return len1(num%10) + 10 + len2(num%100);
}

static int len4() { return 11; }

int main() {
    int sumOfLetters = 0;

    for (int i = 1; i <= 1000; i++) {
        const int length = std::to_string(i).length();

        switch (length) {
        case 1: sumOfLetters += len1(i); break;
        case 2: sumOfLetters += len2(i); break;
        case 3: sumOfLetters += len3(i); break;
        case 4: sumOfLetters += len4(); break;
        default: throw std::invalid_argument("Weird");
        }
    }

    std::cout << "Sum of letters: " << sumOfLetters << std::endl;

    return 0;
}
