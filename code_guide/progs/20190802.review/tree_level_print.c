#include "ds.h"

void level_print(treenode *root)
{
    if (!root)
        return;

    queue *q = queue_create();
    int cur_level = 1;
    int next_level = 0;
#define ENQUEUE(q, x) queue_enqueue(q, (long)(x))
#define DEQUEUE(q) ((treenode *)queue_dequeue(q))

    ENQUEUE(q, root);
    while (!queue_empty(q)) {
        root = DEQUEUE(q);
        if (root->left) {
            ENQUEUE(q, root->left);
            next_level++;
        }
        if (root->right) {
            ENQUEUE(q, root->right);
            next_level++;
        }
        printf("%-3ld", root->val);
        if (--cur_level == 0) {
            printf("\n");
            cur_level = next_level;
            next_level = 0;
        }
    }
    queue_release(&q);
}

int main(int argc, char *argv[])
{
    treenode *root = bst_create(5);
    tree_draw(root);
    level_print(root);
}
