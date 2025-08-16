#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;

int main(int argc, char** argv) {
    string linha;
    int primo;
    bool isPrimo;

    while (true) {
        getline(cin, linha);

        if (linha == "0") {
            break;
        }

        primo = atoi(linha.c_str());
        isPrimo = true;

        for (int i = 2; i < primo; i++) {
            if ((primo % i) == 0 && (i != primo)) {
                isPrimo = false;
                break;
            }
        }

        if (primo > 1) {
            if (isPrimo) {
                cout << primo;
            }
        }
    }

    return 0;
}
