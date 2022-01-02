class RangeModule {
public:
    struct node {
        int low;
        int high;
        node* left = NULL;
        node* right = NULL;
        node* parent = NULL;
    };

    node* root = NULL;

    RangeModule() {
    }

    node* successor(node* v) {
        node* suc = NULL;
        if (v->right != NULL) {
            suc = v->right;
            while (suc->left != NULL) {
                suc = suc->left;
            }
        }
        else {
            if (v->parent == NULL) return NULL;
            suc = v;
            while (suc->parent != NULL && suc == suc->parent->right) {
                suc = suc->parent;
            }
        }
        return suc;
    }

    node* predecessor(node* v) {
        node* pre = NULL;
        if (v->left != NULL) {
            pre = v->left;
            while (pre->right != NULL) {
                pre = pre->right;
            }
        }
        else {
            if (v->parent == NULL) return NULL;
            pre = v;
            while (pre->parent != NULL && pre == pre->parent->left) {
                pre = pre->parent;
            }
        }
        return pre;
    }

    void deletion(node* v) {
        node* d;
        node* c;
        if (v->left == NULL || v->right == NULL) {
            d = v;
        }
        else {
            d = successor(v);
        }
        if (d->left == NULL) {
            c = d->left;
        }
        else {
            c = d->right;
        }
        if (c != NULL) {
            c->parent = d->parent;
        }
        if (d->parent == NULL) {
            root = c;
        }
        else if (d = d->parent->left) {
            d->parent->left = c;
        }
        else {
            d->parent->right = c;
        }
        if (d != v) {
            d->left = v->left;
            d->right = v->right;
            d->parent = v->parent;
        }

    }

    void merge(node* v, bool direction) { // direction = 0 -> left, direction = 1 -> right
        if (direction) { // right: find successor
            node* suc = successor(v);
            if (suc != NULL && suc->low <= v->high) {
                deletion(suc);
                if (suc->high > v->high) {
                    v->high = suc->high;
                    merge(v, true);
                }
                delete suc;
            }
        }
        else {  // left: find predecessor
            node* pre = predecessor(v);
            if (pre != NULL && pre->high >= v->low) {
                deletion(pre);
                if (pre->low < v->low) {
                    v->low = pre->low;
                    merge(v, false);
                }
                delete pre;
            }
        }
    }

    void addRange(int left, int right) {
        if (left == right) return;
        if (root == NULL) {
            root = new node;
            root->low = left;
            root->high = right;
            // std::cout << "new root: " << root->low << " - " << root->high << std::endl;
        }
        else {
            node* parent = NULL;
            node* pointer = root;
            while (pointer != NULL) {
                if (right < pointer->low) {
                    parent = pointer;
                    pointer = pointer->left;
                    continue;
                }
                else if (left > pointer->high) {
                    parent = pointer;
                    pointer = pointer->right;
                    continue;
                }
                else {
                    break;
                }
            }
            if (pointer != NULL) {
                if (right > pointer->high) {
                    pointer->high = right;
                    merge(pointer, true);
                }
                if (left < pointer->low) {
                    pointer->low = left;
                    merge(pointer, false);
                }
                // std::cout << "new pointer: " << pointer->low << " - " << pointer->high << std::endl;
            }
            else {
                node* NewNode = new node;
                NewNode->low = left;
                NewNode->high = right;
                NewNode->parent = parent;
                if (right < parent->low) parent->left = NewNode;
                else if (left > parent->high) parent->right = NewNode;
                // std::cout << "new node: " << NewNode->low << " - " << NewNode->high << std::endl;
            }
        }
    }

    bool queryRange(int left, int right) {
        if (root == NULL) return false;
        node* parent = NULL;
        node* pointer = root;
        while (pointer != NULL) {
            if (right < pointer->low) {
                parent = pointer;
                pointer = pointer->left;
                continue;
            }
            else if (left > pointer->high) {
                parent = pointer;
                pointer = pointer->right;
                continue;
            }
            else {
                break;
            }
        }
        if (pointer == NULL) return false;
        if (pointer->low <= left && pointer->high >= right) return true;
        return false;
    }

    void removeRange(int left, int right) {
        if (root == NULL || left == right) return;
        node* parent = NULL;
        node* pointer = root;
        while (pointer != NULL) {
            if (right < pointer->low) {
                parent = pointer;
                pointer = pointer->left;
                continue;
            }
            else if (left > pointer->high) {
                parent = pointer;
                pointer = pointer->right;
                continue;
            }
            else {
                break;
            }
        }
        if (pointer == NULL) return;
        if (right >= pointer->high && left <= pointer->low) {
            removeRange(pointer->high, right);
            removeRange(left, pointer->low);
        }
        else if (right < pointer->high && left <= pointer->low) {
            pointer->low = right;
            removeRange(left, pointer->low);
        }
        else if (right >= pointer->high && left > pointer->low) {
            pointer->high = left;
            removeRange(pointer->high, right);
        }
        else if (right < pointer->high && left > pointer->low) {
            deletion(pointer);
            addRange(pointer->low, left);
            addRange(right, pointer->high);
            delete pointer;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
