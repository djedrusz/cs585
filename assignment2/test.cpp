#include <stdio.h>

template<typename T>
class v {
public:
	virtual void test() = 0;
};

template<typename T>
class b : public v<T>{
private:
	T data;
public:
	b(T t);
	void test();
};

template<typename T> b<T>::b(T t) {
	data = t;
}

template<typename T> void b<T>::test() {
	printf("please work\n");
}

int main(int argc, char** argv) {
	b<int> tester(2);
	tester.test();
	return 0;
}
