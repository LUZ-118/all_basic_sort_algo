#ifndef SORTDEMO_H
#define SORTDEMO_H

#include <bits/stdc++.h>
using namespace std;

class sortAlgo 
{
    public:
        int glo_val = 78763;
        sortAlgo() : val(333) {cout << "Build a sorting Algo tool.\n";}
        void print_this() {cout << this->glo_val << endl;}
        // simple
        void bubble(vector<int>&);
        void insertion(vector<int>&);
        void selection(vector<int>&);
        void shell(vector<int>&);
        
        // Advance
        void merge(vector<int>&);
        void sub_merge(vector<int>&, int, int);
        void quick(vector<int>&);
        void sub_quick(vector<int>&, int, int);
        void heaps(vector<int>&);
        void max_heapify(vector<int>&, int, int);

        // special
        void radix(vector<int>&);
        void sub_radix(vector<int>&, int);
        int getDigit(int, int);
        void counting(vector<int>&);

        //output result
        void OOOresult(vector<int>&);
    private:
        int val = 100;
};

#endif