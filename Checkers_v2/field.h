#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include "pawn.h"
#include "currentpawn.h"
#include <QPoint>
#include <algorithm>
#include <QObject>


class Field : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    int m_posX;
    int m_posY;
    int m_pointX;
    int m_pointY;
    int m_color;
    QPoint * point;

public:
    Field(int posX, int posY, int pointX, int pointY, int color);
    int get_color(){return m_color;}
    void move();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void sygnal(int newValue);

};

#endif // FIELD_H
