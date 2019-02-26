#include <iostream>
#include "Frame.h"


//std::stack<Frame> frame_stack;
std::deque<Frame*> frame_stack;
char selection;



using std::cout;
using std::endl;




//*******************************************************
//                Frame Constructor
//*******************************************************
Frame::Frame(int width, int height, int position_x, int position_y, char line_style)
    : m_width(width), m_height(height), m_position_x(position_x), m_position_y(position_y), m_line_style(line_style)
{
    sub_vec = std::vector<SubMenu>();
    link_vec = std::vector<std::pair<SubMenu, Frame*>>();
}



Frame::~Frame()
{
}

//*******************************************************
//               Copy Frame Constructor
//*******************************************************

Frame::Frame(const Frame & fr)
    :m_width(fr.m_width), m_height(fr.m_height), m_position_x(fr.m_position_x), m_position_y(fr.m_position_y), m_line_style(fr.m_line_style),
     text_vec(fr.text_vec), sub_vec(fr.sub_vec), link_vec(fr.link_vec)
    {
    
    
    }
    

//*******************************************************
//               Overloaded Copy Assigment Operator
//*******************************************************
    

Frame & Frame::operator=(const Frame & fr){
    if(this == & fr){
        return *this;
    }
        m_width = fr.m_width;
        m_height=fr.m_height;
        m_position_x=fr.m_position_x;
        m_position_y=fr.m_position_y;
        m_line_style=fr.m_line_style;
        text_vec = std::move(fr.text_vec);
        sub_vec = std::move(fr.sub_vec);
        link_vec =std::move(fr.link_vec);
        return *this;
    
    }
    
    
//*******************************************************
//               Overloaded Move Assigment Operator
//*******************************************************


Frame & Frame::operator=(Frame && fr){
    if(this == &fr){
        return *this;
    }
        m_width = fr.m_width;
        m_height=fr.m_height;
        m_position_x=fr.m_position_x;
        m_position_y=fr.m_position_y;
        m_line_style=fr.m_line_style;
        text_vec = std::move(fr.text_vec);
        sub_vec = std::move(fr.sub_vec);
        link_vec =std::move(fr.link_vec);
        
        
        return *this;
        
    }




/////////////// PUBLIC METHODS //////////////////////////

//*******************************************************
//                Displays the Frame object
//*******************************************************
 void Frame::display_frame()
 {
    
    //FRAME
    //system("CLS");
    gotoxy(m_position_x,m_position_y);
    cout << std::setw(m_width) << std::left << std::setfill(m_line_style) << " " << endl;  //top
     for (int i{0}; i<m_height; i++)
         {
             gotoxy(m_position_x, m_position_y + i);
             cout << m_line_style ;
             gotoxy(m_position_x+m_width, m_position_y+i);
             cout << m_line_style ;
        }
    gotoxy(m_position_x-1, m_position_y + m_height);
    cout << std::setw(m_width+2) << std::left << std::setfill(m_line_style) << " " << endl;  //bottom
    //FRAME
     
     
     //SubMenu Items display
     this->display_sub_vec();
    
     //TextField Items display
     this->display_text_vec();

     
     
     //char selection
     do {
         gotoxy(15,15);
         cout << "Wybierz: ";
         gotoxy(23,15);
         cin >> selection;
         for (auto &v:link_vec)
             {
             if (v.first.get_ch() == selection)
                 {
                    system("CLS");
                    frame_stack.push_back(std::move(v.second));
                    frame_stack.back()->display_frame();
                }  
             }
             
            if (selection == 'b' || selection == 'B')
             {
                 if(frame_stack.size()>1){
                system("CLS");
                gotoxy(40,16);
                frame_stack.pop_back();
                frame_stack.back()->display_frame();
                 }
                 else
                     break;
             }
             
             else {
                 gotoxy(12,20);
                 cout << "Niezlaneziono znaku";
             }

                 
         } while (selection != 'Q ' && selection != 'q');
         cin.clear();
         
     
}

//*******************************************************
//                Adding the SubMenu Item
//*******************************************************

void Frame::add(const SubMenu & sub)
{
        sub_vec.push_back(std::move(sub));
}
    

//*******************************************************
//                Adding the TextFielditem
//*******************************************************

void Frame::add(TextField & text_item)
{
    
    text_vec.push_back(std::move(&text_item));
    
}


//*******************************************************
//     Add to Frame pair linked <menu item, Frame>
//*******************************************************

void Frame::link_to(const SubMenu & sub, Frame & f)
{
    
    link_vec.push_back(std::pair<SubMenu,Frame*>(std::move(sub),&f));

}



     
//*******************************************************
//               Allows set cursot at (x,y) position
//*******************************************************     
void Frame:: gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

//*******************************************************
//        Displaying sub_vector components
//*******************************************************     

void Frame::display_sub_vec()
{
     for (auto &s:sub_vec)
        s.display();
}


//*******************************************************
//        Displaying text_vector componentes
//*******************************************************   

void Frame::display_text_vec()
{
    for(auto t:text_vec)
        t->display();
}

   

//Friend Methods
 
    
void run( Frame & fr)
{
    frame_stack.push_back(&fr);
    frame_stack.back()->display_frame();

}
   






