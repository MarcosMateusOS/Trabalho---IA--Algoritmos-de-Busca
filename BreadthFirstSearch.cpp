#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <vector>
#include <queue>  
#include "BreadthFirstSearch.h"
#include "Actions.h"

using namespace std;
using namespace std::chrono;

BreadthFirstSearch::BreadthFirstSearch(int tam,vector<int> start,vector<int> final_state){
    this->root = NULL;
    this->start = start;
    this->goal = final_state;
    
}
bool BreadthFirstSearch::is_goal(vector<int> arr){

    if(arr == this->goal){
        return true;
    } else {
        return false;
    }
    
}

bool BreadthFirstSearch::verify_closed(vector<int> arr,queue<No*> closed){

    for (std::queue<No*> aux = closed; !aux.empty(); aux.pop())
    {      
        No *test = aux.front();

       if(arr == test->get_state()){
        return true;
        } else {
            return false;
        }
    }

    return false;

    
}

void BreadthFirstSearch::set_goal(vector<int> arr){
    this->goal = arr;
}

void BreadthFirstSearch::set_start(vector<int> arr){
    this->start = arr;
}

 void BreadthFirstSearch::path(No *no,std::ofstream& myfile){
     No *aux = no;
     vector<vector<int>> path_reverse;

     while (aux != NULL)
     {     
        path_reverse.push_back(aux->get_state());
        aux = aux->get_father();
     }

     std::reverse(path_reverse.begin(),path_reverse.end());

     for(int i = 0; i < path_reverse.size(); i++){
         myfile<<"[";
          for (auto it = path_reverse[i].begin();
             it != path_reverse[i].end(); it++) {
            myfile << *it << ',';
        }
         myfile<<"] => " << endl;
     }
     
 }



void BreadthFirstSearch::init(std::ofstream& myfile) {
    

    for(int i = 0; i < 100; i++)
    {
        myfile<< "-";
    }
    myfile << endl;
    myfile<< "Busca em largura: "<< endl;
    bool s = false;
    bool f = false;

    int visited = 0;
    int expanded = 0;
    int cost = 0;
    int depth = 0;
    int level = 0;
    int leaf = 0;

    root = new No(tam);

    

    root->set_state(this->start);

    Actions *action = new Actions();
    int count = 0;
    No *aux = new No(tam);
    aux = root;
    aux->set_father(NULL);


    queue<No*> openers;
    queue<No*> closed;
    openers.push(aux);

    

    auto start = std::chrono::high_resolution_clock::now();
    while (s != true || f != true)
    {   
           if(openers.empty()){
                f = true;
                myfile << "Resultado => Fracasso" << endl;
                break;
           }else{
                aux = openers.front();
                
                if(this->is_goal(aux->get_state())){
                    myfile << "Sucesso" << endl;
                    s = true;
                    break;
                }else {
                     openers.pop();// retiro da fila de abertos
                    for(int i = 1; i<=4; i++){
                        vector<int> aux_state = aux->get_state();
                        No *aux2 = new No(tam);          
                       

                        if(i == 1){
                             bool check = action->exec(aux,1,aux_state);
                           

                            if(check == true)
                            {   
                                
                                 if(!verify_closed(aux_state,closed))
                                {
                                    aux2->set_state(aux_state);
                                    aux2->set_father(aux);
                                    aux2->set_cost(1 + aux->get_cost());
                                    aux->set_son1(aux2);
                                    openers.push(aux2);

                                    if(depth < aux2->get_cost()){
                                        depth = aux2->get_cost();
                                    }
                                    
                                }
                            } 
                        }

                         if(i == 2){
                             bool check = action->exec(aux,2,aux_state);
                           

                            if(check == true)
                            {   
                                
                                if(!verify_closed(aux_state,closed))
                                {
                                    aux2->set_state(aux_state);
                                    aux2->set_father(aux);
                                    aux2->set_cost(2 + aux->get_cost());
                                    aux->set_son2(aux2);
                                    openers.push(aux2);

                                    if(depth < aux2->get_cost()){
                                        depth = aux2->get_cost();
                                    }
                                }
                            } 
                        }

                         if(i == 3){
                             bool check = action->exec(aux,3,aux_state);
                           

                            if(check == true)
                            {   
                                
                                 if(!verify_closed(aux_state,closed))
                                {
                                    aux2->set_state(aux_state);
                                    aux2->set_father(aux);
                                    aux2->set_cost(3 + aux->get_cost());
                                    aux->set_son3(aux2);
                                    openers.push(aux2);

                                    if(depth < aux2->get_cost()){
                                        depth = aux2->get_cost();
                                    }
                                }
                               
                            } 
                        }

                         if(i == 4){
                             bool check = action->exec(aux,4,aux_state);
                           

                            if(check == true)
                            {   
                                
                                 if(!verify_closed(aux_state,closed))
                                {
                                    aux2->set_state(aux_state);
                                    aux2->set_father(aux);
                                    aux2->set_cost(4 + aux->get_cost());
                                    aux->set_son4(aux2);
                                    openers.push(aux2);

                                    if(depth < aux2->get_cost()){
                                        depth = aux2->get_cost();
                                    }
                                }
                                
                            } 
                        }



                    }
                    closed.push(aux); // insiro na de fechados
                    
                }
           }
    } 
    expanded = closed.size();
    visited = openers.size() + expanded;
    float average = float((expanded - 1)) / visited;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    myfile <<"Visitados: "<< visited << endl;
    myfile <<"Profundidade: "<< depth << endl;
    myfile <<"Expandidos: " << expanded << endl;
    myfile <<"Fato médio de ramificação: "<< average << endl; 
    myfile <<"Tempo da Busca: "<<float_ms.count() << "s" <<endl;

    if(s == true){
        myfile << "Caminho:" << endl;
        this->path(aux,myfile);
    }

    for(int i = 0; i < 100; i++)
    {
        myfile<< "-";
    }
    
    
}
