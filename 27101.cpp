#include <iostream>
using namespace std;

long long power(long long num, int sp);

int main() {
    long long num;
    cout << "請輸入卡號:";
    cin >> num;

    if (num / 1000000000000000 > 0) {
        if (num / 1000000000000000 == 4) {
            cout << "VISA" << "\n";
        } else {
            int quotient = num / 100000000000000;
            if (quotient >= 51 && quotient <= 55) {
                cout << "MasterCard" << "\n";
            } else {
                cout << "卡號錯誤" << "\n";
                return 0;
            }
        }
    } else if (num / 100000000000000 > 0) {
        int quotient = num / 10000000000000;
        if (quotient == 34 || quotient == 37) {
            cout << "American Express" << "\n";
        } else {
            cout << "卡號錯誤" << "\n";
            return 0;
        }
    } else if (num / 10000000000000 > 0) {
        cout << "卡號錯誤" << "\n";
        return 0;
    } else if (num / 1000000000000 > 0) {
        int quotient = num / 1000000000000;
        if (quotient == 4) {
            cout << "VISA" << "\n";
        } else {
            cout << "卡號錯誤" << "\n";
            return 0;
        }
    } else {
        cout << "卡號錯誤" << "\n";
        return 0;
    }

    long long checksum[16];
    // cout << num << "--\n";

    int total = 0;

    for(int i = 1; i <= 16; i++) {
        checksum[i - 1] = num % power(10,i);
        // cout << checksum[i-1] << "--\n";
        checksum[i - 1] /= power(10,i - 1);
        // cout << checksum[i-1] << "\n";

        if(i % 2 == 0) {
            checksum[i - 1] *= 2;
            checksum[i - 1] = (checksum[i - 1] / 10) + (checksum[i - 1] % 10);
        } else {
            checksum[i - 1] *= 1;
        }

        total = total + checksum[i - 1];
    }

    // cout << total << "\n";

    if(total % 10 == 0) {
        cout << "卡號無誤";
    } else {
        cout << "卡號有誤";
    }


}

long long power(long long num, int sp) {
    long long res = 1;
    for (int i = 0; i < sp; i++) {
        res *= num;
    }
    return res;
}

// 650275 杜心妍
