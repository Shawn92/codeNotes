class CMyString {
public:
	// 构造函数
	CMyString(const char *pszSrc = NULL) {
		cout << "CMyString(const char *pszSrc = NULL)" << endl;
		if (pszSrc == NULL) {
			m_pData = new char[1];
			*m_pData = '\0';
		}
		else {
			m_pData = new char[strlen(pszSrc) + 1];
			strcpy(m_pData, pszSrc);
		}
	}

	// 拷贝构造函数
	CMyString(const CMyString &s) {
		cout << "CMyString(const CMyString &s)" << endl;
		m_pData = new char[strlen(s.m_pData) + 1];
		strcpy(m_pData, s.m_pData);
	}

	// move构造函数     ----        实质上就是·窃取·临时对象，注意参数的形式
	CMyString(CMyString &&s) {
		cout << "CMyString(CMyString &&s)" << endl;
		m_pData = s.m_pData;
		s.m_pData = NULL;
	}

	// 析构函数
	~CMyString(){
		cout << "~CMyString()" << endl;
		delete[] m_pData;
		m_pData = NULL;
	}

	// 拷贝赋值函数
	CMyString &operator =(const CMyString &s) {
		cout << "CMyString &operator =(const CMyString &s)" << endl;
		if (this != &s){
			delete[] m_pData;
			m_pData = new char[strlen(s.m_pData) + 1];
			strcpy(m_pData, s.m_pData);
		}
		return *this;
	}

	// move赋值函数
	CMyString &operator =(CMyString &&s){
		cout << "CMyString &operator =(CMyString &&s)" << endl;
		if (this != &s)
		{
			delete[] m_pData;
			m_pData = s.m_pData;
			s.m_pData = NULL;//重置s中的m_pData指针防止析构时发生问题
		}
		return *this;
	}

private:
	char *m_pData;
};