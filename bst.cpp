#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node * left = NULL;
    Node * right = NULL;
};

typedef struct Node * node;

node root = NULL;

node create(int num)
{
    node p = new Node();
    p->val = num;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void ins(int num, node & p = root)
{
    if (p == NULL)
        return p = create(num), void();
    if (num > p->val)
        ins(num, p->right);
    else if (num < p->val)
        ins(num, p->left);
}

void giai_phong(node & p)
{
    if (p == NULL)
        return;
    giai_phong(p->left);
    giai_phong(p->right);
    p = NULL;
}


node find_node(int target, node & p = root)
{
    if (p == NULL || p->val == target)
        return p;    
    if (target < p->val)
        return find_node(target, p->left);
    return find_node(target, p->right);
}

node LMC;

void left_most_child(node & p)
{
    if (p->left == NULL)
        return LMC = p, void();
    left_most_child(p->left);
}

void del(node & p)
{   
    if (p->left == NULL && p->right == NULL)
    {
        giai_phong(p);
        return;
    }
    if (p->left == NULL)
    {
        p = p->right;
        giai_phong(p->right);
    }
    else if (p->right == NULL)
    {
        p = p->left;
        giai_phong(p->left);
    }
    else
    {
        left_most_child(p->right);
        node tmp = LMC;
        p->val = tmp->val;
        del(LMC);
    } 
}

bool find(int target)
{
    node p = find_node(target);
    return p != NULL;
}

void del(int target)
{
    node p = find_node(target);
    if (p == NULL)
        return;
    del(p);
}


void post_order(node & p = root){
    if(p != NULL)
    {
        cout << p->val << " ";
        post_order(p->left);
        post_order(p->right);
    }
}

vector<int> a = {15, 10, 20, 8, 12, 16, 25};

int main()
{
    for(int x : a)
        ins(x);
        
    node p = root;
    cout << p << '\n';
    cout << &root;

    return 0;
}