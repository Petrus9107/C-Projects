#ifndef SUBMENU_H
#define SUBMENU_H
#include <iostream>
#include "Gotoxy.h"
#include <string>



/* Class allows handling with console SubMenu objects 
 * SubMenu(name, posX, posY, ch - > [ch]) <<[ch] name (posX, posY)
 * 
 */

using std::cout;
using std::cin;

class SubMenu : public Gotoxy
{
private:
    std::string m_name;
    int m_position_x;
    int m_position_y;
    char m_ch;
public:
    SubMenu(std::string name = "DEFAULT", int position_x = 12, int position_y =5 , char ch = '1');
    ~SubMenu();
    SubMenu(const SubMenu & sub);
    SubMenu & operator=(const SubMenu & sub);
    SubMenu & operator=(SubMenu && sub);
    
    const char & get_ch() {return m_ch;}
    std::string get_str() {return m_name;}
    virtual void gotoxy(int x, int y);
    void display(); //displaying SubMenu Item

};

#endif // SUBMENU_H
