#include "sortDemo.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> arr = {1, 4, 2, 7, 5, 9, 10, 6, -53, -2}, temp = arr, ans = arr;
    sort(ans.begin(), ans.end());
    sortAlgo algo;

    algo.bubble(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.insertion(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.selection(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.shell(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.merge(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.quick(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.heaps(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.radix(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;

    algo.counting(temp);
    algo.OOOresult(temp);
    if(ans == temp) cout << "right!\n";
    else cout << "wrong!\n";
    temp = arr;
}