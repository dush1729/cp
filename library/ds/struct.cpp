struct cell {
	int x, y, val;
	bool operator<(const cell &rhs) const {
		return val > rhs.val; // min pq
	}
};