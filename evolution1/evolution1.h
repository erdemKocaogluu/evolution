
#ifndef EVOLUTION1_H
#define EVOLUTION1_H

#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class evolution1
{
private:





public:


    string mutation(string str ) ;

    string nextGenCreating( string str1 , string str2 ) ;

    int fitnessScoreLoser(string str1 , string str2 , string str3, string goal ) ;


    evolution1(/* args */);
    ~evolution1();
};

evolution1::evolution1(/* args */)
{
}

evolution1::~evolution1()
{
}



#endif