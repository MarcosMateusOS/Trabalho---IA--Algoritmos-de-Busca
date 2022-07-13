#include <vector>
#include <iostream>
#include <cstdlib>
#include "No.h"

using namespace std;


class BackTracking{


    private:
        No *root;
        vector<int> start;
        vector<int> goal;

    public:
        BackTracking();
        void init(int tam);
        bool is_goal(vector<int> arr);
        void set_goal(vector<int> arr);
        void set_start(vector<int> arr);
        void path(No *no);
};