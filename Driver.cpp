//
//  Driver.cpp
//  Library_Management
//
//  Created by Sharad Kangude on 03/01/21.
//

#include "Driver.hpp"

int Driver::getChoice(){
    int x;
    cout<<endl<<endl<<endl;
    cout<<"1. Show all books."<<endl;
    cout<<"2. Donate books."<<endl;
    cout<<"3. Lend books."<<endl;
    cout<<"4. Return books."<<endl;
    cout<<"5. Display donors List."<<endl;
    cout<<"6. Display lenders List."<<endl;
    cout<<"7. Quit."<<endl;
    cout<<"Enter choice:";cin>>x;
//    system("clear");
    cout<<"\033[2J\033[1;1H"<<flush;
    return x;
}
void Driver::Start(){
    string dName,lName;
    switch (getChoice()) {
        case 1:
            this->library.showBooks();
            break;
        case 2:
            cout<<"Enter Donor Name:"<<flush;cin>>dName;
            this->library.addBooks(dName);
            break;
        case 3:
            cout<<"Enter Lender Name:"<<flush;cin>>lName;
            this->library.lendBooks(lName);
            break;
        case 4:
            cout<<"Enter Lender Name:"<<flush;cin>>lName;
            this->library.returnBooks(lName);
            break;
        case 5:
            this->library.showDonor();
            break;
        case 6:
            this->library.showLender();
            break;
        case 7:
            cout<<"Exiting...";
            exit(0);
       default:
            break;
    }
    
}
