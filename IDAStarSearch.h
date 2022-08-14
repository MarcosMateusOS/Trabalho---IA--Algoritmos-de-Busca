#include <vector>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "No.h"

using namespace std;

class IDAStarSearch
{

    private:
        No *root;
        int tam;
        vector<int> start;
        vector<int> goal;

    public:
        IDAStarSearch(int tam,vector<int> start,vector<int> final_state);
        void init(std::ofstream& myfile);
        bool is_goal(vector<int> arr);
        bool verify_closed(vector<int> arr,vector<No*> closed);
        void set_goal(vector<int> arr);
        void set_start(vector<int> arr);
        void path(No *no,std::ofstream& myfile);
        int get_lower_cost(int lowe,vector<No*> openers);
        int heuristic(vector<int> arr);

};