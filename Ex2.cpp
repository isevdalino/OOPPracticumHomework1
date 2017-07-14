#include <iostream>
#include <cstring>
using namespace std;
struct Reader{
  char name[100];
  char familyName[100];
  int readerCN;
  Reader(char* name,char* familyName,int teaderCN){
    strcpy(this->name,name);
    strcpy(this->familyName,familyName);
    this->readerCN=readerCN;
  }
  Reader(){
    strcpy(this->name,"");
    strcpy(this->familyName,"");
    this->readerCN=0;
  }
  Reader(const Reader& reader){
    strcpy(name,reader.name);
    strcpy(familyName,reader.familyName);
    readerCN=reader.readerCN;
  }
  void operator=(const Reader& reader){
    strcpy(name,reader.name);
    strcpy(familyName,reader.familyName);
    readerCN=reader.readerCN;
  }
};
struct Book{
  Reader takenBy;
  bool isTaken;
  int libraryNum;
  char title[100];
  char author[100];
  Book(char* title,char* author,int libraryNum){
    isTaken=false;
    strcpy(this->title,title);
    strcpy(this->author,author);
    this->libraryNum=libraryNum;
  }
  Book(){
    isTaken=false;
    strcpy(this->title,"");
    strcpy(this->author,"");
    this->libraryNum=0;
  }
  void changeBookStatus(char * status){
    if(strcmp(status,"taken")==0){
      if(isTaken){
        cout<<"The book is already taken"<<endl;
        return;
      }
      isTaken=true;
      cout<<"Who is the book taken by?"<<endl;
      cin>>takenBy.name;
      cin>>takenBy.familyName;
      cout<<"What is his reader card number?"<<endl;
      cin>>takenBy.readerCN;
    }else if(strcmp(status,"untaken")==0){
      isTaken=false;
      strcpy(takenBy.name,"");
      strcpy(takenBy.familyName,"");
      takenBy.readerCN=0;
    }
  }
  void operator=(Book book){
    strcpy(title,book.title);
    strcpy(author,book.author);
    libraryNum=book.libraryNum;
    isTaken=book.isTaken;
    takenBy=book.takenBy;
  }
  Book(const Book& book){
    strcpy(title,book.title);
    strcpy(author,book.author);
    libraryNum=book.libraryNum;
    isTaken=book.isTaken;
    takenBy=book.takenBy;
  }
  friend class Library;
};
class Library{
  Reader* readers;
  int readersCount;
  int booksCount;
  int readersCapacity;
  int booksCapacity;
  public:
  Book* books;
  Library(int readersCapacity,int booksCapacity){
    this->readersCapacity=readersCapacity;
    this->booksCapacity=booksCapacity;
    readers=NULL;
    readersCount=0;
    books=NULL;
    booksCount=0;
  }
  void printBooks(){
    for(int i=0;i<booksCount;i++){
      cout<<books[i].title<<","<<books[i].author<<",LN "<<books[i].libraryNum<<endl;
    }
  }
  void printReaders(){
    for(int i=0;i<readersCount;i++){
      cout<<readers[i].name<<","<<readers[i].familyName<<",LN "<<readers[i].readerCN<<endl;
    }
  }
  void addReader(char * name,char * familyName,int readerCn){
    if((this->readersCount+1)>readersCapacity){
        return;
    }
    Reader* swapper;
    Reader* readers=new Reader[this->readersCount+1];
    for(int i=0;i<this->readersCount;i++){
      readers[i]=this->readers[i];
    }
    strcpy(readers[this->readersCount].name,name);
    strcpy(readers[this->readersCount].familyName,familyName);
    readers[this->readersCount].readerCN=readerCn;
    swapper=this->readers;
    this->readers=readers;
    delete [] swapper;
    this->readersCount=this->readersCount+1;
  }
  void addReader(Reader reader1){
    if((this->readersCount+1)>readersCapacity){
        return;
    }
    Reader* swapper;
    Reader* readers=new Reader[this->readersCount+1];
    for(int i=0;i<this->readersCount;i++){
      readers[i]=this->readers[i];
    }
    strcpy(readers[this->readersCount].name,reader1.name);
    strcpy(readers[this->readersCount].familyName,reader1.familyName);
    readers[this->readersCount].readerCN=reader1.readerCN;
    swapper=this->readers;
    this->readers=readers;
    delete [] swapper;
    this->readersCount=this->readersCount+1;
  }
  void addBook(char * title,char * author,int libraryNum){
    if((this->booksCount+1)>booksCapacity){
        return;
    }
    Book* swapper;
    Book* books=new Book[this->booksCount+1];
    for(int i=0;i<this->booksCount;i++){
      books[i]=this->books[i];
    }
    strcpy(books[this->booksCount].title,title);
    strcpy(books[this->booksCount].author,author);
    books[this->booksCount].libraryNum=libraryNum;
    swapper=this->books;
    this->books=books;
    delete [] swapper;
    this->booksCount=this->booksCount+1;
  }
  void addBook(Book book1){
    if((this->booksCount+1)>booksCapacity){
        return;
    }
    Book* swapper;
    Book* books=new Book[this->booksCount+1];
    for(int i=0;i<this->booksCount;i++){
      books[i]=this->books[i];
    }
    strcpy(books[this->booksCount].title,book1.title);
    strcpy(books[this->booksCount].author,book1.author);
    books[this->booksCount].libraryNum=book1.libraryNum;
    swapper=this->books;
    this->books=books;
    delete [] swapper;
    this->booksCount=this->booksCount+1;
  }
  void removeBook(int libraryNum){
    Book * swapper;
    Book * books=new Book[this->booksCount-1];
    int j=0;
    for(int i=0;i<this->booksCount-1;i++,j++){
      if((this->books[i].libraryNum)==libraryNum){
        j++;
      }
      books[i]=this->books[j];
    }
    swapper=this->books;
    this->books=books;
    delete [] swapper;
    this->booksCount=this->booksCount-1;
  }
     void sortBooks(){
      Book swapper;
      int maxIndex;
      for(int i=0;i<booksCount-1;i++){
        maxIndex=i;
        for(int j=i+1;j<booksCount;j++){
        if(strcmp(books[j].title,books[maxIndex].title)<0){
          maxIndex=j;
        }
        }
      swapper=books[i];
      books[i]=books[maxIndex];
      books[maxIndex]=swapper;

      }
    }
  void takeOrReturnBook(char* operation,int libraryNum){
    char nameP[100];
    char familyNameP[100];
    int readerCNP;
    bool isThereSuchAPerson=false;
    if(strcmp(operation,"take")==0){
      for(int i=0;i<this->booksCount;i++){
        if(books[i].libraryNum==libraryNum){
          if(books[i].isTaken){
           cout<<"The book is already taken"<<endl;
           return;
          }
          books[i].isTaken=true;
          cout<<"Who is the book taken by?"<<endl;
          cin>>nameP;
          cin>>familyNameP;
          cout<<"What is his reader card number?"<<endl;
          cin>>readerCNP;
          for(int i=0;i<readersCount;i++){
            if(((strcmp(readers[i].name,nameP)==0)&&(strcmp(readers[i].familyName,familyNameP)==0))&&(readerCNP==readers[i].readerCN)){
              isThereSuchAPerson=true;
              break;
            }
          }
          if(isThereSuchAPerson==false){
            cout<<"There is no such a person in the library list."<<endl;
            return;
          }
          strcpy(books[i].takenBy.name,nameP);
          strcpy(books[i].takenBy.familyName,familyNameP);
          books[i].takenBy.readerCN=readerCNP;
          break;
        }
      }
    }else if(strcmp(operation,"return")==0){
      for(int i=0;i<this->booksCount;i++){
        if(books[i].libraryNum==libraryNum){
          books[i].isTaken=false;
          strcpy(books[i].takenBy.name,"");
          strcpy(books[i].takenBy.familyName,"");
          books[i].takenBy.readerCN=0;
          return;
        }
      }
    }
  }
  friend void findBookTaken(Reader reader,Library& library);
  friend void findBookTaken(char* name,char* familyName,Library& library);
  friend bool isThereAFreeCopy(Book book,Library& library);
  friend bool isThereAFreeCopy(char* title,Library& library);
};
 void findBookTaken(Reader reader,Library& library){
  for(int i=0;i<library.booksCount;i++){
    if(library.books[i].isTaken){
    if(strcmp(reader.name,library.books[i].takenBy.name)==0){
      cout<<reader.name<<" "<<reader.familyName<<" borrowed "<< library.books[i].title<<endl;
      return;
    }
    }
  }
  cout<<reader.name<<" "<<reader.familyName<<" has borrowed no books from this library."<<endl;
}
void findBookTaken(char* name,char* familyName,Library& library){
for(int i=0;i<library.booksCount;i++){
    if(library.books[i].isTaken){
      if((strcmp(name,library.books[i].takenBy.name)==0)&&(strcmp(familyName,library.books[i].takenBy.familyName)==0)){
        cout<<name<<" "<<familyName<<" borrowed "<< library.books[i].title<<endl;
        return;
      }
    }
  }
  cout<<name<<" "<<familyName<<" has borrowed no books from this library."<<endl;
}
bool isThereAFreeCopy(Book book,Library& library){
for(int i=0;i<library.booksCount;i++){
    if(strcmp(book.title,library.books[i].title)==0){
        if((library.books[i].isTaken)==false){
        return true;
      }
    }
  }
  return false;
}
bool isThereAFreeCopy(char* title,Library& library){
for(int i=0;i<library.booksCount;i++){
    if(strcmp(title,library.books[i].title)==0){
      if((library.books[i].isTaken)==false){
        return true;
      }
    }
  }
  return false;
}
int main()
{
    Library library(5,5);
    Reader reader;
    Book book;
    strcpy(book.title,"Crash of kings");
    strcpy(book.author,"George Martin");
    book.libraryNum=2;
    strcpy(reader.name,"John");
    strcpy(reader.familyName,"Shepard");
    reader.readerCN=56321;
    //Adding books and readers to the library
    library.addBook("Game of thrones","George Martin",1);
    library.addBook(book);
    library.addBook("A Storm of Swords","George Martin",3);
    library.addBook("A Feast for Crows","George Martin",4);
    library.addBook("A Dance with Dragons","George Martin",5);
    library.addReader("Ivan","Ivanov",81322);
    library.addReader("Stefan","Nikolov",61598);
    library.addReader("Maria","Dimitrova",23654);
    library.addReader("Nina","Georgieva",82387);
    library.addReader(reader);
    //Printing the lists of books and readers
    library.printBooks();
    cout<<endl;
    library.printReaders();
    cout<<endl;
    //Removing a books from the list and printing it again
    library.removeBook(1);
    library.printBooks();
    //Taking a book with library number 4(A Feast for Crows)...TIP:input Ivan-Ivanov-81322 when it asks to see futher effects
    library.takeOrReturnBook("take",4);
    //Finding what book did Ivan Ivanov took from the library
    findBookTaken("Ivan","Ivanov",library);
    cout<<endl;
    //Seeking is there a free copy of a given book in the library
    cout<<"Is there a free copy of A Feast for Crows?"<<endl;
    if(isThereAFreeCopy("A Feast for Crows",library)){
      cout<<"There is a free copy of that book"<<endl;
    }else{
      cout<<"There is no free copy of that book"<<endl;
    }
    cout<<"Is there a free copy of Game of thrones?"<<endl;
    if(isThereAFreeCopy("Game of thrones",library)){
      cout<<"There is a free copy of that book"<<endl;
    }else{
      cout<<"There is no free copy of that book"<<endl;
    }
    //Returning A Feast for Crows to the library and seeking it
    library.takeOrReturnBook("return",4);
    cout<<"Is there a free copy of A Feast for Crows now?"<<endl;
    if(isThereAFreeCopy("A Feast for Crows",library)){
      cout<<"There is a free copy of that book"<<endl;
    }else{
      cout<<"There is no free copy of that book"<<endl;
    }
    cout<<endl;
    //Sorting the books from the library and printing them again
    library.sortBooks();
    library.printBooks();
    return 0;
}


