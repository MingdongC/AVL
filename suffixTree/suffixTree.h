//
// Created by Lenovo on 2021/1/7.
//

#ifndef SUFFIXTREE_SUFFIXTREE_H
#define SUFFIXTREE_SUFFIXTREE_H


#define NUM                 27
#define STARTCHAR          'a'
#define SPECIALCHAR         '{'
#define ERROR               -1
#define TYPE1               1
#define TYPE2               2
#define LEAF                1
#define NOTLEAF             2

struct SuffixTrie {
    int Start, End;
    SuffixTrie * Next[NUM];
    SuffixTrie * Link;
    SuffixTrie * Father;
    int Flag;
    int Length;
};

char str[100010], buf[100010];
SuffixTrie head;
SuffixTrie*P, *G, *U, *V, *q;
int W[3], len, len2;

void CreateNode(SuffixTrie * & Node);
void Initialize(SuffixTrie & h, char s[]);
int FindV(char s[]);
int Insert(SuffixTrie * Node, int start, char s[]);
int Select(int start, char s[], int type);
void BuildSuffixTrie(SuffixTrie & h, char s[]);
void DelSuffTrie(SuffixTrie * & Node);
int FindStr(int start, char s[]);
int Search(SuffixTrie & h, char s[]);
int getMaxlenHWZC(SuffixTrie head, char str[]);

#endif