#include <iostream>
#include <memory.h>
using namespace std;

int N, M, K;
int *nums;
int a, b, c;
int *tree;

int init(int start, int end, int node) {
    if(start == end) return tree[node] = nums[start];
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
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}


int main(int argc, char** argv) {
    cin >> N >> M >> K;
    cout << N << M << K;
    nums = (int*)malloc(sizeof(int) * N);
    tree = (int*)malloc(sizeof(int) * N * 4);
    memset(tree, 0, sizeof(int) * N * 4);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    init(0, N - 1, 1);
    for(int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i < N * 4; i++) {
        cout << tree[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        switch(a) {
            case 1:
                update(0, N - 1, 1, b, c - nums[b]);
                for(int i = 1; i < N * 4; i++) {
                    cout << tree[i] << ' ';
                }
                cout << endl;
            break;
            case 2:
                cout << sum(0, N - 1, 1, b, c) << endl;
            break;
        }
    }
}