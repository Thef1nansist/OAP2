#include<iostream>
using namespace std;
enum color { red, black };
struct node
{
	color cl = red;
	int data;
	node* left = nullptr, * right = nullptr, * parent = nullptr;

};
node* root = nullptr;
void push1(node*);
void push2(node*);
void push3(node*);
void push4(node*);
void push5(node*);
node* parent(node* n)
{
	node* tmp = nullptr;
	if (n && n->parent)
		tmp = n->parent->parent;
	return tmp;
}
node* ancstr(node* n)
{
	node* tmp = nullptr;
	if (node const* anc = parent(n))
		tmp = (anc->left == n->parent ? anc->right : anc->left);
	return tmp;
}
void lft(node* n)
{
	node* tmp = n->right;
	tmp->parent = n->parent;
	if (n->parent != nullptr)
	{
		if (n->parent->left == n)
			n->parent->left = tmp;
		else
			n->parent->right = tmp;
	}
	else
		root = tmp;
	n->right = tmp->left;
	if (tmp->left != nullptr)
		tmp->left->parent = n;
	n->parent = tmp;
	tmp->left = n;
}
void rght(node* n)
{
	node* tmp = n->left;
	tmp->parent = n->parent;
	if (n->parent != nullptr)
	{
		if (n->parent->left == n)
			n->parent->left = tmp;
		else
			n->parent->right = tmp;
	}
	else
		root = tmp;
	n->left = tmp->right;
	if (tmp->right != nullptr)
		tmp->right->parent = n;
	n->parent = tmp;
	tmp->right = n;
}
void push(node*& root, int data)
{
	node** anc = &root;
	node* parent = nullptr;
	while (*anc)
	{
		parent = *anc;
		if (data < (*anc)->data)
			anc = &(*anc)->left;
		else if (data > (*anc)->data)
			anc = &(*anc)->right;
		else
			break;
	}
	if (*anc == nullptr)
	{
		*anc = new node;
		(*anc)->data = data;
		(*anc)->parent = parent;
		push1(*anc);
	}
}
void push1(node* n)
{
	if (n->parent == nullptr)
		n->cl = black;
	else
		push2(n);
}
void push2(node* n)
{
	if (n->parent->cl == black)
	{
		return;
	}
	else
	{
		push3(n);
	}
}
void push3(node* n)
{
	node* t = ancstr(n), * l = nullptr;
	if ((t != nullptr) && (t->cl == red))
	{
		n->parent->cl = black;
		t->cl = black;
		l = parent(n);
		l->cl = red;
		push1(l);
	}
	else
	{
		push4(n);
	}
}
void push4(node* n)
{
	node* l = parent(n);
	if ((n == n->parent->right) && (n->parent == l->left))
	{
		lft(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == l->right))
	{
		rght(n->parent);
		n = n->right;
	}
	push5(n);
}
void push5(node* n)
{
	node* l = parent(n);
	n->parent->cl = black;
	l->cl = red;
	if ((n == n->parent->left) && (n->parent == l->left))
	{
		rght(l);
	}
	else if ((n == n->parent->right) && (n->parent == l->right))
	{
		lft(l);
	}
}
node* find(int const data)
{
	node* tmp = root;
	while (tmp)
	{
		if (data < tmp->data)
			tmp = tmp->left;
		else if (data > tmp->data)
			tmp = tmp->right;
		else
			break;
	}
	return tmp;
}
void print(node* root, int level = 0)
{
	if (root)
	{
		print(root->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "|";
		cout << root->data << endl;
		print(root->left, level + 1);
	}
}
int main()
{
	push(root, 1);
	push(root, 3);
	push(root, 4);
	push(root, 19);
	push(root, 13);
	push(root, 32);
	push(root, 37);
	push(root, 55);
	print(root);
	system("pause");

}
