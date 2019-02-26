#include <iostream>
#include "Frame.h"




int main()
{
   //Frame 1
    Frame frame1;
    SubMenu I11 ("Przenies mnie do FRAME_2", 12, 6, '1');
    SubMenu I12 ("Przenies mnie do FRAME_3", 12, 7, '2');
    SubMenu I13 ("Przenies mnie do FRAME_4", 12, 8, '3');
    frame1.add(I11);
    frame1.add(I12);
    frame1.add(I13);
    TextField T11 ("Jestes w FRAME 1", 40, 4);
    frame1.add(T11);
    
    
    //Frame 2
    Frame frame2;
    SubMenu I3 ("Przenies mnie do menu 1", 12,6,'1');
    SubMenu I4 ("Przenies mnie do menu 3", 12, 7, '2');
    frame2.add(I3);
    frame2.add(I4);
    TextField T2 ("Jestes w FRAME 2", 40, 4);
    frame2.add(T2);
    T2.set_text("No co? JESTES W FRAME 2");
   
    
    
    //Frame 3
    Frame frame3;
    SubMenu I5 ("Zabierz mnie do MENU 4", 12, 6, '1');
    SubMenu I6 ("zabierz mnie do kiciusa", 12, 7, '2');
    frame3.add(I5);
    frame3.add(I6);
    TextField T3 ("Jestes w FRAME 3", 40, 4);
    frame3.add(T3);
    
    //Frame 4
    Frame frame4;
    SubMenu I7("Kuku Kuku", 12, 6, '1');
    frame4.add(I7);
    TextField T5 ("Jestes w meny 4", 40, 4);
    frame4.add(T5);
    

    frame1.link_to(I11,frame2);
    frame1.link_to(I12,frame3);
    frame1.link_to(I13,frame4);
    
    frame2.link_to(I3,frame1);
    frame2.link_to(I4,frame3);
    
    frame3.link_to(I7,frame4);
    
  
    
    
   run(frame1);



   
    
    
	return 0;
}
