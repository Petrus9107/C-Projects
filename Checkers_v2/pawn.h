#ifndef PAWN_H
#define PAWN_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QtGui>
#include <QDebug>
#include "currentpawn.h"
#include <QPoint>


class Pawn;


class Pawn : public QGraphicsEllipseItem
{


private:
    int m_posX;
    int m_posY;
    int m_pointX;
    int m_pointY;
    int m_status;    // 0 white, 1 black
    QPoint * point;

public:
    Pawn();
    Pawn(int posX,int posY, int pointX, int pointY, int status);
    int get_posX(){return m_posX;}
    int get_posY(){return m_posY;}
    int get_pointX(){return point->rx();}
    int get_pointY(){return point->ry();}
    void set_pointX(int & x);
    void set_pointY(int & y);
    int get_status(){return m_status;}


signals:
    void sign();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};
#endif // PAWN_H



