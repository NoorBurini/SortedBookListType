#include <iostream>
#include "SortedBookListType.h"
using namespace std;


int main() {
SortedBookListType list;
BookType b1("Math", "Omar", 2020);
BookType b2("Biology", "Ali", 2012);
BookType b3("Chemistry", "Obada", 2005);
BookType b4("Physics", "Ahmad", 2010);
BookType b5("Programming", "Faris", 2010);

if(list.isempty()){
cout<<"***try to delete from empty list***"<<endl;
cout<<endl;
list.deleteBook(b5);}


list.insertBook(b1);
list.insertBook(b2);
list.insertBook(b3);
list.insertBook(b4);
list.insertBook(b5);

cout<<"***print the list after insert 5 books***"<<endl;
cout<<endl;
list.print();

cout<<"***print the list after delete Math book***"<<endl;
cout<<endl;
list.deleteBook(b1);
list.print();

cout<<"***print the list after delete Programming book***"<<endl;
cout<<endl;
list.deleteBook(b5);
list.print();

cout<<"***try to delete a Math book again(which is not in the list)***"<<endl;
cout<<endl;
list.deleteBook(b1);


cout<<"***Does Programming book exist in the list???***"<<endl;
cout<<endl;

 if(list.searchByTitle("Programming")){
 cout<<"yes, this book is in the list"<<endl;
 cout<<endl;}
 else 
 {cout<<"No, this book does not exist"<<endl;
 cout<<endl;}


 cout<<"***Does Physics book exist in the list???***"<<endl;
cout<<endl;

 if(list.searchByTitle("Physics"))
 {cout<<"yes, this book in the list"<<endl;
 cout<<endl;}
 else {
 cout<<"No, this book does not exist"<<endl;
 cout<<endl;}

cout<<"***Is there a book was published in 2001???***"<<endl;
cout<<endl;

if(list.searchByYear(2001))
 {cout<<"yes, the book in the list"<<endl;
 cout<<endl;}
 else {
 cout<<"No, the book does not exist"<<endl;
cout<<endl;}

cout<<"***Is there a book was published in 2010???***"<<endl;
cout<<endl;
if(list.searchByYear(2010))
 {cout<<"yes, the book in the list"<<endl;
 cout<<endl;}
 else {
 cout<<"No, the book does not exist"<<endl;
cout<<endl;}

list.insertBook(b1);
list.insertBook(b2);
list.insertBook(b3);
list.insertBook(b4);
list.insertBook(b5);
cout<<"***print the list after insert another 5 books***"<<endl;
cout<<endl;
list.print();

cout<<"***how many books are checked out???***"<<endl;
cout<<endl;
if(list.countCheckOut()==0)
 {cout<<"there is no checked out books"<<endl;
 cout<<endl;}
 else {
 cout<<"there are "<<list.countCheckOut()<<" book(s) are checked out"<<endl;
 cout<<endl;}

 list.checkBookOut("Biology");
 list.checkBookOut("Physics");
 list.checkBookOut("Programming");
 list.checkBookOut("Math");

 cout<<"***print the list after 4 books was checked out***"<<endl;
 cout<<endl;
 list.print();

 cout<<"***how many books are checked out???***"<<endl;
cout<<endl;
if(list.countCheckOut()==0)
 {cout<<"there is no checked out books"<<endl;
 cout<<endl;}
 else {
 cout<<"there are "<<list.countCheckOut()<<" book(s) are checked out"<<endl;
 cout<<endl;}

cout<<"***how many copies of Physics???***"<<endl;
cout<<endl;
if(list.countCopies(b4)==0){
 cout<<"there is no copies of this book"<<endl;
 cout<<endl;}
 else {
 cout<<"there are "<<list.countCopies(b4)<<" copy(s) of this book"<<endl; 
 cout<<endl;}

 cout<<"***how many copies of Math???***"<<endl;
cout<<endl;
if(list.countCopies(b1)==0){
 cout<<"there is no copies of this book"<<endl;
 cout<<endl;}
 else {
 cout<<"there are "<<list.countCopies(b1)<<" copy(s) of this book"<<endl; 
 cout<<endl;}
 
 list.deleteBook(b1);

 cout<<"***how many copies of Math??? (after delete all copies)***"<<endl;
cout<<endl;
if(list.countCopies(b1)==0){
 cout<<"there is no copies of this book"<<endl;
 cout<<endl;}
 else {
 cout<<"there are "<<list.countCopies(b1)<<" copy(s) of this book"<<endl; 
 cout<<endl;}

list.returnBook("Biology");
list.returnBook("Programming");

cout<<"***print the list after return 2 books ***"<<endl;
cout<<endl;
list.print();
cout<<"***how many books in the list???***"<<endl;
cout<<endl;
cout<<"there are "<<list.length()<<" book(s)"<<endl;


}