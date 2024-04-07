#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node
{
	int data;
	Node *right;
	Node *left;
};

void CreatTree(Node *&root)
{
	root = NULL;
}

void AddNode(Node *&root, int x)
{
	if(root == NULL)
	{
		Node *p =  new Node;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		root = p;
	}
	else
	{
		if(root->data > x)
		{
			AddNode(root->left, x);
		}
		else if(root->data < x)
		{
			AddNode(root->right, x);
		}
	}
}

void NLR(Node *root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

bool Search(Node *&root, int x)
{
	if(root == NULL)
	{
		return false;
	}
	else
	{
		if(x < root->data)
		{
			return Search(root->left, x);
		}
		else if(x > root->data)
		{
			return Search(root->right, x);
		}
		else
		{
			return true;
		}
	}
	
	return false;
}

//Hàm sinh số ngẫu nhiên
int generateRandomNumber(int min, int max) 
{
    // Sinh số ngẫu nhiên trong phạm vi và trả về
    return min + rand() % (max - min + 1);
}

int main() {
    Node *Tree;
    CreatTree(Tree);
    
    int n;
    cin >> n;
    
    int minRange = 1; // Phạm vi nhỏ nhất
    int maxRange = 10000; // Phạm vi lớn nhất

	// Thiết lập seed cho hàm sinh số ngẫu nhiên
    srand(time(0));
    
    for(int i = 0; i < n; i++)
    {
	    // Sinh số ngẫu nhiên trong phạm vi từ 1 đến 100 và in ra
	    int randomNumber = generateRandomNumber(minRange, maxRange);
	    AddNode(Tree, randomNumber);
	}
	
	NLR(Tree);
	cout << endl;
	
	int x;
	cout << "Nhap so can tim: ";
	cin >> x;
	cout << endl;
	
	if(Search(Tree, x))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	
	return 0;
}
