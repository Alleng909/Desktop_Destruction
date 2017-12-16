#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int heightButton = 40;
int widthButton = 40;
int heightOffset = 10;
int widthOffset = 10;


MainWindow::MainWindow(GameBoard* b, QWidget *parent) : board(b), QMainWindow(parent)
{
    try {
        for(size_t height = 0; height < board->getHeight(); height++) {
            for (size_t width = 0; width < board->getWidth(); width++) {
                int index = height*board->getWidth()+width;
                buttons.push_back(new QPushButton(QString::number(index), this));
                buttons[index]->setGeometry(QRect(QPoint(heightOffset+heightButton*height,
                    widthOffset+widthButton*width),QSize(heightButton,widthButton)));
                //connect(buttons[index], SIGNAL(released(), this, SLOT(MISSSSSSSSSSSSING));
            }
        }
    } catch(std::exception e) {
        std::cout << "Error in making window";
        throw e;
    }

}

MainWindow::~MainWindow()
{

}
