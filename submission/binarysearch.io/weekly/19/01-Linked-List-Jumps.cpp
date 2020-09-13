#include "solution.hpp"
using namespace std;

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
class Solution {
	public:
	LLNode* solve(LLNode* node) {
		
		vector <LLNode *> v;

		auto ptr=node;
		while(ptr) v.push_back(ptr),ptr=ptr->next;

		int pos=0;
		auto newptr=node;
		while(newptr)
		{
			if(pos+newptr->val>=v.size())
			{
				newptr->next=NULL;
				break;
			}
			pos+=newptr->val;
			newptr->next=v[pos];
			newptr=newptr->next;
		}

		return node;
	}
};
