
	vector <int> listToVec(ListNode *p) {
		vector <int> a;
		while(p) a.push_back(p->val), p = p->next;
		return a;
	}

	ListNode* vecToList(const vector <int> &a) {
		auto h = new ListNode(0), p = h;
		for(const int &x: a) p->next = new ListNode(x), p = p->next;
		return h->next;
	}
