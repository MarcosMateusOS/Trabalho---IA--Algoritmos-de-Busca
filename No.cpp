#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm> 
#include <string>
#include "No.h"



using namespace std;


No::No(int x){
  
    size = 2 * x + 1;
    id = id;
    prof = prof;
    state.resize(size);

    father = NULL;
    son1 = NULL;
    son2 = NULL;
    son3 = NULL;
    son4 = NULL;

}

void No::set_state(vector<int> new_state){
    this->state = new_state;
}

vector<int>No::get_state(){
    return this->state;
}


bool No::is_unique(No *no, vector<int> arr){
    No *aux = no->get_father();
    cout <<"TESTANDO unicidade" << endl;
    bool check = true;
    for(auto itr : arr)
    {
        cout << itr << " ";
    }
    cout << endl;
    while (aux != NULL)
    {   
        //  cout <<"PAI"<<arr.size() << endl;
        // for(auto itr : arr)
        // {
        //     cout << itr << " ";
        // }
        // cout << endl;

        if(arr == aux->get_state())
        {   
            cout << "retornando falso" << endl;
            check = false;
            break;
        }else{
            // cout << "buscand pai" << endl;
            aux = aux->get_father();
        }

        
    }
    return check;
    

}