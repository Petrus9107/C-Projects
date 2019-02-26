#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include <iostream>
#include "Gotoxy.h"

using std::cout;
using std::cin;
using std::endl;


class TextField : public Gotoxy
{
private:
    std::string m_text_name;
    int m_position_x;
    int m_position_y;
public:
    TextField(std::string text_name = " ", int position_x = 40, int position_y = 5);
    ~TextField();
    
    virtual void gotoxy(int x, int y);
    void display(); //displaying TetField Item
    void set_text(char * text);
    void set_text(std::string & text);
    

};

#endif // TEXTFIELD_H
