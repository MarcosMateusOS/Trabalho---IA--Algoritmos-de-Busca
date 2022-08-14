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
#include "Backtracking.h"
#include "Actions.h"

using namespace std;
using namespace std::chrono;
BackTracking::BackTracking(int tam,vector<int> start,vector<int> final_state){
    this->root = NULL;
    this->start = start;
    this->goal = final_state;
}
bool BackTracking::is_goal(vector<int> arr){

    if(arr == this->goal){
        return true;
    } else {
        return false;
    }
    
}

void BackTracking::set_goal(vector<int> arr){
    this->goal = arr;
}

void BackTracking::set_start(vector<int> arr){
    this->start = arr;
}

 void BackTracking::path(No *no,std::ofstream& myfile){
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



void BackTracking::init(std::ofstream& myfile){
    for(int i = 0; i < 100; i++)
    {
        myfile<< "-";
    }
    myfile << endl;
    myfile<< "Backtracking: "<< endl;


    int visited = 0;
    int expanded = 0;
    int cost = 0;
    int depth = 0;
    int level = 0;
    int leaf = 0;
    bool s = false;
    bool f = false;

    root = new No(tam);

    

    root->set_state(this->start);

    Actions *action = new Actions();
    int count = 0;
    No *aux = new No(this->tam);
    aux = root;
    aux->set_father(NULL);

    auto start = std::chrono::high_resolution_clock::now();
    while (s != true || f != true)
    {   
           

                    
            vector<int> aux_state = aux->get_state();
            No *aux2 = new No(this->tam);          
            bool check = action->exec(aux,1,aux_state);
            
            if(check == 1 && aux->get_son1() == NULL){
               
                aux2->set_state(aux_state);
                aux2->set_father(aux);
                aux->set_son1(aux2);
                aux = aux2;
                visited++;
                depth++;        
            }

            if(check == 0){
                
                check = action->exec(aux,2,aux_state);

                if(check == 1 && aux->get_son2() == NULL){
                   
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son2(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                }

            }


            if(check == 0){
              
                check = action->exec(aux,3,aux_state);
                
                if(check == 1 && aux->get_son3() == NULL){
                    
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son3(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                }

            }

            if(check == 0){
               
                check = action->exec(aux,4,aux_state);
                
                if(check == 1 && aux->get_son4() == NULL){
                     
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son4(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                }

            }  


            if(this->is_goal(aux->get_state())){
                myfile << "Sucesso" << endl;
                s = true;
                leaf++;
                break;
            }
           

            if(check == 0 && 
                aux->get_son1() == NULL  && 
                aux->get_son2() == NULL  && 
                aux->get_son3() == NULL  && 
                aux->get_son4() == NULL) 
            {
                aux = aux->get_father();
                depth--;
                leaf++;
            }else if(check == 0) {
                myfile << "Resultado => Fracasso" << endl;
                f = true;
                break;
            }

            
    }
    expanded = visited;
    float average = float((expanded - 1)) / (visited - leaf);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    myfile <<"Visitados: "<< visited << endl;
    myfile <<"Profundidade: "<< depth << endl;
    myfile <<"Expandidos: " << expanded << endl;
    myfile <<"Fato médio de ramificação: "<< average << endl; 
    myfile <<"Tempo da busca: "<<float_ms.count() << "s" <<endl;

    if(s == true){
        myfile << "Caminho" << endl;
        this->path(aux,myfile);
        myfile << "Custo do caminho: "<< cost << endl;
    }

    for(int i = 0; i < 100; i++)
    {
        myfile<< "-";
    }
    myfile << endl;
    
   
}