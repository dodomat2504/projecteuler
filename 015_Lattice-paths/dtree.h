#ifndef DTREE_H
#define DTREE_H

#include <vector>

class DTreeNode {
private:
    std::vector<unsigned long long> _parentValues;

    unsigned long long _val;

    DTreeNode* _l, *_r;

    void appendParentValue(const unsigned long long val) { _parentValues.push_back(val); }
public:
    DTreeNode(const unsigned long long val = 0, DTreeNode* left = nullptr, DTreeNode* right = nullptr): _val(val), _l(left), _r(right) {}

    unsigned long long value() const { return _val; }
    DTreeNode* left() const { return _l; }
    DTreeNode* right() const { return _r; }

    void value(const unsigned long long val) { _val = val; }
    void left(DTreeNode* left) { _l = left; }
    void right(DTreeNode* right) { _r = right; }


    DTreeNode* createLeft() { _l = new DTreeNode(); return _l; }
    DTreeNode* createRight() { _r = new DTreeNode(); return _r; }

    void setValueFromParents() {
        _val = 0;
        for (int i = 0; i < _parentValues.size(); i++) _val += _parentValues[i];
    }

    void sendValueToChildren() {
        if (_l != nullptr) _l->appendParentValue(_val);
        if (_r != nullptr) _r->appendParentValue(_val);
    }

};

#endif // DTREE_H
