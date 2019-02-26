#ifndef GOTOXY_H
#define GOTOXY_H
#include <windows.h>

class Gotoxy{
    public:
virtual void gotoxy(int x, int y)=0;
virtual ~Gotoxy() {};


};

#endif // GOTOXY_H
