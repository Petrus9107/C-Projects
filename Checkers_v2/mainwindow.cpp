#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include "pawn.h"
#include "currentpawn.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bialy = QPixmap(":/Images/bialyRuch.png");
    czarny = QPixmap(":/Images/czarny.png");
    ui->label->setPixmap(bialy);

    // create scene
    QGraphicsScene *scene = new QGraphicsScene();
    // add scene to the View
    ui->graphicsView->setScene(scene);
    //set scene geometry
    scene->setSceneRect(0,0,640,640);

    //create field templates
    QPixmap brownMap (":/img/Images/Brown.png");
    QBrush brownField (brownMap);

    QPixmap blueMap (":/img/Images/BLUE.png");
    QBrush blueField (blueMap);

    QPen blackPen (Qt::black);
    QBrush whiteBursh(Qt::white);
    QBrush blackBrush(Qt::black);

    Field *pole= new Field(80,80, 1,1,1);
    scene->addItem(pole);
    //connect(pole, SIGNAL(sygnal(int)), this, SLOT(change_pic(int)));


    // create field flor
        for (int i=0; i<8; i=i+2){
            for (int j=1; j<=8; j=j+2){
                Field * field= new Field(j*80,i*80, j+1, i+1,1);
                scene->addItem(field);
                connect(field, SIGNAL(sygnal(int)), this, SLOT(change_pic(int)));
            }

        }

        for (int i=1; i<=8; i=i+2){
            for (int j=0; j<8; j=j+2){
                Field * field= new Field(j*80,i*80, j+1, i+1,1);
                scene->addItem(field);
                connect(field, SIGNAL(sygnal(int)), this, SLOT(change_pic(int)));
            }

        }

        for (int i=0; i<8; i=i+2){
            for (int j=0; j<8; j=j+2){
                Field * field= new Field(j*80,i*80, j+1 , i+1,0);
                scene->addItem(field);
            }

        }

        for (int i=1; i<=8; i=i+2){
            for (int j=1; j<=8; j=j+2){
                Field * field= new Field(j*80,i*80, j+1, i+1,0);
                scene->addItem(field);

            }

        }


      //create Pawns

        for (int i=0; i<8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,570,i+1,8,1);
            scene->addItem(pawn);

        }

        for (int i=1; i<=8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,490,i+1,7,1);
            scene->addItem(pawn);

        }

        for (int i=0; i<8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,410,i+1,6,1);
            scene->addItem(pawn);

        }

         //create Pawn object (white)

        for (int i=1; i<=8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,10,i+1,1,0);
            scene->addItem(pawn);


        }

        for (int i=0; i<8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,90,i+1,2,0);
            scene->addItem(pawn);


        }

        for (int i=1; i<=8; i=i+2 ){

            Pawn * pawn = new Pawn((i*80)+10,170,i+1,3,0);
            scene->addItem(pawn);
        }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    player=(player==0)?1:0;
    if(player==0){
          ui->label->setPixmap(bialy);
    }
    else {
       ui->label->setPixmap(czarny);
    }
}

void MainWindow::change_pic(int val)
{

    if(val==0){
          ui->label->setPixmap(bialy);
    }
    else {
       ui->label->setPixmap(czarny);
    }


}
