#ifndef FRAME_H
#define FRAME_H
#include <iomanip>
#include "Gotoxy.h"
#include <stdlib.h>
#include "SubMenu.h"
#include "TextField.h"
#include <utility>
#include <vector>
#include <stack>
#include <deque>

/* Class allows handling with console Frame objects 
 * Frame(width,height,xposition,yposition,line_style) <<creation of Frame objects, arguments specification
 * 
 */

class SubMenu;
class Frame;

//extern std::stack<Frame> frame_stack;
extern std::deque<Frame*> frame_stack;
extern char selection;


class Frame : public Gotoxy
{

friend void run(Frame & fr);


private:
    std::vector<TextField*> text_vec;
    std::vector<SubMenu> sub_vec;
    std::vector<std::pair<SubMenu, Frame*>> link_vec;
    int m_width;
    int m_height;
    int m_position_x;
    int m_position_y;
    char m_line_style;
public:
    Frame(int width = 90, int height = 20, int position_x = 10, int position_y = 3, char line_style ='#');
    ~Frame();
    Frame(const Frame & fr); //copy constructor 
    Frame & operator=(const Frame & fr);  //copy assigment operator
    Frame & operator=(Frame && fr); //copy move opearator
    

    virtual void gotoxy(int x, int y); //setting cursor at (x,y) position
    void display_frame(); //displaying frame
    void add(const SubMenu & sub); //adding the SubMenu Item to Frame
    void add(TextField & text_item); //adding the textField Item do Frame
    void link_to(const SubMenu & sub, Frame & f);  //linking submenu Item to Frame
    
    void display_sub_vec();  //displaying the sub_vector componentss
    void display_text_vec(); //displaying the text_vector componenets
   

 //temporary
    auto get_vector(){return link_vec;}
    int return_width(){return m_width;}
    
    
    
};


#endif // CONSONE_FRAME_H
