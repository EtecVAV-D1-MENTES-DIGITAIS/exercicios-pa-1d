#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct PriorityCompare {
    map<string,int> *prioridade;
    PriorityCompare(map<string,int> *p) : prioridade(p) {}
    bool operator()(const string &a, const string &b) const {
        return (*prioridade)[a] < (*prioridade)[b];
    }
};

int main() {
    int N, M;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        map<string, vector<string> > adj;
        map<string, int> indegree;
        map<string, int> prioridade;
        vector<string> ordem; 

        for (int i = 0; i < N; i++) {
            string materia;
            int K;
            cin >> materia >> K;

            if (prioridade.find(materia) == prioridade.end()) {
                prioridade[materia] = (int)ordem.size();
                ordem.push_back(materia);
            }

            for (int j = 0; j < K; j++) {
                string prereq;
                cin >> prereq;

                if (prioridade.find(prereq) == prioridade.end()) {
                    prioridade[prereq] = (int)ordem.size();
                    ordem.push_back(prereq);
                }

                adj[prereq].push_back(materia);
                indegree[materia]++;
                if (indegree.find(prereq) == indegree.end()) indegree[prereq] = 0;
            }
        }

        vector<string> disponiveis;
        for (map<string,int>::iterator it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0) disponiveis.push_back(it->first);
        }

        vector< vector<string> > semestres;

        while (!disponiveis.empty()) {
            sort(disponiveis.begin(), disponiveis.end(), PriorityCompare(&prioridade));

            int pegar = min(M, (int)disponiveis.size());
            vector<string> escolhidas(disponiveis.begin(), disponiveis.begin() + pegar);
            disponiveis.erase(disponiveis.begin(), disponiveis.begin() + pegar);

            for (size_t i = 0; i < escolhidas.size(); i++) {
                string mat = escolhidas[i];
                for (size_t j = 0; j < adj[mat].size(); j++) {
                    string prox = adj[mat][j];
                    indegree[prox]--;
                    if (indegree[prox] == 0) {
                        disponiveis.push_back(prox);
                    }
                }
            }

            sort(escolhidas.begin(), escolhidas.end());
            semestres.push_back(escolhidas);
        }

        cout << "Formatura em " << semestres.size() << " semestres\n";
        for (int i = 0; i < (int)semestres.size(); i++) {
            cout << "Semestre " << i+1 << " :";
            for (size_t j = 0; j < semestres[i].size(); j++) {
                cout << " " << semestres[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
