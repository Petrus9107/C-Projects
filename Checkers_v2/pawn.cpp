#include "pawn.h"

Pawn::Pawn()
{

}

Pawn::Pawn(int posX, int posY, int pointX, int pointY, int status): m_posX(posX), m_posY(posY), m_pointX(pointX), m_pointY(pointY), m_status(status)
{
    QBrush whiteBursh(Qt::white);
    QBrush blackBrush(Qt::black);


    if(m_status==1){
        point = new QPoint(m_pointX, m_pointY);
        setRect(posX,posY,60,60);
        this->setBrush(blackBrush);
        this->setCursor(Qt::PointingHandCursor);
        pionki.push_back(this);

    }

    else if (m_status==0){
    point = new QPoint(m_pointX, m_pointY);
    setRect(posX,posY,60,60);
    this->setBrush(whiteBursh);
    this->setCursor(Qt::PointingHandCursor);
    pionki.push_back(this);
    }
}


void Pawn::set_pointX(int & x)
{
    point->setX(x);
}

void Pawn::set_pointY(int & y)
{
    point->setY(y);
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->buttons()== Qt::LeftButton){
        // jesli podniesionny i zaden pionek nie jest zaznaczony
        if(currentPawn == nullptr && isPop == false ){
            currentPawn=this;
            isPop=true;
        }
        //jesli podnniesiony i zaznaczony obiekt
        else if(currentPawn == this && isPop == true){
            currentPawn = nullptr;
            isPop = false;
        }
        else{
            currentPawn=nullptr;
            isPop=false;
        }




}

}


