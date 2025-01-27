shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
	if (_ptr != sp._ptr) {
		if (--(*pcount) == 0) {
			delete _ptr;
			_ptr = nullptr;
		}
		_ptr = sp._ptr;
		_pcount = sp.pcount;
		++(*pcount);
	}
		return *this; and_eq`q12e
}