#ifndef PASCALSCHERDIAMANT_H
#define PASCALSCHERDIAMANT_H

#include "dtree.h"
#include <cmath>

class PascalscherDiamant {
private:
    const int _n;

    std::vector<DTreeNode*> nodes;

    int summeVon1BisN(const int N) const {
        int sum = 0;
        for (int i = 1; i <= N; i++) sum += i;
        return sum;
    }

    int reiheDesIndex(const int index) const {
        int r = 1;
        while (r <= 2*_n) {
            if (summeVon1BisN(r) <= index) r++;
            else break;
        }
        return r;
    }

    DTreeNode* LastNode() const {
        int i = -1;
        for (i = nodes.size()-1; i >= 0; i--) {
            if (nodes[i] != nullptr) break;
        }
        return nodes[i];
    }

public:
    PascalscherDiamant(const int n): _n(n) {
        nodes.push_back(new DTreeNode(1));

        for (int i = 1; i <= 2*_n; i++) {
            const int i_n_diff = i-_n;
            const int inDiffNurPositiv = i_n_diff > 0 ? i_n_diff : 0;

            for (int j = 0; j < i_n_diff; j++) nodes.push_back(nullptr);

            for (int j = 0; j < i+1-inDiffNurPositiv*2; j++) nodes.push_back(new DTreeNode());

            for (int j = 0; j < i_n_diff; j++) nodes.push_back(nullptr);
        }

        // link dem
        for (int i = 0; i < nodes.size() - (2*_n+1); i++) {
            int parent = i;
            int lchild = parent + reiheDesIndex(parent);
            int rchild = lchild + 1;
            if (nodes[parent] != nullptr) {
                DTreeNode* parentNode = nodes[parent];
                if (lchild < nodes.size()) {
                    if (nodes[lchild] != nullptr) {
                        DTreeNode* lchildNode = nodes[lchild];
                        parentNode->left(lchildNode);
                    }
                }
                if (rchild < nodes.size()) {
                    if (nodes[rchild] != nullptr) {
                        DTreeNode* rchildNode = nodes[rchild];
                        parentNode->right(rchildNode);
                    }
                }
            }
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == nullptr) continue;
            DTreeNode* parent = nodes[i];
            if (i != 0) parent->setValueFromParents();
            if (i < nodes.size() - (2*_n+1)) parent->sendValueToChildren();
        }

    }

    ~PascalscherDiamant() {
        for (DTreeNode* ptr : nodes) if (ptr != nullptr) delete ptr;
    }

    unsigned long long Ergebnis() const { return LastNode()->value(); }

};

#endif // PASCALSCHERDIAMANT_H
