//
//  Library.hpp
//  Library_Management
//
//  Created by Sharad Kangude on 01/01/21.
//

#ifndef Library_hpp
#define Library_hpp

#include "Book.cpp"
#include <list>
#include <map>
#include <iterator> 
using namespace std;

class Library{
private:
    list<Book> books;
    map<string, map<int, int> > lenderList;
    map<string, map<int, int> > donorList;
public:
    void showBooks();
    bool addBooks(string);
    bool lendBooks(string);
    bool returnBooks(string);
    void showDonor();
    void showLender();
    list<Book>::iterator getBookByName(string);
    string getBookNameById(int);
    map<string, map<int, int> >::iterator getDonorByName(string);
    map<string, map<int, int> >::iterator getLenderByName(string);
};
#endif /* Library_hpp */
