/*077's notes:
input:
nodes of a tree
output:
nodes yg perlu diperkuat
using bst
fp2_shinji (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

struct bst {
    int value;
    bst *left, *right;
};

struct q {
    bst* node;
    q* next;
};

bst* newnode(int value) {
    bst* node = new bst;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bst* push(bst* node, int value) {
    if (node == nullptr) {
        return newnode(value);
    }
    if (value < node->value) {
        node->left = push(node->left, value);
    } else if (value > node->value) {
        node->right = push(node->right, value);
    }
    return node;
}

void enq(q** front, q** rear, bst* node) {
    q* temp = new q;
    temp->node = node;
    temp->next = nullptr;
    if (*rear == nullptr) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

bst* deq(q** front, q** rear) {
    if (*front == nullptr) {
        return nullptr;
    }
    q* temp = *front;
    *front = (*front)->next;
    if (*front == nullptr) {
        *rear = nullptr;
    }
    bst* node = temp->node;
    delete temp;
    return node;
}

bool empty(q* front) {
    return front == nullptr;
}

void gvf(bst* root) {
    if (root == nullptr) {
        return;
    }
    q* front = nullptr;
    q* rear = nullptr;
    enq(&front, &rear, root);
    while (!empty(front)) {
        int lvlsz = 0;
        q* temp = front;
        while (temp != nullptr) {
            lvlsz++;
            temp = temp->next;
        }
        int maxv = INT_MIN;
        for (int counter = 0; counter < lvlsz; counter += 1) {
            bst* current = deq(&front, &rear);
            maxv = (maxv > current->value) ? maxv : current->value;
            if (current->left) {
                enq(&front, &rear, current->left);
            }
            if (current->right) {
                enq(&front, &rear, current->right);
            }
        }
        if (maxv != INT_MIN) {
            cout << maxv << endl;
        }
    }
}

int main() {
    bst* root = nullptr;
    int n;
    while (cin >> n) {
        root = push(root, n);
    }
    gvf(root);
    cout << endl;
    return 0;
}
