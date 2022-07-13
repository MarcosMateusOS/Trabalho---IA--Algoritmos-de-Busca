#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Backtracking.h"
#include "Actions.h"

using namespace std;

BackTracking::BackTracking(){
    root = NULL;
    
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

 void BackTracking::path(No *no){
     No *aux = no;
     vector<vector<int>> path_reverse;

     while (aux != NULL)
     {     
        path_reverse.push_back(aux->get_state());
        aux = aux->get_father();
     }

     std::reverse(path_reverse.begin(),path_reverse.end());

     for(int i = 0; i < path_reverse.size(); i++){
         cout<<"[";
          for (auto it = path_reverse[i].begin();
             it != path_reverse[i].end(); it++) {
            cout << *it << ',';
        }
         cout<<"] => ";
     }
     
 }



void BackTracking::init(int tam){
    cout<< "Entrou init backtracking: "<<tam<< endl;
    bool s = false;
    bool f = false;

    root = new No(tam);

    

    root->set_state(this->start);

    Actions *action = new Actions();
    int count = 0;
    No *aux = new No(tam);
    aux = root;
    aux->set_father(NULL);

    while (s != true || f != true)
    {   
           


            cout << "Buscando..." << endl;
            cout <<  "Antes" << endl;
             for(auto itr : aux->get_state())
            {
                cout << itr << " ";
            }
            cout << endl;
                    

            vector<int> aux_state = aux->get_state();
            No *aux2 = new No(aux->get_size());
            
            bool check = action->exec(aux,1,aux_state);
            
            if(check == 1 && aux->get_son1() == NULL){
                cout << "R1 => " << check << endl;
                aux2->set_state(aux_state);
                aux2->set_father(aux);
                aux->set_son1(aux2);
                aux = aux2;        
            }

            if(check == 0){
                cout << "TESTANDO R2" << check << endl;
                check = action->exec(aux,2,aux_state);

                if(check == 1 && aux->get_son2() == NULL){
                    cout << "R2 => " << check << endl;
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son2(aux2);
                    aux = aux2; 
                }

            }


            if(check == 0){
                cout << "TESTANDO R3" << check << endl;
                 check = action->exec(aux,3,aux_state);
                cout << check << endl;  
                cout << aux->get_son4() << endl;
                if(check == 1 && aux->get_son3() == NULL){
                    cout << "R3 => " << check << endl;
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son3(aux2);
                    aux = aux2; 
                }

            }

            if(check == 0){
                cout << "TESTANDO R4" << check << endl;
                check = action->exec(aux,4,aux_state);
                cout << check << endl;  
                cout << aux->get_son4() << endl;
                if(check == 1 && aux->get_son4() == NULL){
                     cout << "R4 => " << check << endl;
                    aux2->set_state(aux_state);
                    aux2->set_father(aux);
                    aux->set_son4(aux2);
                    aux = aux2; 
                }

            }  


           
            cout <<  "Depois" << endl;
             for(auto itr : aux->get_state())
            {
                cout << itr << " ";
            }
            cout << endl;


            if(this->is_goal(aux->get_state())){
                cout << "Sucesso" << endl;
                s = true;
                break;
            }
           

            if(check == 0 && 
                aux->get_son1() == NULL  && 
                aux->get_son2() == NULL  && 
                aux->get_son3() == NULL  && 
                aux->get_son4() == NULL) 
            {
                cout << "Backtracking"<< endl;
                aux = aux->get_father();
            }else if(check == 0) {
                cout << "Fracasso" << endl;
                f = true;
                break;;
            }

            
            //  if(count == 15){
            //      break;
            //  }
    
    }

    if(s == true){
        cout << "Imprimindo caminho" << endl;
        this->path(aux);
    }
    
   
}