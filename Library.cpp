//
//  Library.cpp
//  Library_Management
//
//  Created by Sharad Kangude on 01/01/21.
//

#include "Library.hpp"
void Library::showBooks(){
    list<Book>::iterator it;
    //cout<<"SrNo. Book_Name : Price : Quantity"<<endl;
    cout << "_____________________________________" << endl;
           cout <<"Book_Id\t\tBook Name\t\tPrice(in INR)\tQUANTITY"<< endl;
           cout << "---------------------------------------------------------------------" << endl;
    for(it = this->books.begin(); it != this->books.end(); ++it){
        cout<<it->getBookId()<<".\t\t"<<it->getBookName()<<"\t\t\t: "<<it->getBookPrice()<<"\t : "<<it->getBookQuantity()<<endl;
    }
}
list<Book>::iterator Library::getBookByName(string bName){
    list<Book>::iterator it;
    for(it = this->books.begin(); it != this->books.end(); ++it){
        if (it->getBookName()==bName) {
            break;
        }
    }
    return it;
}
string Library::getBookNameById(int id){
    list<Book>::iterator it;
    for(it = this->books.begin(); it != this->books.end(); ++it){
        if (it->getBookId()==id) {
            return it->getBookName();
        }
    }
    return NULL;
}
bool Library::addBooks(string donorName){
    string bName;int bPrice,bQuantity;
    cout<<"Give information of donated Book :"<<endl;
    cout<<"Enter book name :";cin>>bName;
    cout<<"Enter book quantity :";cin>>bQuantity;
    list<Book>::iterator it = getBookByName(bName);
    map<int, int> Temp;
    pair<int, int> tempPair;
    if (it==books.end()) {
        cout<<"Book not present in Library Enter book price :";cin>>bPrice;
        Book book(bName,bPrice,bQuantity);
        this->books.push_back(book);
        tempPair = pair<int, int>(book.getBookId(),bQuantity);
    } else {
        it->setBookQuantity(it->getBookQuantity()+bQuantity);
        tempPair = pair<int, int>(it->getBookId(),bQuantity);
    }
    map<string, map<int, int> >::iterator donorInstatance=this->getDonorByName(donorName);
    if (donorInstatance==this->donorList.end()) {
        Temp.insert(tempPair);
        this->donorList.insert(pair<string, map<int,int> >(donorName,Temp));
    } else {
        donorInstatance->second.insert(tempPair);
    }
    cout<<"Books donated successfully!"<<endl;
    return true;
}

bool Library::lendBooks(string lenderName){
    string bName;int bQuantity;
    cout<<"Give information of lend Book :"<<endl;
    cout<<"Enter book name :";cin>>bName;
    cout<<"Enter book quantity :";cin>>bQuantity;
    list<Book>::iterator it = getBookByName(bName);
    map<int, int> Temp;
    pair<int, int> tempPair;
    if (it==books.end()) {
        cout<<"Book not present in Library. Can't lend.";
        return false;
    } else {
        if ((it->getBookQuantity()-bQuantity)>-1) {
            it->setBookQuantity(it->getBookQuantity()-bQuantity);
            tempPair = pair<int, int>(it->getBookId(),bQuantity);
        } else {
            char ch;
            cout<<"Library doens't have that much quantity."
                <<"Only have "<<it->getBookQuantity()<<" books"<<endl
            <<"Do you want to proceed with that quantity(y/n):";
            cin>>ch;
            if (ch=='y' || ch=='Y') {
                tempPair = pair<int, int>(it->getBookId(),it->getBookQuantity());
                it->setBookQuantity(0);
            } else {
                cout<<"Library doens't have that much quantity. Can't lend"<<endl;
                return false;
            }
        }
    }
    map<string, map<int, int> >::iterator lenderInstatance=this->getLenderByName(lenderName);
    if (lenderInstatance==this->lenderList.end()) {
           Temp.insert(tempPair);
           this->lenderList.insert(pair<string, map<int,int> >(lenderName,Temp));
       } else {
           lenderInstatance->second.insert(tempPair);
       }
    cout<<"Books lended successfully!"<<endl;
    return true;
}

void Library::showDonor(){
    map<string, map<int, int> >::iterator it;
    cout<<"\nDonors are : "<<endl;
    //cout<<'\t'<<"Donor Name"<<'\t'<<"Book Name"<<'\t'<<"Book Quantity"<<endl;
    cout << "_____________________________________" << endl;
    cout <<"SR_NO\t\tDonor_Name\t\tBook_Name\tQuantity"<< endl;
    cout << "---------------------------------------------------------------------" << endl;
    int i=0;
    for (it=this->donorList.begin();it!=this->donorList.end();it++) {
        map<int, int>::iterator donor;
        for (donor=it->second.begin();donor!=it->second.end();donor++) {
            i++;
        cout<<i<<".\t\t"<<it->first<<"\t\t\t"<<this->getBookNameById(donor->first)<<'\t'<<donor->second<<endl;
        }
    }
    cout<<endl;
}
void Library::showLender(){
    map<string, map<int, int> >::iterator it;
    cout<<"\nLenders are : "<<endl;
    cout << "_____________________________________" << endl;
    cout <<"SR_NO\t\tLender_Name\t\tBook_Name\tQuantity"<< endl;
    cout << "---------------------------------------------------------------------" << endl;
    int i=0;
    for (it=this->lenderList.begin();it!=this->lenderList.end();it++) {
        map<int, int>::iterator lender;
        for (lender=it->second.begin();lender!=it->second.end();lender++) {
            i++;
            cout<<i<<".\t\t"<<it->first<<"\t\t\t"<<this->getBookNameById(lender->first)<<'\t'<<lender->second<<endl;
        }
    }
    cout<<endl;
}
map<string, map<int, int> >::iterator Library::getDonorByName(string dName){
    map<string, map<int, int> >::iterator it;
    for (it=this->donorList.begin();it!=this->donorList.end();it++) {
        if (it->first==dName) {
            break;
        }
    }
    return it;
}
map<string, map<int, int> >::iterator Library::getLenderByName(string dName){
    map<string, map<int, int> >::iterator it;
    for (it=this->lenderList.begin();it!=this->lenderList.end();it++) {
        if (it->first==dName) {
            break;
        }
    }
    return it;
}
bool Library::returnBooks(string lenderName){
    map<string, map<int, int> >::iterator it = this->getLenderByName(lenderName);
    if (it!=this->lenderList.end()) {
        cout<<"Displaying books lended to "<<lenderName<<" :"<<endl;
        cout << "_____________________________________" << endl;
        cout <<"SR_NO\t\tLender_Name\t\tBook_Name\tQuantity"<< endl;
        cout << "---------------------------------------------------------------------" << endl;
        map<int, int>::iterator lender;
        int i=0;
        for (lender=it->second.begin();lender!=it->second.end();lender++) {
            i++;
        cout<<i<<".\t\t"<<it->first<<"\t\t\t"<<this->getBookNameById(lender->first)<<'\t'<<lender->second<<endl;
        }
        string bName;int bQuantity;
        cout<<endl<<endl<<"Enter book name to return :";cin>>bName;
        cout<<"Enter Quantity to return :";cin>>bQuantity;
        list<Book>::iterator Bookit = getBookByName(bName);
        map<int, int> Temp;
        map<int, int>::iterator lenderInstatance;
        for (lender=it->second.begin();lender!=it->second.end();lender++) {
            if (lender->first==getBookByName(bName)->getBookId()) {
                lenderInstatance = lender;
                break;
            }
        }
        if ((lenderInstatance->second-bQuantity)>-1) {
            Bookit->setBookQuantity(Bookit->getBookQuantity()+bQuantity);
            lenderInstatance->second = lenderInstatance->second-bQuantity;
        } else {
            cout<<"Return quantity is greater than lended quantity."<<endl;
            return false;
        }
        
    } else {
        cout<<"No books to return."<<endl;
        return false;
    }
    cout<<"Return Successfull!"<<endl;
    return true;
}
