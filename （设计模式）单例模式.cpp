//饱汉模式
class singleTon {
protected:
	singleTon() {}
private:
	static singleTon* p;
public:
	static singleTon* initance();
	static std::mutex mtx;
};

singleTon* singleTon::p = NULL;

singleTon* singleTon::initance() {
	if (p == NULL) {
		if (mtx.try_lock()) {
			p = new singleTon();
			mtx.unlock();
		}
	}
	return p;
}