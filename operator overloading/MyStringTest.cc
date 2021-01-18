#include "MyString.h"

void test()
{
	String str1;
	//str1.print();
	String str2 = "Hello,world";
	const char* p = "hello,2020";
	String str3("wangdao");
	String str4 = str3;
	str4 = str2;
	str3 += str2;
	cout<<str3<<endl;
	str3 += p;
	cout<<str3<<endl;
	str3 = p + str3;
	cout << str3 << endl;
	String str5;
    cout<<"please input a string: \n";
	cin>>str5;
	cout<<str5<<endl;
	cout<<str5.size()<<endl;
    
    String str6="Hello,worldd";
    cout<<"str2==str6: "<<(str2==str6)<<endl;
    cout<<"str2>str6: "<<(str2>str6)<<endl;
    cout<<"str2<str6: "<<(str2<str6)<<endl;
    
}
int main(void)
{
    test();
	return 0;
}
