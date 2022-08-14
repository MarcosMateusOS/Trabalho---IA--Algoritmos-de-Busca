#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <queue>
#include "No.h"

using namespace std;

class BreadthFirstSearch
{

    private:
        No *root;
        int tam;
        vector<int> start;
        vector<int> goal;

    public:
        BreadthFirstSearch(int tam,vector<int> start,vector<int> final_state);
        void init(std::ofstream& myfile);
        bool is_goal(vector<int> arr);
        bool verify_closed(vector<int> arr,queue<No*> closed);
        void set_goal(vector<int> arr);
        void set_start(vector<int> arr);
        void path(No *no,std::ofstream& myfile);

};