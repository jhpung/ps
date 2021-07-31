#include <iostream>
#define NUMBER 12
using namespace std;

int a[NUMBER] = {1,9,3,8,4,5,5,9,10,3,4,5};
int tree[4 * NUMBER];
/**
 * 0 1 2 3 4 5 6 7 8 9 10 11
 * 5 8 7 3 2 5 1 8 9 8 7  3
 * */
int init(int start, int end, int node) {
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end)return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}
int main(int argc, char** argv) {
    init(0, NUMBER - 1, 1);
    cout << "0부터 12까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
    update(0, NUMBER - 1, 1, 5, -5);
    cout << "0부터 12까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
    return 0;
}