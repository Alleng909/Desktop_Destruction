#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int heightButton = 20;
int widthButton = 20;
int heightOffset = 10;
int widthOffset = 10;


MainWindow::MainWindow(GameBoard* b, QWidget *parent) : board(b), QMainWindow(parent)
{
    test = new QPushButton(QString::number(1010101), this);
    test -> setGeometry(QRect(QPoint(heightOffset+heightButton*1,
        widthOffset+widthButton*1),QSize(heightButton,widthButton)));
    for(size_t height = 0; height < board->getHeight(); height++) {
        for (size_t width = 0; width < board->getWidth(); width++) {
            int index = height*board->getWidth()+width;
            std::cout << index;
            buttons.push_back(new QPushButton(QString::number(index), this));
            buttons[index]->setGeometry(QRect(QPoint(heightOffset+heightButton*height,
                widthOffset+widthButton*width),QSize(heightButton,widthButton)));
            //connect(buttons[index], SIGNAL(released(), this, SLOT(MISSSSSSSSSSSSING));
        }
    }
}

MainWindow::~MainWindow()
{

}
