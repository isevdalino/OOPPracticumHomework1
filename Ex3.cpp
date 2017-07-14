#include <iostream>
#include <cstring>
using namespace std;
class Student{
  char* name;
  double avarageGrades;
  int facultyNumber;
  public:
  Student(){
    name=new char[2];
    strcpy(this->name," ");
    this->avarageGrades=2.00;
    this->facultyNumber=00000;
  }
  Student(char * name,double avarageGrades,int facultyNumber){
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->avarageGrades=avarageGrades;
    this->facultyNumber=facultyNumber;
  }
  Student(const Student& student1){
    this->name=new char[strlen(student1.name)+1];
    strcpy(this->name,student1.name);
    this->avarageGrades=student1.avarageGrades;
    this->facultyNumber=student1.facultyNumber;
  }
  Student& operator=(const Student& student1){
    if(this!=&student1){
    delete this->name;
    this->name=new char[strlen(student1.name)+1];
    strcpy(this->name,student1.name);
    this->avarageGrades=student1.avarageGrades;
    this->facultyNumber=student1.facultyNumber;
    }
    return *this;
  }
  ~Student(){
     delete [] name;
  }
  void setName(char * name){
    delete this->name;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
  }
  void setAvarageGrades(double avarageGrades){
    this->avarageGrades=avarageGrades;
  }
  void setFacultyNumber(int facultyNumber){
    this->facultyNumber=facultyNumber;
  }
  char* getName(){
    return name;
  }
  double getAvarageGrades(){
    return avarageGrades;
  }
  int getFacultyNumber(){
    return facultyNumber;
  }
  void printStudentInformation(){
    cout<<"Name:"<<name<<endl<<"Avarage grades:"<<avarageGrades<<endl<<"Faculty number:"<<facultyNumber<<endl;
  }
};
class University{
  Student* students;
  int size;
  public:
  University(){
  size=0;
  students=new Student[1];
  }
  University(const University& university){
  size=university.size;
  students=new Student[size];
  for(int i=0;i<this->size;i++){
      students[i]=university.students[i];
  }
  }University& operator=(const University& university){
    if(this!=&university){
    size=university.size;
    students=new Student[size];
    for(int i=0;i<this->size;i++){
      students[i]=university.students[i];
    }
   }
   return *this;
  }
  ~University(){
    delete [] students;
  }
  void addStudent(char * name,double avarageGrades,int facultyNumber){
    Student * swapper;
    Student * students=new Student[this->size+1];
    for(int i=0;i<this->size;i++){
      students[i]=this->students[i];
    }
    students[this->size].setName(name);
    students[this->size].setAvarageGrades(avarageGrades);
    students[this->size].setFacultyNumber(facultyNumber);
    swapper=this->students;
    this->students=students;
    delete [] swapper;
    this->size=this->size+1;
  }
  void addStudent(Student student){
    Student * swapper;
    Student * students=new Student[this->size+1];
    for(int i=0;i<this->size;i++){
      students[i]=this->students[i];
    }
    students[this->size]=student;
    swapper=this->students;
    this->students=students;
    delete [] swapper;
    this->size=this->size+1;
  }
  void removeStudent(int facultyNumber){
    Student * swapper;
    Student * students=new Student[this->size-1];
    int j=0;
    for(int i=0;i<this->size-1;i++,j++){
      if((this->students[i].getFacultyNumber())==facultyNumber){
        j++;
      }
      students[i]=this->students[j];
    }
    swapper=this->students;
    this->students=students;
    delete [] swapper;
    this->size=this->size-1;
  }
  Student& getStudent(int facultyNumber){
    for(int i=0;i<this->size;i++){
      if((this->students[i].getFacultyNumber())==facultyNumber){
        return this->students[i];
      }
    }
  }
  void printStudentsInformation(){
     for(int i=0;i<this->size;i++){
      cout<<i+1<<"."<<"Name:"<<this->students[i].getName()<<endl<<"Avarage grades:"<<this->students[i].getAvarageGrades()<<endl<<"Faculty number:"<<this->students[i].getFacultyNumber()<<endl;
    }
  }
    void sortStudents(char* regime=" "){
      Student swapper;
      int (*f)(int,int);
      if(strcmp(regime,"by name")==0){
        int maxIndex;
      for(int i=0;i<this->size-1;i++){
        maxIndex=i;
        for(int j=i+1;j<this->size;j++){
        if(compareNames(j,maxIndex)){
          maxIndex=j;
        }

        }
      swapper=students[i];
      students[i]=students[maxIndex];
      students[maxIndex]=swapper;

      }
    }else{
        int maxIndex;
      for(int i=0;i<this->size-1;i++){
        maxIndex=i;
        for(int j=i;j<this->size;j++){
        if(compareFacultyNumbers(j,maxIndex)){
          maxIndex=j;
        }

        }
      swapper=students[i];
      students[i]=students[maxIndex];
      students[maxIndex]=swapper;

      }
      }



    }
    int compareNames(int i,int j){
      if(strcmp(students[i].getName(),students[j].getName())<0){
      return 1;
      }else{
      return 0;
    }
}
  int compareFacultyNumbers(int i,int j){
    if(students[i].getFacultyNumber()<students[j].getFacultyNumber()){
    return 1;
    }else{
    return 0;
    }
  }
};

int main()
{
    University fmi;
    University fmi2;
    Student student;
    student.setFacultyNumber(85326);
    student.setAvarageGrades(5.25);
    student.setName("B");
    fmi.addStudent("Ivan Sevdalinov Ivanov",4.75,81322);
    fmi.addStudent("A",6.00,62354);
    fmi.addStudent(student);
    cout<<"Printing the students information"<<endl;
    fmi.printStudentsInformation();
    fmi.sortStudents();
    cout<<endl;
    cout<<"Printing the students information sorted by faculty number"<<endl;
    fmi.printStudentsInformation();
    fmi.sortStudents("by name");
    cout<<endl;
    cout<<"Printing the students information sorted by names"<<endl;
    fmi.printStudentsInformation();
    fmi.removeStudent(81322);
    cout<<endl;
    cout<<"Printing the students information after removing student with faculty number\n81322 from the list"<<endl;
    fmi.printStudentsInformation();
    cout<<endl;
    cout<<"Assigning object of type university to another object of type university\nand then printing it on the screen"<<endl;
    fmi2=fmi;
    fmi2.printStudentsInformation();
    fmi.addStudent("Ivan Sevdalinov Ivanov",4.75,81322);
    cout<<endl;
    cout<<"Using the get student method to access information about student with\nfaculty number 81322"<<endl;
    fmi.getStudent(81322).printStudentInformation();
    return 0;
}

