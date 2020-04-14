#include "studentlist.h"
#include "iostream"
#include "QDebug"
using std::swap;
bool compareLastName_Less(const Student& a,const Student& b)
{
    return a.getLastName()<b.getLastName();
}
bool compareLastName_Bigger(const Student& a,const Student& b)
{
    return a.getLastName()>b.getLastName();
}
bool compareAverage_Less(const Student& a, const Student& b)
{
    double averageA=0, averageB=0;
    for(int i=0; i<NUMOFMARKS; ++i)
    {
        averageA+=a.getMark(i);
        averageB+=b.getMark(i);
    }
    averageA/=NUMOFMARKS;
    averageB/=NUMOFMARKS;
    return averageA<averageB;
}
bool compareAverage_Bigger(const Student& a, const Student& b)
{
    double averageA=0, averageB=0;
    for(int i=0; i<NUMOFMARKS; ++i)
    {
        averageA+=a.getMark(i);
        averageB+=b.getMark(i);
    }
    averageA/=NUMOFMARKS;
    averageB/=NUMOFMARKS;
    return averageA>averageB;
}
bool Student::marksEmpty()const
{
    if(!marks)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Student::Student()
{
    lastName="";
    firstName="";
    marks=nullptr;
}


Student::Student(const QString& LastName, const QString& FirstName)
{
    lastName=LastName;
    firstName=FirstName;
    marks=nullptr;
}
Student::Student(const Student& old)
{
    lastName=old.lastName;
    firstName=old.firstName;
    if(old.marksEmpty())
    {
        marks=nullptr;
        return;
    }
    marks= new int [NUMOFMARKS];
    for(int i=0; i<NUMOFMARKS;++i)
    {
        marks[i]=old.marks[i];
    }
}
Student::~Student()
{
    delete [] marks;
}
void Student::operator=(const Student& old)
{
    if(!marksEmpty())
    {
        delete [] marks;
        marks=nullptr;
    }
    lastName=old.lastName;
    firstName=old.firstName;
    if(old.marksEmpty())
    {
        marks=nullptr;
        return;
    }
    marks= new int [NUMOFMARKS];
    for(int i=0; i<NUMOFMARKS;++i)
    {
        marks[i]=old.marks[i];
    }
}
void Student::setMark(const int index, const int x)
{
    if(index>=NUMOFMARKS)
    {
        return;
    }
    if(marksEmpty())
    {
        marks= new int[NUMOFMARKS];
    }
    marks[index]=x;
}
int Student::getMark(const int index)const
{
    if(marksEmpty()||index>=NUMOFMARKS)
    {
        return -1;
    }
    return marks[index];
}
const QString& Student::getLastName()const
{
    return lastName;
}
const QString& Student::getFirstName()const
{
    return firstName;
}
void  Student::setLastName(const QString& LastName)
{
    lastName=LastName;
}
void  Student::setFirstName(const QString& FirstName)
{
    firstName=FirstName;
}
void Student::readFromFile(QList<Student> &list, QTextStream &in)
{
    if(in.atEnd())
    {
        return;
    }
    in.setCodec("UTF-8");
    QString content = in.readAll();
    // extract words
    QStringList contentSplitedOnWords = content.split(" ");
    Student tmp;
    while(1)
    {
        if(contentSplitedOnWords.isEmpty())
        {
            break;
        }
        tmp.setLastName(contentSplitedOnWords.at(0));
        contentSplitedOnWords.removeAt(0);
        if(contentSplitedOnWords.isEmpty())
        {
            break;
        }
        tmp.setFirstName(contentSplitedOnWords.at(0));
        contentSplitedOnWords.removeAt(0);
        if(contentSplitedOnWords.isEmpty())
        {
            break;
        }
        for(int i=0; i<NUMOFMARKS;++i)
        {
            tmp.setMark(i,contentSplitedOnWords.at(0).toInt());
            contentSplitedOnWords.removeAt(0);
            if(contentSplitedOnWords.isEmpty())
            {
                break;
            }
        }
        list.append(tmp);
    }
}
bool Student::isExcellentStudent()const
{
    if(marksEmpty())
    {
        return false;
    }
    double sum=0;
    for(int i=0; i<NUMOFMARKS;++i)
    {
        sum+=marks[i];
    }
    if(sum/NUMOFMARKS==5)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Student::operator==(const Student& obj)const
{
    bool res=true;
    if(lastName==obj.lastName&&firstName==obj.firstName)
    {
        for(int i=0; i<NUMOFMARKS;++i)
        {
            if(marks[i]!=obj.marks[i])
            {
                res=false;
                break;
            }
        }
    }
    return res;
}











/*bool Student::compareBirth(Student &obj)
{
    if(birth[2]==obj.birth[2])
    {
        if(birth[1]==obj.birth[1])
        {
            return birth[0]<obj.birth[0];
        }
        else
        {
            return birth[1]<obj.birth[1];
        }
    }
    else
    {
        return birth[1]<obj.birth[1];
    }
}*/
