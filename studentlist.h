#include "QTextStream"
#include "mainwindow.h"
#include "algorithm"
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QMainWindow>

#define NUMOFMARKS 7
#define MAXMARK 5
enum showExcellentStudents
{
   no,yes
};
enum sort{
    Default,ByNameLess,ByNameBigger,ByAverageLess,ByAverageBigger
};
class Student
{
private:
QString firstName;
QString lastName;
//int birth[3];
int* marks;
bool marksEmpty()const;
public:
    Student();
    Student(const QString& LastName, const QString& FirstName);
    Student(const Student& old);
    virtual ~Student();
    void operator=(const Student& old);
    void setMark(const int index, const int x);
    int getMark(const int index)const;
    const QString& getLastName()const;
    const QString& getFirstName()const;
    void setLastName(const QString& LastName);
    void setFirstName(const QString& FirstName);
   // bool compareLastName(Student* obj)const;
    //bool compareBirth(Student& obj);
   // bool compareAverage(Student* obj)const;
    void readFromFile(QList<Student>&list, QTextStream& in);
    bool isExcellentStudent()const;
    bool operator==(const Student& obj)const;


};
bool compareLastName_Less(const Student& a,const Student& b);
bool compareLastName_Bigger(const Student& a,const Student& b);
bool compareAverage_Less(const Student& a, const Student& b);
bool compareAverage_Bigger(const Student& a, const Student& b);


#endif // STUDENTLIST_H
