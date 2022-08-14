#include <vector>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <fstream>
#include "No.h"

using namespace std;

class DepthFirstSearch
{

    private:
        No *root;
        int tam;
        vector<int> start;
        vector<int> goal;

    public:
        DepthFirstSearch(int tam,vector<int> start,vector<int> final_state);
        void init(std::ofstream& myfile);
        bool is_goal(vector<int> arr);
        bool verify_closed(vector<int> arr,stack<No*> emptys);
        void set_goal(vector<int> arr);
        void set_start(vector<int> arr);
        void path(No *no,std::ofstream& myfile);

};