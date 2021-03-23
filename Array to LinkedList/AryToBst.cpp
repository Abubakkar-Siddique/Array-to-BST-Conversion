#include<iostream>
#include<string.h>
using namespace std;
const int AS = 50;

struct node 
{
	int data;
	node *left;
	node *right;
};

class OrdToTree 
{
private:
	int Ary[AS];
	int Counter;
	node *root;
public:

	OrdToTree() 
	{
		Counter = 0;
		root = NULL;
	}

	node *getroot() 
	{
		return root;
	}

	bool OrderedArray(int Num) 
	{
		if (Counter < AS) {
			Ary[Counter] = Num;
			Counter++;
			return true;
		}
		else {
			return false;
		}
	}

	void view() 
	{
		for (int i = 0; i < Counter; i++) 
		{
			cout << Ary[i];
			cout << " ";
		}
		cout << "" << endl;
	}

	bool CreateTree() 
	{
		int mid;
		int i = 0;
		node *p, *c, *temp;
		p = c = temp = NULL;
		mid = Counter / 2;
		temp = new(node);
		temp->right = NULL;
		temp->left = NULL;
		temp->data = Ary[mid];

		if (root == NULL) 
		{
			root = temp;
		}

		if (Counter >= 4) 
		{
			while (i<Counter) 
			{
				temp = new(node);
				temp->right = NULL;
				temp->left = NULL;
				temp->data = Ary[i];

				if (i == mid) 
				{
					i++;
					continue;
				}
				else if (root->left == NULL && temp->data<root->data) 
				{
					root->left = temp;
					i++;
					continue;
				}
				else if (root->right == NULL && temp->data >= root->data) 
				{
					root->right = temp;
					i++;
					continue;
				}
				else
				{
					p = c = root;
					while (c != NULL)
					{
						p = c;
						if (c->data > temp->data)
						{
							c = c->left;
						}
						else
						{
							c = c->right;
						}
					}
					if (p->data <= temp->data)
					{
						p->right = temp;
						i++;
						continue;
					}
					else
					{
						p->left = temp;
						i++;
						continue;
					}

				}
			}
			return true;
		}
	}

	void viewtree(node *R) 
	{
		if (R == NULL)
			return;
		viewtree(R->left);
		cout << " ";
		cout << R->data;
		viewtree(R->right);
	}
};

int main() 
{
	OrdToTree o1;
	int Num;
	cout << "Enter 1 to enter data in ordered array" << endl;
	cout << "Enter 2 to view data from array" << endl;
	cout << "Enter 3 to make tree from array" << endl;
	cout << "Enter 4 to view tree" << endl;
	cin >> Num;
	while (Num != 0) {
		switch (Num) {
		case 1:
		{
			int Number;
			cout << "Enter the number u want to insert in ordered tree" << endl;
			cin >> Number;
			if (o1.OrderedArray(Number) == true) {
				cout << "Number is successfully inserted" << endl;
			}
			else {
				cout << "Array is full" << endl;
			}
		}
		break;
		case 2:
		{
			o1.view();
		}
		break;
		case 3:
		{
			if (o1.CreateTree() == true) {
				cout << "Tree is successfully created" << endl;
			}
			else {
				cout << "Tree cannot be created";
			}
		}
		break;
		case 4:
		{
			o1.viewtree(o1.getroot());
		}
		break;
		default:
		{
			cout << "Enter appropriate number" << endl;
		}
		break;
		}
		cout << "Enter 1 to enter data in ordered array" << endl;
		cout << "Enter 2 to view data from array" << endl;
		cout << "Enter 3 to make tree from array" << endl;
		cout << "Enter 4 to view tree" << endl;
		cin >> Num;

	}


}