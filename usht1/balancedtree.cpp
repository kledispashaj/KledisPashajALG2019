#include<bits/stdc++.h> 
#include <fstream>
#include <algorithm>
#include <string>
using namespace std; 
  
class Node  
{  
    public: 
    string data;  
    Node *left;  
    Node *right;  
    int height;  
};  
  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  
    int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  

Node* newNode(string data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
                      
    return(node);  
}  
  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    x->right = y;  
    y->left = T2;  
  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
                    
    return x;  
}  
  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  

    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}  
  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
Node* insert(Node* node, string data)  
{  
    if (node == NULL)  
        return(newNode(data));  
        
    int a = data.compare(node->data);
    if (a==0)
        return node;
    if (a<0)  
        node->left = insert(node->left, data);  
    else  
        node->right = insert(node->right, data);  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
  
    if (balance > 1 && data.compare(node->left->data)<0)
        return rightRotate(node);  
  
    if (balance < -1 && data.compare(node->right->data)>0)  
        return leftRotate(node);  
  
    if (balance > 1 && data.compare(node->left->data)>0)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
   
    if (balance < -1 && data.compare(node->right->data)<0)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  
  
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  
  
string strip(string in) 
{
  in.erase(remove_if(in.begin(), in.end(), [] (string::value_type ch)
      { return !isalpha(ch); }
    ), in.end());
  return in;
}
  
  
int main()  
{  
string x;
	Node *rrenja=NULL;
	
	ifstream inFile;
	inFile.open("datafile4.txt");
	if (!inFile) {
    cerr << "Unable to open datafile";
    exit(1);
    }
    
    while (inFile >> x)
    	rrenja = insert(rrenja, strip(x));
    inFile.close();
	preOrder(rrenja);  
	return 0;
}
