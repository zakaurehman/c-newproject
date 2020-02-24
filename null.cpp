// insertH.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;

struct node
{
	double data;
	node* left;
	node* right;
	node* parent;

	node()
	{
		data=0;
		left=right=parent=0 ;
	}

};

struct minHeap
{
	node* root ;
	minHeap()
	{
		root =0 ;
	}

	queue<node*> q,temp ;
	deque<node*> dq;
		void add(double info)
		{
			node* pnew = new node;
			pnew->data =info ;
			if(root==0)
			{
				root =pnew;
				q.push(pnew);
			}
			else
			{
				node* ptemp = q.front();
				if(ptemp->left ==0)
				{
					ptemp->left = pnew ;
					pnew->parent = ptemp ;
					q.push(ptemp->left);
				}
				else
				{
					ptemp->right = pnew ;
					pnew->parent = ptemp ;
					q.push(ptemp->right);
				}

				if(ptemp->left!=0 && ptemp->right !=0)
				{
					q.pop();
				}
			}
			while(pnew->parent!=0)
			{
				while(pnew->data < pnew->parent->data )
				{
					std::swap(pnew->parent->data,pnew->data);
				}
				pnew=pnew->parent ;
			}
		}
		void orderLevelcopy(node* root)
		{
			if(root==0)
			{
				return ;
			}
			else
			{
				temp.push(root);
				while(!temp.empty())
				{
					node* atemp = temp.front() ;
					dq.push_back(atemp);
					if(atemp->left!=0)
					{
						temp.push(atemp->left);
					}
					if(atemp->right!=0)
					{
						temp.push(atemp->right);
					}
					temp.pop();
				}

			}
		}
		void Delete()
		{
			dq.clear();
			if(root==0)
			{
				return ;
			}
			else
			{
				orderLevelcopy(root);
				node* pFirst = root ;
				node* pLast = dq.back() ;
				std::swap(pFirst->data,pLast->data);
				node* parLast = pLast->parent ;
				if(parLast->left->data == pLast->data )
				{
					pLast->parent->left = 0;
					pLast->parent =0;
					delete pLast;
				}
				else
				{
					pLast->parent->right = 0;
					pLast->parent =0;
					delete pLast;
				}
				while(pFirst !=0)
				{
					node* v ;
					if(pFirst->right->data < pFirst->left->data)
					{
						v = pFirst->right ;
						std::swap(pFirst->data,v->data);
						pFirst = pFirst->right ;
					}
					else
					{
						v = pFirst->left ;
						std::swap(pFirst->data,v->data);
						pFirst = pFirst->left ;
					}


					if(pFirst->left ==0 && pFirst->right==0 )
					{
						break;
					}
				}
			}

		}

		void inOrder(node* root)
		{
			queue<node*> a;
			a.push(root);
			while(!a.empty())
			{
				node* p= a.front();
				cout<<p->data<<"  ";
				if(p->left!=0)
				{
					a.push(p->left);
				}
				if(p->right!=0)
				{
					a.push(p->right);
				}
				a.pop();
			}
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	minHeap h;
	h.add(5);
	h.add(2);
	h.add(7);
	h.add(10);
	h.add(13);
	h.add(16);
	h.inOrder(h.root);
	h.Delete();
	cout<<endl;
	h.inOrder(h.root);
	system("pause");
	return 0;
}

