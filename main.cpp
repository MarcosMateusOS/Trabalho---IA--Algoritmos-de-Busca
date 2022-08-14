#include <iostream>
#include <fstream>
#include "Backtracking.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "OrdinateSearch.h"
#include "GreedySearch.h"
#include "AStarSearch.h"
#include "IDAStarSearch.h"

using namespace std;



int main()
{   

    int num = 0; //Numero de fichar
    vector<int> final_state;
    vector<int> start;
    

    cout << "Inicio do Jogo das fichas:" << endl;
    cout << "Digite o numero de fichas (Pretas [1], Brancas [-1], *Espaço vazio 0 )\nRegra: Numero de fichas tem que ser maior do que 1 para cada cor." << endl;
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

    cout << "Arquivo TXT criado" << endl;
    ofstream arq; 
    arq.open("output.txt", ios::ate | ios::out | ios::in);
    
     

    
    BackTracking *backtracking = new BackTracking(num,start,final_state);
    backtracking->init(arq);

    
    BreadthFirstSearch *breadthFirstSearch = new BreadthFirstSearch(num,start,final_state);
    breadthFirstSearch->init(arq);

    DepthFirstSearch *depthFirstSearch = new DepthFirstSearch(num,start,final_state);
    depthFirstSearch->init(arq);
    

    OrdinateSearch *ordinateSearch = new OrdinateSearch(num,start,final_state);
    ordinateSearch->init(arq);
    

    GreedySearch *greedySearch = new GreedySearch(num,start,final_state);
    greedySearch->init(arq);

    AStarSearch *aStartSearch = new AStarSearch(num,start,final_state);
    aStartSearch->init(arq);

    IDAStarSearch *idaStartSearch = new IDAStarSearch(num,start,final_state);
    idaStartSearch->init(arq);

    arq.close();


    return 0;
}

//g++ -o exec -O3 *.cpp 
//./exec