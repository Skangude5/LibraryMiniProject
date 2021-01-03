//
//  Book.hpp
//  Library_Management
//
//  Created by Sharad Kangude on 01/01/21.
//  Copyright © 2021 Sharad Kangude. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <iostream>
using namespace std;
class Book{
private:
    static int bookObjectCounter;
    int bookId;
    string bookName;
    int bookPrice;
    int bookQuantity;
public:
    Book(string,int,int);
    int getBookId();
    string getBookName();
    int getBookQuantity();
    int getBookPrice();
    void setBookQuantity(int);
};
#endif /* Book_hpp */
