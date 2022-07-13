#include <iostream>

#include "Backtracking.h"

using namespace std;


int main()
{   

    int num = 0; //Numero de fichar
    vector<int> final_state;
    vector<int> start;
    

    cout << "Inicio do Jogo das fichas:" << endl;
    cout << "Digite o numero de fichas ( Pretas [1], Brancas [-1], Espaço vazio 0 ) => Regra: Numero de fichas tem que ser maior que 1 para cara cor." << endl;
    cin >> num;
    cout<<"Numero de fichas: " << num << " Pretas, " << num << " Brancas" << endl;
    int size = 2 * num + 1;
    int x;


     cout << "Digite o estado inicial de "<< size <<" :"<< endl;
    


    for(int i=0;i<size; i++){
        cin >> x;
        start.push_back(x);
    }

    cout << "Digite o estado final de "<< size <<" :"<< endl;
    


    for(int i=0;i<size; i++){
        cin >> x;
        final_state.push_back(x);
    }
     


    BackTracking *teste = new BackTracking();
    teste->set_start(start);
    teste->set_goal(final_state);
    teste->init(num);

    return 0;
}

//g++ -o exec -O3 *.cpp 
//./exec