#include "sortDemo.h"

void sortAlgo::bubble(vector<int> &arr) {
    for(int i = 1; i < arr.size(); i++) {
        bool flag = false;
        for(int j = 0; j < arr.size() - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
};

void sortAlgo::insertion(vector<int> &arr) {
    for(int i = 1; i < arr.size(); i++) {
        int temp = arr[i], j;
        for(j = i; j >= 1 && temp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
};

void sortAlgo::selection(vector<int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int temp = i;
        for(int j = i + 1; j < arr.size(); j++) {
            temp = arr[j] < arr[temp] ? j : temp;
        }
        swap(arr[i], arr[temp]);
    }
};

void sortAlgo::shell(vector<int> &arr) {
    int gap = arr.size() / 2;
    while(gap != 0) {
        for(int i = gap; i < arr.size(); i++) {
            int temp = arr[i], j;
            for(j = i; j >= gap && temp < arr[j - gap]; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void sortAlgo::merge(vector<int> &arr) {
    sub_merge(arr, 0, arr.size() - 1);
};

void sortAlgo::sub_merge(vector<int> &arr, int LB, int RB) {
    if(LB >= RB) return;
    int mid = (RB - LB) / 2 + LB;
    sub_merge(arr, LB, mid);
    sub_merge(arr, mid + 1, RB);
    int L = LB, R = mid + 1, k = 0;
    vector<int> sub_arr(RB - LB + 1, 0);
    while(L <= mid && R <= RB)
        sub_arr[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
    while(L <= mid)
        sub_arr[k++] = arr[L++];
    while(R <= RB)
        sub_arr[k++] = arr[R++];
    for(int i = LB; i <= RB; i++) 
        arr[i] = sub_arr[i - LB];
}

void sortAlgo::quick(vector<int> &arr) {
    sub_quick(arr,0, arr.size());
};

void sortAlgo::sub_quick(vector<int> &arr, int LB, int RB) {
    if(LB >= RB) return;
    int pivot = LB, L = pivot, R = RB + 1;
    swap(arr[pivot], arr[LB + rand() % (RB - LB + 1)]);
    while(1) {
        while(L <= RB && arr[++L] < arr[pivot]);
        while(R >= LB && arr[--R] > arr[pivot]);
        if(L >= R) break;
        swap(arr[L], arr[R]);
    }
    swap(arr[pivot], arr[R]);
    sub_quick(arr, LB, R - 1);
    sub_quick(arr, R + 1, RB);
}

void sortAlgo::heaps(vector<int> &arr) {
    int len = arr.size() - 1;
    for(int i = (len - 1) >> 1; i >= 0; i--)
        max_heapify(arr, i, len + 1);
    for(int i = len; i >= 1; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
};

void sortAlgo::max_heapify(vector<int> &arr, int k, int boundary) {
    while(k < boundary) {
        int max_idx = k, L = (k << 1) + 1, R = (k << 1) + 2;
        max_idx = L < boundary && arr[L] > arr[max_idx] ? L : max_idx;
        max_idx = R < boundary && arr[R] > arr[max_idx] ? R : max_idx;
        if(max_idx == k) break;
        swap(arr[k], arr[max_idx]);
        k = max_idx;
    }
}

void sortAlgo::radix(vector<int> &arr) {
    int factor = 1, max_v = INT_MIN, min_v = INT_MAX;
    for(int &i : arr)
        min_v = i < min_v ? i : min_v;
    for(int &i : arr) {
        i -= min_v;
        max_v = i > max_v ? i : max_v;
    }
    while(max_v / factor) {
        sub_radix(arr, factor);
        factor *= 10;
    }
    for(int &i : arr)
        i += min_v;
};

void sortAlgo::sub_radix(vector<int> &arr, int factor) {
    int freqSize = 10, len = arr.size();
    vector<int> freq(freqSize, 0), sorted(len, 0);
    for(int i = 0; i < len; i++)
        freq[getDigit(arr[i], factor)]++;
    for(int i = 1; i < freqSize; i++)
        freq[i] += freq[i - 1];
    for(int i = len - 1; i >= 0; i--)
        sorted[freq[getDigit(arr[i], factor)]-- - 1] = arr[i];
    arr= sorted;
}

int sortAlgo::getDigit(int number, int factor) {
    return abs(number) / abs(factor) % 10;
}

void sortAlgo::counting(vector<int> &arr) {
    int max_v = INT_MIN, min_v = INT_MAX;
    for(int &i : arr) {
        min_v = i < min_v ? i : min_v;
        max_v = i > max_v ? i : max_v;
    }
    int freqSize = max_v - min_v + 2, len = arr.size();
    vector<int> freq(freqSize, 0), sorted(len, 0);
    for(int i = 0; i < len; i++)
        freq[arr[i] - min_v]++;
    for(int i = 1; i < freqSize; i++)
        freq[i] += freq[i - 1];
    for(int i = len - 1; i >= 0; i--) 
        sorted[freq[arr[i] - min_v]-- - 1] = arr[i];
    arr = sorted;
};

void sortAlgo::OOOresult(vector<int> &arr) {
    for(int &item : arr) {
        cout << item << ", ";
    }
    cout<<endl;
};