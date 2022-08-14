
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <algorithm> 
#include <string>
#include "Actions.h"


using namespace std;

int Actions::index_zero(vector<int> arr)
{

   auto it = find(arr.begin(), arr.end(), 0);
    

    if (it != arr.end()) 
    {
      
        int index = it - arr.begin();
        return index;
    }
    else {
        return -1;
    }
  
  
}

bool Actions::move_R1(No *no, vector<int> &arr){


  
    int index_zero = this->index_zero(arr);


  
    if(index_zero != -1){
         
         if(index_zero - 1  >= 0 && arr[index_zero-1] != 0 ){
     
            std::swap(arr[index_zero], arr[index_zero-1]);
            if(no->is_unique(no,arr) && (no->get_son1() == NULL ||  no->get_son1()->get_state() != arr))
            {
               
                return true;
            }else{
                 std::swap(arr[index_zero-1], arr[index_zero]);
                 return false;
            }
            
        }
       
        return false;
    }

    
    return false;
    
};
bool Actions::move_R2(No *no, vector<int> &arr){

     int index_zero = this->index_zero(arr);
  
    if(index_zero != -1){
         
         if(index_zero - 2  >= 0 && arr[index_zero-2] != 0){
              std::swap(arr[index_zero], arr[index_zero-2]);

            if(no->is_unique(no,arr) && (no->get_son2() == NULL ||  no->get_son2()->get_state() != arr))
            {
               
                return true;
            }else{
                 std::swap(arr[index_zero-2], arr[index_zero]);
                 return false;
            }
        }
         
         return false;
    }

    return false;
    
};
bool Actions::move_R3(No *no,vector<int> &arr){
    int index_zero = this->index_zero(arr);
  
    if(index_zero != -1){
         
         if(index_zero + 1  <= arr.size() && arr[index_zero+1] != 0){
            std::swap(arr[index_zero], arr[index_zero+1]);
            
            if(no->is_unique(no,arr)  && (no->get_son3() == NULL || no->get_son3()->get_state() != arr))
            {   
               
                return true;
            }else{
                 std::swap(arr[index_zero+1], arr[index_zero]);
                 return false;
            }

        }
         
         return false;
    }


     return false;
    
};
bool Actions::move_R4(No *no,vector<int> &arr){
    int index_zero = this->index_zero(arr);
  
    if(index_zero != -1){
        
         if(index_zero + 2  <= arr.size() && arr[index_zero+2] != 0){
            
            std::swap(arr[index_zero], arr[index_zero+2]);
            
            if(no->is_unique(no,arr) && (no->get_son4() == NULL || no->get_son4()->get_state() != arr))
            {
                return true;
            }else{
                 std::swap(arr[index_zero+2], arr[index_zero]);
                 return false;
            }

        }
         
         return false;
    }
    
    return false;
};

bool Actions::exec(No *no,int r,vector<int> &arr){

    if(r == 1){
        return this->move_R1(no,arr);
     }else if(r == 2){
        return this->move_R2(no,arr);
     }else if(r == 3){
        return this->move_R3(no,arr);
    }else if(r == 4){
        return this->move_R4(no,arr);
    }else{
        cout << "Sem solução" << endl;
        return false;
    }        

}