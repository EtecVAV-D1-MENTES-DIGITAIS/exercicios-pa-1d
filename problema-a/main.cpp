#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    int teste = 1;

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break; 
        }

        vector<int> temperaturas(N);
        for (int i = 0; i < N; i++) {
            cin >> temperaturas[i];
        }

        int menorMedia = INT_MAX;
        int maiorMedia = INT_MIN;

        for (int i = 0; i <= N - M; i++) {
            int soma = 0;
            for (int j = i; j < i + M; j++) {
                soma += temperaturas[j];
            }
            int media = soma / M; 
            if (media < menorMedia) menorMedia = media;
            if (media > maiorMedia) maiorMedia = media;
        }

        cout << "Teste " << teste++ << "\n";
        cout << menorMedia << " " << maiorMedia << "\n\n";
    }

    return 0;
}

