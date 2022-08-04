#include<iostream>
#include<list>
#include<cstring>
#include<iterator>

using namespace std;


class Book{
public:
	string name;
	int price;

	Book(){
	}

	Book(string name, int price){
		this->name=name;
		this->price=price;
	}
};

class BookCompare{
public:
	bool operator()(Book A, Book B){
		if(A.name==B.name)
			return true;
		return false;
	}
};

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
	while(start!=end){
		if(*start==key)
			return start;
		start++;
	}
	return end;
}

template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp){
	while(start!=end){
		if(*start==key)
			return start;
		start++;
	}
	return end;
}



int main(){
	Book b1("java", 150);
	Book b2("C++", 100);
	Book b3("Python", 200);
	list<Book> l;

	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);

	Book bookToFind("C++",110);

	BookCompare cmp;

	list<Book>::iterator it = search(l.begin(),l.end(),bookToFind, cmp);

	if(it!=l.end())
		cout<<"book found at: "<<endl;//it-l.begin()<<endl;
	else
		cout<<"not found"<<endl;
}
