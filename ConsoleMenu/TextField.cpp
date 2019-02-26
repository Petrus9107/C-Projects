#include "TextField.h"

TextField::TextField(std::string text_name, int position_x, int position_y)
    : m_text_name(text_name), m_position_x(position_x), m_position_y(position_y)
{
}

TextField::~TextField()
{
}


void TextField::display()
{
    gotoxy(m_position_x, m_position_y);
    cout << m_text_name;
    gotoxy(10,23);
}


void TextField::gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    
}



void TextField::set_text(char * text){
    m_text_name=text;
    
    }
    
void TextField::set_text(std::string & text){
    m_text_name=text;
    }