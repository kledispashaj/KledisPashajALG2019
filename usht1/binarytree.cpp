#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

struct node{
	string data;
	node *majte,*djathte,*p;
};

node *insertTree(node *T, node *z)
{
	node *y = NULL;
	node *x = T;

	while(x != NULL)
	{
		y = x;
	   int a = z->data.compare(x->data);
		if(a==0)
		return T;
		else if(a<0)
		x = x->majte;
		else x = x->djathte;
	}
	z->p = y;

	if(y==NULL)
		T = z;
	else if (z->data.compare(y->data)<0) 
	y->majte = z;
	else y->djathte = z;

	return T;
}

void paraRendore(node *T)
{
	if(T != NULL) {
		
		cout<<T->data<<" ";
		paraRendore(T->majte);
		paraRendore(T->djathte);
		
		}
}

string strip(string in) 
  {
  in.erase(remove_if(in.begin(), in.end(), [] (string::value_type ch)
      { return !isalpha(ch); }
    ), in.end());
  return in;
  }

int main(){
	string x;
	node *rrenja=NULL, *z=NULL;
	
	ifstream inFile;
	inFile.open("datafile2.txt");
	if (!inFile) {
    cerr << "Unable to open datafile";
    exit(1);
    }
    while (inFile >> x){
       	z = new node;
		z->data = strip(x);
		z->majte = NULL;
		z->djathte = NULL;
		z->p = NULL;
		rrenja= insertTree(rrenja,z);
     }
    inFile.close();
    paraRendore(rrenja);
	
	return 0;
}
