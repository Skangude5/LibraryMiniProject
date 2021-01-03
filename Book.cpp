//
//  Book.cpp
//  Library_Management
//
//  Created by Sharad Kangude on 01/01/21.
//

#include "Book.hpp"
int Book::bookObjectCounter=1;
Book::Book(string name, int price, int quantity){
    this->bookId = this->bookObjectCounter;
    this->bookName = name;
    this->bookQuantity = quantity;
    this->bookPrice = price;
    this->bookObjectCounter++;
}
int Book::getBookId(){
    return this->bookId;
}
string Book::getBookName(){
    return this->bookName;
}
int Book::getBookQuantity(){
    return this->bookQuantity;
}
int Book::getBookPrice(){
    return this->bookPrice;
}
void Book::setBookQuantity(int quantity){
    this->bookQuantity = quantity;
}
