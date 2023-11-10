
#include "unsorted.h"
#include <chrono>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std ;

/* Implements the methods declared in the uns class in unsorted.h. */

// Initializes the uns class object with the provided data.
uns::uns(string * pairs ,unsigned long int totalpairs,int * Num,int q,string * randomwords){
    this->totalpairs=totalpairs;
    this->Q=q;
    randomw=new string[Q];
    unsArr=new string[totalpairs];
    num = new int[totalpairs];
    for(unsigned long int i = 0 ; i < totalpairs ; i ++ ){
        unsArr[i]=pairs[i];
        num[i]=Num[i];
    }
    for(int i =0 ; i < Q ; i ++){
        randomw[i]=randomwords[i];
    }

}

uns::~uns(){
    delete []unsArr;
}

/* Performs a sequential search for each random pair in the unsorted array (unsArr).
*/



void uns::searchUnsorted(){
ofstream fout;
fout.open("results.txt");
auto start = chrono::steady_clock::now();
bool flag=true;
for(int j = 0 ; j < Q ; j++){
    for(unsigned int i = 0  ; i < totalpairs && flag; i++){
        if (randomw[j]==unsArr[i]){
            flag=false;
            fout<<randomw[j]<<" || Appears: "<<num[j]<<" times "<<endl;
        }

    }
flag=true;
}

/* Records the time taken for the search operation in nanoseconds, microseconds, milliseconds, and seconds. Also records
the time taken for the search operation in nanoseconds, microseconds, milliseconds, and seconds. */


auto end = chrono::steady_clock::now();
fout<<"Time taken to find "<<Q<<" pairs in unsorted array structure :"<<endl;
 fout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    fout << "Elapsed time in microseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;

    fout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    fout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec"<<endl;
        for(int i=0;i<10;i++){fout<<endl;}

fout.close();
}

