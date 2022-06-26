//
// Created by Lenovo on 2020/12/17.
//

#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H

#endif //UNTITLED_MAIN_H

//结点定义
struct SBTNode
{
    int value;
    SBTNode *lchild;
    SBTNode *rchild;
    int size;
};

void LeftRotate(SBTNode* &T);
void RightRotate(SBTNode* &T);
SBTNode* InsertSBT(SBTNode* T, int value);
int getNodeSize(SBTNode* T);
void DeleteSBT(SBTNode* &T,int x);
SBTNode* get_next(SBTNode* T,int value);
SBTNode* FindMax(SBTNode* T);
SBTNode* FindMin(SBTNode* T);
SBTNode* FindPreNode(SBTNode* T, int x);
SBTNode* SearchSBT(SBTNode* T, int value);
void Maintain(SBTNode* &T);
SBTNode* CreateTree(int arr[], int NodesNum);
