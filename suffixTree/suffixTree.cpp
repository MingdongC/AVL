#include<cstdio>
#include<string>
#include<iostream>
#include "suffixTree.h"
#include<string.h>
#include <cstdlib>
using namespace std;

void CreateNode(SuffixTrie * & Node) {
    int i;
    Node = (SuffixTrie * ) malloc(sizeof(SuffixTrie));
    Node -> Start = Node -> End = Node -> Length = ERROR;
    for (i = 0; i < NUM; i++) Node -> Next[i] = NULL;
    Node -> Link = Node -> Father = NULL;
    Node -> Flag = LEAF;
}

void Initialize(SuffixTrie & h, char s[]) {
    int i;
    h.Start = h.End = ERROR;
    for (i = 0; i < NUM; i++) 
		h.Next[i] = NULL;
    h.Link = & h;
    h.Father = NULL;
    h.Flag = LEAF;
    h.Length = 0;
     
    len = strlen(s);
    s[len] = SPECIALCHAR;
    s[len + 1] = '\0';
    len++;
}

int FindV(char s[]) {
    int old;
    SuffixTrie * t, * newt;
    t = U -> Next[s[W[0]] - STARTCHAR];
     
    old = 0;
    while (W[2] > (t -> End) - (t -> Start) + 1 + old) {
        old += (t -> End - t -> Start + 1);
        t = t -> Next[s[W[0] + old] - STARTCHAR];
    }
    if (W[2] == (t -> End) - (t -> Start) + 1 + old) {
        V = t;
        P -> Link = V;
        return TYPE1;
    } else {
        CreateNode(newt);
        newt -> Start = t -> Start;
        newt -> End = t -> Start + W[2] - old - 1;
        newt -> Father = t -> Father;
        newt ->
               Length = newt -> Father -> Length + newt -> End - newt ->
               Start + 1;
        t -> Father -> Next[s[t -> Start] - STARTCHAR] = newt;
        t -> Start = newt -> End + 1;
        newt -> Next[s[t -> Start] - STARTCHAR] = t;
        t -> Father = newt;
        V = newt;
        P -> Link = V;
        return TYPE2;
    }
}

int Insert(SuffixTrie * Node, int start, char s[]) {
    int i, posbegin, posend;
    SuffixTrie * t;
    if (Node -> Next[s[start] - STARTCHAR] == NULL) {
        CreateNode(Node -> Next[s[start] - STARTCHAR]);
        Node -> Next[s[start] - STARTCHAR] -> Start = start;
        Node -> Next[s[start] - STARTCHAR] -> End = len - 1;
        Node -> Next[s[start] - STARTCHAR] -> Father = Node;
        Node -> Next[s[start] - STARTCHAR] ->
               Length = Node -> Length + len - start;
        Node -> Flag = NOTLEAF;
        P = Node;
        return TYPE1;
    } else {
        posbegin = Node -> Next[s[start] - STARTCHAR] -> Start;
        posend = Node -> Next[s[start] - STARTCHAR] -> End;
        for (i = posbegin; i <= posend; i++) {
            if (s[i] != s[start + i - posbegin]) break;
        }
        if (i == posend + 1) {
            return Insert(Node -> Next[s[start] - STARTCHAR], start + i - posbegin, s);
        } else {
            CreateNode(t);
            t -> Start = posbegin;
            t -> End = i - 1;
            t -> Flag = NOTLEAF;
            Node -> Next[s[start] - STARTCHAR] -> Start = i;
            t -> Next[s[i] - STARTCHAR] = Node -> Next[s[start] - STARTCHAR];
            t -> Next[s[i] - STARTCHAR] -> Father = t;
            Node -> Next[s[start] - STARTCHAR] = t;
            t -> Father = Node;
            t -> Length = Node -> Length + t -> End - t -> Start + 1;
            Insert(t, start + i - posbegin, s);
            G = Node;
            P = t;
            return TYPE2;
        }
    }
}

int Select(int start, char s[], int type) {
    int result1, result2, result;
    if (type == TYPE1) {
        U = P -> Link;
        result = Insert(U, start + U -> Length, s);
    } else {
        U = G -> Link;
        if (G -> Link == G) {
            W[0] = P -> Start + 1;
            W[1] = P -> End;
            W[2] = P -> End - P -> Start;
        } else {
            W[0] = P -> Start;
            W[1] = P -> End;
            W[2] = P -> End - P -> Start + 1;
        }
        if (W[2] == 0) {
            V = G;
            P -> Link = V;
            result = Insert(V, start, s);
        } else {
            result1 = FindV(s);
            result2 = Insert(V, start + V -> Length, s);
            if (result1 == TYPE2) {
                G = P -> Father;
                result = result1;
            } else result = result2;
        }
    }
    return result;
}

void BuildSuffixTrie(SuffixTrie & h, char s[]) {
    int i;
    int type;
     
    len = strlen(s);
    CreateNode(h.Next[s[0] - STARTCHAR]);
    h.Next[s[0] - STARTCHAR] -> Start = 0;
    h.Next[s[0] - STARTCHAR] -> End = len - 1;
    h.Next[s[0] - STARTCHAR] -> Father = & h;
    h.Next[s[0] - STARTCHAR] -> Length = h.Length + h.Next[s[0] - STARTCHAR] -> End - h.Next[s[0] - STARTCHAR] -> Start + 1;
    h.Flag = NOTLEAF;
    type = TYPE1;
    P = & h;
     
    for (i = 1; i < len; i++) type = Select(i, s, type);
}

void DelSuffTrie(SuffixTrie * & Node) {
    int i;
    for (i = 0; i < NUM; i++) {
        if (Node -> Next[i] != NULL) {
            DelSuffTrie(Node -> Next[i]);
            Node -> Next[i] = NULL;
        }
    }
    free(Node);
}

int FindStr(int start, char s[]) {
    int result;
    int i;
    int temp;
    SuffixTrie * x;
    x = P -> Next[s[start] - STARTCHAR];
    result = P -> Length;
    if (x == NULL) {
        P = P -> Link;
        return result;
    }
    temp = 0;
    for (i = start; i < len2; i++) {
        if (x -> Start + i - start - temp > x -> End) {
            temp = i - start;
            P = x;
            x = x -> Next[s[start + temp] - STARTCHAR];
            if (x == NULL) break;
        }
        if (s[i] != str[x -> Start + i - start - temp]) break;
        result++;
    }
    P = P -> Link;
    return result;
}

int Search(SuffixTrie & h, char s[]) {
    int result;
    int i;
    int temp;
    len2 = strlen(s);
    result = 0;
    P = & head;
    for (i = 0; i < len2; i++) {
        temp = FindStr(i + P -> Length, s);
        if (result < temp) result = temp;
        if (result >= len2 - i) break;
    }
    return result;
}

int main()
{
    int result,len,i,j,k;
    printf("后缀树法——样例\n");
    while (scanf("%s", str) != EOF) {
        Init(head, str);
        BuildSuffixTrie(head, str);
        len=strlen(str)-1;
        for(i=0;i<len;i++)
            buf[i]=str[len-1-i];
        buf[i]='\0';
        result = Search(head, buf);
        printf("最长回文子串：%d\n", result);
    }
    return 0;
}

