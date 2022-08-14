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
#include "IDAStarSearch.h"
#include "Actions.h"

using namespace std;
using namespace std::chrono;

IDAStarSearch::IDAStarSearch(int tam,vector<int> start,vector<int> final_state){
    this->root = NULL;
    this->start = start;
    this->goal = final_state;
    
}
bool IDAStarSearch::is_goal(vector<int> arr){

    if(arr == this->goal){
        return true;
    } else {
        return false;
    }
    
}

int IDAStarSearch::heuristic(vector<int> arr){


    int count = 0;
    vector<int> aux = this->goal;
     
    for (auto it = arr.begin(), it2 = aux.begin();
            it != arr.end() && it2 != aux.end(); it++, it2++) {
            
            
                
            if(*it != *it2)
            {
                count++;
            }
            
            
    }
   
    return count;
}

bool IDAStarSearch::verify_closed(vector<int> arr, vector<No*> closed){
    

    
    for (int i = 0; i < closed.size(); i++)
    {      
        

       if(arr == closed[i]->get_state()){
        return true;
        } else {
            return false;
        }
    }

    return false;
    
}

int IDAStarSearch::get_lower_cost(int lower, vector<No*> openers){
              

    for(int i = 0; i < openers.size(); i++)
    {

        if(openers[i]->get_cost() + openers[i]->get_heuristic_cost() < lower || lower == -1){
        
            return openers[i]->get_cost();
        }

    }

    return -1;

}

void IDAStarSearch::set_goal(vector<int> arr){
    this->goal = arr;
}

void IDAStarSearch::set_start(vector<int> arr){
    this->start = arr;
}

 void IDAStarSearch::path(No *no,std::ofstream& myfile){
     No *aux = no;
     int cost = 0;
     vector<vector<int>> path_reverse;

     while (aux != NULL)
     {     
        path_reverse.push_back(aux->get_state());
        cost = cost + aux->get_cost() + aux->get_heuristic_cost();
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
     

      myfile << "Custo: "<< cost << endl;
 }



void IDAStarSearch::init(std::ofstream& myfile){

    for(int i = 0; i < 100; i++)
    {
        myfile<< "-";
    }
    myfile << endl;
    myfile<< "Busca com IDA: "<< endl;

    int level = 0;
    int expanded = 0;
    int old_level = -1;
    int discarded = -1;
    int visited = 0;
    int cost = 0;
    int depth = 0;
    int leaf = 0;

    bool s = false;
    bool f = false;

    root = new No(tam);
    root->set_state(this->start);

    Actions *action = new Actions();
   

    int lower_cost =  -1;

    No *aux = new No(tam);
    aux = root;
    aux->set_father(NULL);
    aux->set_cost(0);
    aux->set_heuristic_cost(this->heuristic(aux->get_state()));
    
    level = aux->get_cost() + aux->get_heuristic_cost();
    
    No *memory = new No(tam);
    memory = aux;
    
    int count = 0;

    auto start = std::chrono::high_resolution_clock::now();
    while (s != true || f != true)
    {       
        
    


        if(level == old_level || level == 0){ 
            f = true;
            myfile << "Resultado => Fracasso" << endl;
            break;
        }else {

              if(this->is_goal(aux->get_state())){
                    myfile << "Sucesso" << endl;
                    s = true;
                    break;
              }

            

            int sum = aux->get_cost() + aux->get_heuristic_cost();
            
            
            if(sum > level){

                if(discarded == -1){
                    discarded = sum;
                }else if(discarded > sum){           
                    discarded = sum;
                }

                aux = aux->get_father();

            }

            vector<int> aux_state = aux->get_state();
            No *aux2 = new No(this->tam);   
            bool check = action->exec(aux,1,aux_state);
            int heuric_cost = 0;
            
            if(check == 1 && aux->get_son1() == NULL){    
               
                heuric_cost = this->heuristic(aux_state);

                aux2->set_heuristic_cost(heuric_cost);
                aux2->set_cost(aux->get_cost() + 1);
                aux2->set_state(aux_state);
                aux2->set_father(aux);
                aux->set_son1(aux2);
                aux = aux2;
                visited++;
                depth++;
                expanded++;        
            }

            if(check == 0){
                
                check = action->exec(aux,2,aux_state);

                if(check == 1 && aux->get_son2() == NULL){

                    heuric_cost= this->heuristic(aux_state);
                    aux2->set_heuristic_cost(heuric_cost);
                    aux2->set_cost(aux->get_cost() + 2);
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son2(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                    expanded++; 
                }

            }
            if(check == 0){
              
                check = action->exec(aux,3,aux_state);        
                if(check == 1 && aux->get_son3() == NULL){
                    
                    heuric_cost = this->heuristic(aux_state);
                    aux2->set_heuristic_cost(heuric_cost);
                    aux2->set_cost(aux->get_cost() + 3);
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son3(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                    expanded++; 
                }

            }

            if(check == 0){
               
                check = action->exec(aux,4,aux_state);
                
                if(check == 1 && aux->get_son4() == NULL){
                     
                    heuric_cost = this->heuristic(aux_state);
                    aux2->set_heuristic_cost(heuric_cost);
                    aux2->set_cost(aux->get_cost() + 4);
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son4(aux2);
                    aux = aux2;
                    visited++;
                    depth++; 
                    expanded++; 
                }

            }  

            if(check == 0){
                
                if(aux->get_state() == memory->get_state()){
                    No *test = new No(tam);
                    test->set_state(memory->get_state());
                    test->set_cost(memory->get_cost());
                    test->set_heuristic_cost(memory->get_heuristic_cost());

                    
                    old_level = level;
                    level = discarded;
                    discarded = -1;
                    aux = test;
                    
                    if(old_level != level and level == 0){
                        depth = 0;
                        visited = 0;
                        leaf = 0;
                    }
                }else{
                    depth = -1;
                    if(
                        aux->get_son1() == NULL  && 
                        aux->get_son2() == NULL  && 
                        aux->get_son3() == NULL  && 
                        aux->get_son4() == NULL
                        ) 
                    {
                        depth++;
                    }
                     aux = aux->get_father();
                }
                
            }   
 
        }

    }
    auto end = std::chrono::high_resolution_clock::now();
    float average = float((expanded - 1)) / visited - leaf;
    std::chrono::duration<double, std::milli> float_ms = end - start;
    myfile <<"Visitados: "<< visited << endl;
    myfile <<"Profundidade: "<< depth << endl;
    myfile <<"Tempo da Busca: "<<float_ms.count() << "s" <<endl;
    myfile <<"Fato médio de ramificação: "<< average << endl; 
    myfile << "Patamar máximo: " << level <<endl; 
    myfile << "Imprimindo caminho" << endl;
    this->path(aux,myfile);
    
}

