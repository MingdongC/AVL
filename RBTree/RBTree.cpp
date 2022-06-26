//
// Created by 程良彬 on 12-15.
// 动图参考https://www.cnblogs.com/newobjectcc/p/11295652.html
// 代码参考https://www.cnblogs.com/cthon/p/9281677.html

#include <stdio.h>
#include <cstdlib>
#include <time.h>

#define RED 0
#define BLACK 1

int sale[30] = {3566, 2472, 1180, 2948, 2286, 4414, 1207, 2110, 1951, 4271,
                1690, 3574, 4297, 4232, 2609, 1367, 3893, 1693, 1997, 1589,
                3140, 2063, 2359, 3291, 2699, 4179, 2333, 3786, 1458, 3427};
int test[6] = {200,100, 300, 400, 500, 600};
// 红黑树节点
typedef struct RBTreeNode{
    unsigned char color;
    int key;
    int data = 0;
//    int day_sale;
    struct RBTreeNode *left;
    struct RBTreeNode *right;
    struct RBTreeNode *parent;
}Node, *node;

//红黑树根
typedef struct RBRootNode{
    Node *node;
}RBRoot;

int abs(int i){
    if(i > 0)
        return i;
    else
        return -i;
}

static void rbtree_left_rotate(RBRoot *root, Node *x);
static void rbtree_right_rotate(RBRoot *root, Node *y);
static void rbtree_insert(RBRoot *root, Node *node);
static void rbtree_insert_fixup(RBRoot *root, Node *node);
int rbtree_delete_key(RBRoot *root, int key, node *p);
void rbtree_delete(RBRoot *root, Node *node);
static void rbtree_delete_fixup(RBRoot *root, Node *node, Node *parent);
static int rbtree_search(RBRoot *root, int key, node *result);
static void printNode(Node *node);

/* 对红黑树的节点(x)进行左旋转
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     //1                             //
 *     x                               y
 *   /  \\2      --(左旋)-->         //  \
 *  lx    y                         x    ry
 *     //3  \                     / \\
 *    ly     ry                  lx   ly
 */
static void rbtree_left_rotate(RBRoot *root, Node *x){
    //由于节点中有指向parent的指针，所以root指的是整棵树的树根而不是“最小不平衡子树”的树根
    node y = x->right;
    // 3
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
    y->left = x;
    // 1
    y->parent = x->parent;
    if(x->parent == NULL){
        //x的父节点为空时，直接把y设置为根节点
        root->node = y;
    } else{
        //否则按照x在父节点左右位置来设置y
        if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    // 2
    y->left = x;
    x->parent = y;
}

/*
 * 对红黑树的节点(y)进行右旋转
 * 右旋示意图(对节点y进行右旋)：
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 */
static void rbtree_right_rotate(RBRoot *root, Node *y){
    Node *x = y->left;
    y->left = x->right;
    if(x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == NULL){
        root->node = x;
    }else{
        if(y->parent->left == y)
            y->parent->left = x;
        else
            y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

static int rbtree_search(RBRoot *root, int key, node *result){
    //在root为根的树中搜索键值为key的结点，把结点赋给result
    Node *x = root->node;
    while(x != NULL){
//        printNode(x);
        if(x->key == key){
            //查找成功，把x赋值给result, 返回1
            *result = x;
//            printf("\n");
            return 1;
        } else if(key > x->key){
            x = x->right;
        }else{
            x = x->left;
        }
    }
    *result = x;
//    printf("\n");
    //查找失败，返回0
    return 0;
}

static void rbtree_insert(RBRoot *root, Node *node){
    Node *y = NULL;//y指向x的前驱，方便插入结点
    Node *x = root->node;//x作为索引，找出插入的位置
    while(x != NULL){
        y = x;
        if(node->key > x->key)
            x = x->right;
        else
            x = x->left;
    }
    node->parent = y;
    if(y != NULL){//
        if(node->key < y->key)
            y ->left = node;
        else
            y->right = node;
    }else{
        root->node = node;
    }
    node->color = RED;
    //对插入后的红黑树进行修正
    rbtree_insert_fixup(root, node);
}

static void rbtree_insert_fixup(RBRoot *root, Node *node){
    Node *parent, *gparent;
//    parent = node->parent;
    while((parent = node->parent) && parent->color == RED){
        //只有在父节点为红色时，才需要进行修正
        gparent = parent->parent;
        if(parent == gparent->left){
            //父节点在祖父节点左子树
            Node *uncle = gparent->right;
            if(uncle != NULL && uncle->color == RED){
                //叔叔节点存在且为红色
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                //修正完当前节点后，需要以当前根节点继续向上修正
                node = gparent;
                continue;
            }
            if(node == parent->right){
                //LR型，转换为LL型再处理
                Node *tmp;
                rbtree_left_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

                //LL型
                rbtree_right_rotate(root, gparent);
                parent->color = BLACK;
                gparent->color = RED;

        }else{
            //父节点在祖父节点右侧
            Node *uncle = gparent ->left;
            if(uncle != NULL && uncle ->color == RED){
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                node = gparent;
                continue;
            }
            if(node == parent ->left){
                //RL型
                Node *tmp;
                rbtree_right_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

                //RR型
                rbtree_left_rotate(root, gparent);
                gparent->color = RED;
                parent->color = BLACK;

        }
    }
    root->node->color = BLACK;
}

int  rbtree_delete_key(RBRoot *root, int key, node *p){
    //使用键值删除结点
    int t = rbtree_search(root, key, p);
    if(t == 1) {
        rbtree_delete(root, *p);
//        删除成功，返回1
        return 1;
    }
    else
        //删除失败，返回0
        return 0;
}

void rbtree_delete(RBRoot *root, Node *node){
    Node *child, *parent;
    int color;

    if((node->left != NULL) && (node->right != NULL)){
        //被删除结点的左右孩子都不为空
        Node *front = node;
        //通过找到直接前驱结点，交换原本删除的位置，再进行删除（直接后继也行）
        front = front ->left;
        while(front ->right != NULL)
            //获取左子树的最大结点，即删除结点的前驱结点
            front = front ->right;


        if(node->parent){
            //node父节点不为空，则可交换结点
            if(node->parent ->left == node)
                node->parent->left = front;
            else
                node->parent->right = front;
        } else{
            //父节点为空，则node是根节点
            root->node = front;
        }

        //child结点指代的是前驱结点的孩子，只会有左孩子
        //需要删除的结点变成了删除该结点的后继结点，此后继结点只会有一个或零个子节点
        //   parent
        //      \
        //     front
        //       /
        //    child
        child = front->left;
        parent = front->parent;
        //color记录的是前驱结点的颜色
        color = front->color;

        if(parent == node){
            //前驱结点front就是node的子节点
            parent = front;
        }else{
            if(child)
            //child不为空，即后继结点有一个子节点，直接用child结点取代front的位置
                child->parent = parent;
            parent->right = child;
            //替换node原本的位置，更改左支
            front->left = node->left;
            node->left->parent = front;
        }
        front->parent = node->parent;
        front->color = node->color;
        //更改右支
        front->right = node->right;
        node->right->parent = front;

        if(color == BLACK)
            rbtree_delete_fixup(root, child, parent);
        free(node);

        return;
    }

    if(node->left != NULL)
        //删除结点只有一个子节点的情况,只可能为黑节点红孩子
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;

    if(child)
        child->parent = parent;

    if(parent){
        if(parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }else
        root->node = child;

    if(color == BLACK)
        rbtree_delete_fixup(root, child, parent);
    free(node);
}

static void rbtree_delete_fixup(RBRoot *root,Node *node,Node *parent){
    Node *brother;

    while((!node || node->color == BLACK) && node != root->node){
        if(parent->left == node){
            //node在左子树
            brother = parent->right;
            if(brother->color == RED){
                //case1:node的兄弟brother是红色的
                brother->color = BLACK;
                parent->color = RED;
                rbtree_left_rotate(root, parent);
                brother = parent->right;
                //处理完尚未平衡，只是进入了case 2,3,4
            }
            if((!brother->left || brother->left->color == BLACK) &&
                (!brother->right || brother->right->color == BLACK)){
                //case2:兄弟结点为黑色，且其两个孩子都是黑色
                brother->color = RED;
                //把parent变为node，继续向上迭代调整
                node = parent;
                parent = node->parent;
            }else{
                if(!brother->right || brother->right->color == BLACK){
                    //case3:兄弟结点为黑色，其左孩子为红，右孩子为黑
                    brother->left->color = BLACK;
                    brother->color = RED;
                    rbtree_right_rotate(root, brother);
                    brother = parent->right;
                    //处理完尚未平衡，只是进入了case4的情况
                }
                //case4:兄弟结点为黑，其右孩子是红色，左孩子任意颜色
                brother->color = parent->color;
                parent->color = BLACK;
                brother->right->color = BLACK;
                rbtree_left_rotate(root, parent);
                node = root->node;
                break;
            }
        } else{
            //node在右子树
            brother = parent->left;
            if(brother->color == RED){
                //case1 兄弟结点为红
                brother->color = BLACK;
                parent->color = RED;
                rbtree_right_rotate(root, parent);
                brother = parent->left;
            }
            if((!brother->left || brother->left->color == BLACK) &&
               (!brother->right || brother->right->color == BLACK)){
                //case2 兄弟结点为黑色，且其两个孩子也都是黑色
                brother->color = RED;
                node = parent;
                parent = node->parent;
            } else{
                if(!brother->left || brother->left->color == BLACK){
                    //case3 兄弟结点为黑，且左孩子为红，右孩子为黑
                    brother->right->color = BLACK;
                    brother->color = RED;
                    rbtree_left_rotate(root, brother);
                    brother = parent->left;
                }
                //case4 兄弟结点为黑，且右孩子为红，左孩子任意颜色
                brother->color = parent->color;
                parent->color = BLACK;
                brother->left->color = BLACK;
                rbtree_right_rotate(root, parent);
                node = root->node;
                break;
            }
        }
    }
    if(node)
        node->color = BLACK;
}

static void printNode(Node *node){
    //打印结点
    char *s;
    if(node != NULL) {
        if (node->color == BLACK)
            s = "BLACK";
        else
            s = "RED";
        printf("|%d:%d %s|", node->key, node->data, s);
    } else{
        printf("|NULL|");
    }
}

static void printTree(Node *node){
    //打印树
    printf(" root:");
    printNode(node);
    printf(" left:");
    printNode(node->left);
    printf(" right:");
    printNode(node->right);
    printf("\n");
    if(node->left != NULL)
        printTree(node->left);
    if(node->right != NULL)
        printTree(node->right);
}

int main(){

    //计算营业额最小波动值
//    node *result = (node*)malloc(sizeof(node));
//    Node *root = (Node*)malloc(sizeof(Node));
//    root->color = BLACK;
//    root->left = root->right = root->parent = NULL;
//    root->key = 0;
//    root->data = 3566;
//    RBRoot *Root = (RBRoot*)malloc(sizeof(RBRoot));
//    Root->node = root;
//    for(int i = 1; i < 30; i++){
//        Node *ti = (Node*)malloc(sizeof(Node));
//        ti->right = ti->left = ti->parent = NULL;
//        ti->key = i;
//        ti->data = sale[i];
//        rbtree_insert(Root, ti);
//    }
//    int tmp, r, sale_today, sale_other, min, count = 3566;
////    从第二个开始算，count赋第一个月的值
//    for(int i = 1; i < 30; i++){
//        r = rbtree_search(Root, i, result);
//        sale_today = (*result)->data;
//        min = 9999;
//        for(int j = 0; j < i; j++) {
//            r = rbtree_search(Root, j, result);
//            sale_other = (*result)->data;
//            tmp = abs(sale_today - sale_other);
//            if(tmp < min)
//                min = tmp;
//        }
//        count += min;
//    }
//    printf("min:%d", count);

    //计算200W次插入，查找，删除时间
    clock_t start, finish;
    double  duration1, duration2, duration3;
    node *p = (node*)malloc(sizeof(node));

    //创建根节点
    Node *root = (Node*)malloc(sizeof(Node));
    root->color = BLACK;
    root->left = root->right = root->parent = NULL;
    root->key = rand();
    root->data = 0;
    RBRoot *Root = (RBRoot*)malloc(sizeof(RBRoot));
    Root->node = root;

    start = clock();
    for(int i = 1; i < 2000000; i++){
        //随机生成2000000个数，插入红黑树中
        Node *ti = (Node*)malloc(sizeof(Node));
        ti->right = ti->left = ti->parent = NULL;
        ti->key = rand();
        ti->data = 0;
        //rand()只能生成0~32767，故允许可重复插入
        rbtree_insert(Root, ti);
    }
    finish = clock();
    duration1 = (double)(finish - start) / CLOCKS_PER_SEC;
    int successSearch, successDelete = 0;//记录成功删除次数

    start = clock();
    for(int i = 1; i < 2000000; i++){
        //随机生成2000000个数，从红黑树中删除
        successSearch += rbtree_search(Root, rand(), p);
    }
    finish = clock();
    duration2 = (double)(finish - start) / CLOCKS_PER_SEC;

    start = clock();
    for(int i = 1; i < 2000000; i++){
        //随机生成2000000个数，从红黑树中删除
        successDelete += rbtree_delete_key(Root, rand(), p);
    }
    finish = clock();
    duration3 = (double)(finish - start) / CLOCKS_PER_SEC;
//    printTree(Root->node);
    printf( "insert: %f seconds\n", duration1 );
    printf( "search: %f seconds\n", duration2 );
    printf( "delete: %f seconds\n", duration3 );
    printf( "%d\n", successDelete );
    return 0;
}