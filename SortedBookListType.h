#ifndef H_SortedBookListType
#define H_SortedBookListType

#include<iostream>
#include<string>
using namespace std;

 
class BookType{
 public:
string title;
string author;
int year;
bool checked_out;
BookType(string,string,int,bool=false); //O(1)
BookType(); //O(1)
void printBookInfo(); //O(1)
};

BookType::BookType(string t ,string a ,int y ,bool c){
title=t;
author=a;
year=y;
checked_out=c;

}

BookType::BookType(){
  title="";
  author="";
  year=0;
  checked_out=false;
}

void BookType::printBookInfo(){
  cout<<title<<", "<<author<<", "<<year<<", ";
  if(checked_out==true) 
  cout<<"this book is checked out."<<endl;
  else
  cout<<"this book is not checked out."<<endl;
  cout<<endl;
  
}

class BookNode{
 public: 
BookType book;
BookNode *link;
};

class SortedBookListType{
BookNode *first;
BookNode *last;
int counter;
public:
SortedBookListType(); //O(1)
~SortedBookListType(); //O(n)
bool isempty(); //O(1)
int length(); //O(1)
void print(); //O(n)
void insertBook(const BookType& item); //O(n)
void deleteBook(BookType& item); //O(n)
bool searchByTitle(string title); //O(n)
bool searchByYear(int year); //O(n)
int countCheckOut(); //O(n)
int countCopies(BookType book); //O(n)
void checkBookOut(string t); //O(n)
void returnBook(string t); //O(n)
};

SortedBookListType::SortedBookListType(){
first=NULL;
last=NULL;
counter=0;
}

SortedBookListType::~SortedBookListType(){
BookNode *temp;  
while (first != NULL){
temp = first;  
first = first->link;  
delete temp; 
}
last = NULL;  
counter = 0;
}

bool SortedBookListType::isempty(){
return(counter==0);
}

int SortedBookListType::length(){
return counter;
}

void SortedBookListType::print(){
BookNode *current;
current=first;
while(current!=NULL){
current->book.printBookInfo() ;
current=current->link;}
}

void SortedBookListType::insertBook(const BookType& item){
 
  BookNode *current;
  BookNode *trailcurrent;
  BookNode *newbook;
  bool found;
  newbook= new BookNode;
  newbook->book.title=item.title;
  newbook->book.author=item.author;
  newbook->book.year=item.year;
  newbook->book.checked_out=item.checked_out;
  newbook->link=NULL;

if (first == NULL) //Case 1:the list is empty
{
first = newbook;
last = newbook;
counter++;
}
else
{
current = first;
found = false;
while (current != NULL && !found) 
if (current->book.year >= item.year)
found = true;
else
{
trailcurrent = current;
current = current->link;
}
if (current == first) //Case 2:the item is smaller than the smallest
{
newbook->link = first;
first = newbook;
counter++;
}
 
else //Case 3:the item is larger than the largest
{
trailcurrent->link = newbook;
newbook->link = current;
if (current == NULL)
last = newbook;
counter++;
}
}
}

void SortedBookListType::deleteBook(BookType& item){
  BookNode *current;
  BookNode *trailcurrent;
  bool found;

  //case 1:the list is empty
  if(first==NULL)
  {cout<<"there are no books in the list to delete"<<endl;
  cout<<endl;}
  else{
    current=first;
    found=false;

    while(current!=NULL && !found){
      if(current->book.year >= item.year)
       found=true;
      else
      {
        trailcurrent=current;
        current=current->link;
      }
    }
  //case 2:the book is not exist in the list
   if(current==NULL)
   { cout<<"the book you want to delete does not exist in the list"<<endl;
      cout<<endl;} 
   else if(current->book.year == item.year &&
    current->book.title.compare(item.title)==0 &&
    current->book.author.compare(item.author)==0){
  //case 3:the book we want to delete is the first book
     if(first==current){
       first=first->link;
       if(first==NULL)
       last=NULL;
       delete current;
     }
   //case 4:the book we want to delete in the middle
     else{
       trailcurrent->link=current->link;
       if(current==last)
       last=trailcurrent;
       delete current;
     }
     counter--;
   }
   else {
     cout<<"the book you want to delete does not exist in the list"<<endl;
      cout<<endl;}
  }
}

bool SortedBookListType::searchByTitle(string title){
  bool found=false;
  BookNode *current;
  current=first;
  while(current!=NULL && !found){
    if (current->book.title.compare(title)==0)
      found = true;
    else
     current = current->link;
  }
  return found; 
}

bool SortedBookListType::searchByYear(int year){
  bool found=false;
  BookNode *current;
  current=first;
  while(current!=NULL && !found){
    if (current->book.year >= year)
      found = true;
    else
     current = current->link;
  }
  if(found)
   found=(current->book.year==year);

  return found; 
}

int SortedBookListType::countCheckOut(){
  int numofcheckoutbook=0;
  BookNode *current;
  current=first;
  while(current!=NULL){
    if(current->book.checked_out==true)
     numofcheckoutbook++;
    current=current->link;
  }
 return numofcheckoutbook; 
}

int SortedBookListType::countCopies(BookType b){
  BookNode *current;
  current=first;
  int numofcopies=0;
  
  while(current!=NULL){
   if(current->book.title.compare(b.title)==0 &&
    current->book.author.compare(b.author)==0 &&
    current->book.year==b.year)  
   {numofcopies++;}
   current=current->link;
  }
  return numofcopies;
}

void SortedBookListType::checkBookOut(string t){
BookNode *current;
current=first;
bool found=false;

while(current!=NULL){
  if(current->book.title.compare(t)==0)
  {
    found=true;

    if(current->book.checked_out==false){
    current->book.checked_out=true;
    break;
    } 
    else{
      cout<<"all copies of this book are already checked out"<<endl;
      cout<<endl;
      break;
    }
  }
  else
    current=current->link;
}
}


void SortedBookListType::returnBook(string t){
BookNode *current;
current=first;
bool found=false;

while(current!=NULL){
  if(current->book.title.compare(t)==0)
  {
    found=true;

    if(current->book.checked_out==true){
    current->book.checked_out=false;
    break;
    } 
  }
  else
current=current->link;
}
}

#endif