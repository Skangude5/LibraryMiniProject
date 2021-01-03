//
//  Driver.hpp
//  Library_Management
//
//  Created by Sharad Kangude on 03/01/21.
//  Copyright © 2021 Sharad Kangude. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include "Library.cpp"
class Driver{
private:
    Library library;
public:
    int getChoice();
    void Start();
};
#endif /* Driver_hpp */
