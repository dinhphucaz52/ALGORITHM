#include <iostream>

using namespace std;

struct node{
    node *a[26];
};

typedef struct node* trie;

trie root;

trie create(){
    trie p=new node;
    for(int i=0;i<=25;i++)
        p->a[i]=NULL;
    return p;
}

void ins(string s){
    trie p=root;
    for(char x:s){
        if (p->a[x-'a']==NULL)
            p->a[x-'a']=create();
        p=p->a[x-'a'];
    }
}

bool check(string s){
    trie p=root;
    for(char x:s){
        if (p->a[x-'a']==NULL)
            return false;
        p=p->a[x-'a'];
    }
    return true;
}

int main(){
    root=create();
    ins("helo");  ins("heelooo");
    cout<<check("hee");
    return 0;
}
