#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "No.h"

using namespace std;


class BackTracking{


    private:
        No *root;
        int tam;
        vector<int> start;
        vector<int> goal;

    public:
        BackTracking(int tam,vector<int> start,vector<int> final_state);
        void init(std::ofstream& myfile);
        bool is_goal(vector<int> arr);
        void set_goal(vector<int> arr);
        void set_start(vector<int> arr);
        void path(No *no,std::ofstream& myfile);
};