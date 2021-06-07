#include "Displayable.h"
#ifndef SICT_STUDENT_H_
#define SICT_STUDENT_H_
namespace sict{

  class Student :public Displayable{
    int _stno;
    char _name[41];
    void set(int stno, const char* name);
  public:
    Student(int stno, const char* name = "no name");
    Student(const Student& S) = delete;
    Student& operator=(const Student& S) = delete;
    std::ostream& display(std::ostream& os)const;
    bool operator<=(const Student& S)const;
    bool operator>=(const Student& S)const;
    operator const char*()const;
  };
}
#endif 