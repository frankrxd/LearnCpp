#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
public:
	String() {
		_pstr = nullptr;
	};
	String(const char* pstr);
	String(const String& rhs);
	String& operator=(const String rhs);
	String& operator=(const char* rhs);
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	String& operator+(const String& rhs);
	String& operator+(const char* rhs);
	char& operator[](std::size_t index);
	const char& operator[](std::size_t index) const;
	size_t size() const;
	const char* c_str() const;
	~String();
private:
	char* _pstr;
};

String operator+(const String&, const String&);
String operator+(const String&, const char*);
String operator+(const char*, const String&);