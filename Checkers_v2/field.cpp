#include "field.h"



Field::Field(int posX, int posY, int pointX, int pointY, int color) : m_posX(posX), m_posY(posY), m_pointX(pointX), m_pointY(pointY),
    m_color(color)

{
    QPixmap brownMap (":/img/Images/Brown.png");
    QBrush brownField (brownMap);

    QPixmap blueMap (":/img/Images/BLUE.png");
    QBrush blueField (blueMap);

    QPen blackPen (Qt::black);

    if(m_color==1){
        point = new QPoint(m_pointX, m_pointY);
        setRect(m_posX,m_posY,80,80);
        this->setBrush(brownField);
        this->setPen(blackPen);
    }

    else if(m_color==0){
        point = new QPoint(m_pointX, m_pointY);
        setRect(m_posX,m_posY,80,80);
        this->setBrush(blueField);
        this->setPen(blackPen);
    }

}





void Field::move()
{
    player=(player==0)?1:0;
    emit sygnal(player);
    currentPawn->setPos(m_posX - currentPawn->get_posX() +10, m_posY - currentPawn->get_posY()+10);
    currentPawn->set_pointX(point->rx());
    currentPawn->set_pointY(point->ry());
    currentPawn = nullptr;
    isPop = false;


}



void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    //move black
    if(event->buttons()== Qt::LeftButton && isPop==true && player==1) {
         if(this->get_color()==1 &&
                 (abs(this->point->rx()-currentPawn->get_pointX()) ==1)
                        && (abs(this->point->ry() - currentPawn->get_pointY()))==1 && currentPawn->get_status()==1){
            this->move();


    }

    //Bicie black
         else if(this->get_color()==1 &&
                 (abs(this->point->rx()-currentPawn->get_pointX()) == 2) && (abs(this->point->ry() - currentPawn->get_pointY()))==2
                 && currentPawn->get_status()==1)
          {
              int i=0;
              for (auto &s:pionki){
                  i++;
                     if(s->get_pointX() == (this->m_pointX + currentPawn->get_pointX())/2 &&
                             s->get_pointY() == (this->m_pointY + currentPawn->get_pointY())/2 && currentPawn->get_status()!=s->get_status()){
                                 qDebug() << "I: " << i;
                                 scene()->removeItem(s);
                                 qDebug() <<"Pionek: "<< pionki.at(i-1)->get_pointX() <<" , " << pionki.at(i-1)->get_pointY();
                                 currentPawn->set_pointX(this->point->rx());
                                 currentPawn->set_pointY(this->point->ry());
                                 currentPawn->setPos(this->m_posX - currentPawn->get_posX() +10, this->m_posY - currentPawn->get_posY()+10);
                                 pionki.erase(pionki.begin()+i-1);
                                 player=(player==0)?1:0;
                                 emit sygnal(player);
                     }
              }
              currentPawn= nullptr;
              isPop=false;

}
         else{
             currentPawn= nullptr;
             isPop=false;
         }
}



// move white
    else if (event->buttons()== Qt::LeftButton && isPop==true && player==0){
            if(this->get_color()==1 &&
                    (abs(this->point->rx()-currentPawn->get_pointX()) ==1)
                           && (abs(this->point->ry() - currentPawn->get_pointY()))==1 && currentPawn->get_status()==0){
               this->move();

        }



        else if(this->get_color()==1 &&
                (abs(this->point->rx()-currentPawn->get_pointX()) == 2) && (abs(this->point->ry() - currentPawn->get_pointY()))==2
                && currentPawn->get_status()==0)
         {
             int i=0;
             for (auto &s:pionki){
                 i++;
                    if(s->get_pointX() == (this->m_pointX + currentPawn->get_pointX())/2 &&
                            s->get_pointY() == (this->m_pointY + currentPawn->get_pointY())/2 && currentPawn->get_status()!=s->get_status()){
                                qDebug() << "I: " << i;
                                scene()->removeItem(s);
                                qDebug() <<"Pionek: "<< pionki.at(i-1)->get_pointX() <<" , " << pionki.at(i-1)->get_pointY();
                                currentPawn->set_pointX(this->point->rx());
                                currentPawn->set_pointY(this->point->ry());
                                currentPawn->setPos(this->m_posX - currentPawn->get_posX() +10, this->m_posY - currentPawn->get_posY()+10);
                                pionki.erase(pionki.begin()+i-1);
                                player=(player==0)?1:0;
                                emit sygnal(player);

                    }
             }
             currentPawn= nullptr;
             isPop=false;
         }

        else{
            currentPawn= nullptr;
            isPop=false;
        }


}


// sprawdzenie wygranej
    if(std::all_of(pionki.begin(), pionki.end(), [](Pawn * p){return p->get_status()==1;})){
            qDebug() <<"WYGRALES CZAFNE GIERE";

    }
    else if(std::all_of(pionki.begin(), pionki.end(), [](Pawn * p){return p->get_status()==0;})){
        qDebug() <<"WYGRALES BIALE GIERE";
    }


}











