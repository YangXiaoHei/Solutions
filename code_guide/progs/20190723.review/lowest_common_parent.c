#include "ds.h"

treenode *lowest_common_parent(treenode *root, treenode *n1, treenode *n2)
{
    if (!root || root == n1 || root == n2)
        return root;

    treenode *l = lowest_common_parent(root->left, n1, n2);
    treenode *r = lowest_common_parent(root->right, n1, n2);
    if (l && r)
        return root;
    return l ? l : r;
}

treenode *get_kth_node(treenode *root, int k)
{
    treenode *cur1 = root, *cur2 = NULL;
    treenode *target = NULL;
    while (cur1) {
        cur2 = cur1->left;
        if (cur2) {
            while (cur2->right && cur2->right != cur1)
                cur2 = cur2->right;

            if (!cur2->right) {
                cur2->right = cur1;
                cur1 = cur1->left;
                continue;
            }
            cur2->right = NULL;
        }
        if (k-- <= 0 && !target)
            target = cur1;
        cur1 = cur1->right;
    }
    return target;
}

void gen_two_treenode(treenode *root, int size, treenode **n1, treenode **n2)
{
    int k = randWithRange(0, size);
    int m = randWithRange(0, size);
    *n1 = get_kth_node(root, k);
    *n2 = get_kth_node(root, m);
}

int main(int argc, char *argv[])
{
    treenode *root = bst_create(5);
    tree_draw(root);
    treenode *n1 = NULL, *n2 = NULL;
    gen_two_treenode(root, 5, &n1, &n2);
    printf("n1 = %ld, n2 = %ld\n", n1->val, n2->val);
    treenode *common = lowest_common_parent(root, n1, n2);
    if (common)
        printf("common %ld\n", common->val);
    else
        printf("common not exist!\n");
}
