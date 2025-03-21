#include<iostream>
using namespace std;
class a{
	public:
	virtual void show()=0;
};
class b:public a{
};
int main(void){
	b B;
	return 0;
}
