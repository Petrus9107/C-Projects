#include "SubMenu.h"


//Submenu Constructor
SubMenu::SubMenu(std::string name, int position_x, int position_y, char ch)
    : m_name(name), m_position_x(position_x), m_position_y(position_y), m_ch(ch)
{
}

//Submenu Destructor
SubMenu::~SubMenu()
{
}

//Submenu Copy Constructor
SubMenu::SubMenu(const SubMenu & sub)
    :m_name(sub.m_name), m_position_x(sub.m_position_x), m_position_y(sub.m_position_y), m_ch(sub.m_ch)
{
    
}


SubMenu & SubMenu::operator =(const SubMenu & sub){
    if(this == &sub){
        return *this;
    }
        
        m_name=sub.m_name;
        m_position_x=sub.m_position_x;
        m_position_y=sub.m_position_y;
        m_ch=sub.m_ch;
        return *this;
    }
    
SubMenu & SubMenu::operator=(SubMenu && sub){
        if(this == &sub){
        return *this;
    }
        
        m_name=sub.m_name;
        m_position_x=sub.m_position_x;
        m_position_y=sub.m_position_y;
        m_ch=sub.m_ch;
        return *this;
    
    }
    



//void gotoxyz(int x, int y); //sets courson at (x,y) position


void SubMenu::display()
{   
    gotoxy(m_position_x, m_position_y);
    cout << "[" << m_ch << "] " << m_name;
    gotoxy(12,27);
    
    
}











//*******************************************************
//               Allows set cursot at (x,y) position
//*******************************************************     
void SubMenu::gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
    