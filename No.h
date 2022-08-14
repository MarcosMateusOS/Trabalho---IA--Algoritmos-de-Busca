#include <vector>
#include <iostream>
#include <cstdlib>
#include <vector>

#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

using namespace std;

class No
{   

    private:
        int size;
        int id;
        int prof;
        int cost;
        int heuristic_cost;
        vector<int> state;
        No* father;
        No* son1;
        No* son2;
        No* son3;
        No* son4;


    public:
        No(int x);

        int get_size() {return size;}

        void set_cost(int co){cost = co;};
        int get_cost(){return cost;};

        void set_heuristic_cost(int co){heuristic_cost = co;};
        int get_heuristic_cost(){return heuristic_cost;};

        void set_state(vector<int> new_state);
        void set_father(No *no){father=no;};
         No* get_father(){return father;};

        void set_son1(No *no){son1 = no;};
        No* get_son1(){return son1;};

        void set_son2(No *no){son2 = no;};
         No* get_son2(){return son2;};

        void set_son3(No *no){son3 = no;};;
         No* get_son3(){return son3;};

        void set_son4(No *no){son4 = no;};;
        No* get_son4(){return son4;};

        vector<int> get_state();

        bool is_unique(No *no, vector<int> arr);

       
    
};

#endif