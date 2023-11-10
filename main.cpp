#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include "unsorted.h"
#include <cstring>
#include <string>
#include "sorted.h"

using namespace std;

int main()
{

ifstream book;
string str;
char charToRead,charLastRead=' ';


/* Opens a file named "book.txt" and reads its contents character by character.
 */

book.open("book.txt");
if (book.is_open()){
    cout<<"File opened successfully !"<<endl;
}
else
    cerr<<"Could not open file";

  /* Converts each character to lowercase.
 */
while (!book.eof()){
    book.get(charToRead);
    charToRead=tolower(charToRead);
    // checks for double spaces and if there are it does not count them
    if ((charLastRead==' ' && charToRead==' ' )|| charToRead=='\n'){}
        else{
            if (!ispunct(charToRead)){
                str+=charToRead;
            }
            }
    charLastRead=charToRead;
}
cout<<"File read successfully !"<<endl;
book.close();

// Finds total words
unsigned long int totalwords=1;
for(unsigned long int i = 0 ; i < str.size() ; i++){
    if (isspace(str[i]))
        totalwords++;
}

string * words = new string[totalwords];
string * allPairs = new string[totalwords-1];
string * pairs = new string[totalwords-1];

// Separates words from the string read earlier and stores them in the words array
unsigned long int a=0;
for(unsigned long int i=0;i<str.size();i++){
   if(isspace(str[i])){
        a++;
    }
    else{
        words[a]+=str[i];
    }
}

// Creates pairs of consecutive words and stores them in the allPairs array.
for (unsigned long int i = 0 ; i < totalwords-1 ;i ++){
  allPairs[i]=words[i]+" "+words[i+1] ;
}



// Extracts unique pairs and stores them in the pairs array
unsigned long int countt = 0 ;
bool thereIs=false;
for (unsigned long int i = 0 ; i < totalwords-1 ; i++){
    for (unsigned long int j =0 ; j < countt && thereIs==false ; j++){
        if (pairs[j]==allPairs[i]){
            thereIs=true;
        }
    }
    if (!thereIs){
        pairs[countt]=allPairs[i];
        countt++;
    }
    thereIs=false;
}



// Generates a random number Q and selects Q random pairs from the unique pairs array.
int Q = rand()%1501+1000;
int random2;
string *randomwords = new string[Q];
for(int i=0;i<Q;i++){
    random2=rand() % totalwords;
    randomwords[i]=pairs[random2];
}




// Calculates the frequency of each pair in the original array and stores it in the NUM array.

int NUM[countt];
for (unsigned long int j=0;j<countt;j++){
    for(unsigned long int i=0;i<totalwords-1;i++){
        if(pairs[j]==allPairs[i])
            NUM[j]++;
    }
}




uns A(pairs,countt,NUM,Q,randomwords); //Creates an object of the uns class named A using the dynamically generated data

A.searchUnsorted(); // Calls the searchUnsorted method of the A object to perform a search for each random pair in the unsorted array.

//Memory Cleanup
delete []words;
delete []pairs;
delete []randomwords;
delete []allPairs;

    return 0;
}

