#include <vector>
#include "No.h"

#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
using namespace std;


class Actions
{

    public:
        Actions(){};
        int index_zero(vector<int> arr);
        bool exec(No *no,int r,vector<int> &arr);
        bool move_R1(No *no,vector<int> &arr);
        bool move_R2(No *no,vector<int> &arr);
        bool move_R3(No *no,vector<int> &arr);
        bool move_R4(No *no,vector<int> &arr);

};

#endif 