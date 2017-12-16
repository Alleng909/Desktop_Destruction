#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int heightButton = 40;
int widthButton = 40;
int heightOffset = 10;
int widthOffset = 10;


MainWindow::MainWindow(GameBoard* b, QWidget *parent) : board(b), QMainWindow(parent), lastClicked(0)
{
    try {
        QString qs("Ocean");
        for(size_t height = 0; height < board->getHeight(); height++) {
            for (size_t width = 0; width < board->getWidth(); width++) {
                int index = height*board->getWidth()+width;
                buttons.push_back(new QPushButton(qs, this));
                buttons[index]->setGeometry(QRect(QPoint(heightOffset+heightButton*height,
                    widthOffset+widthButton*width),QSize(heightButton,widthButton)));
                connect(buttons[index], SIGNAL(released()), this, SLOT(blank()));
            }
        }

    } catch(std::exception e) {
        std::cout << "Error in making window";
        throw e;
    }

}

void MainWindow::blank() {
    QPushButton* clickedMe = qobject_cast<QPushButton* >(sender());
    QString imSpecial = clickedMe->text(); //Annoying bugger needs a special function to be converted.
    std::string noLongerSpecial = imSpecial.toStdString();
    //Sets label to ocean
    //if(buttons[lastClicked])
    buttons[lastClicked]->setText("Ocean");
    connect(buttons[lastClicked], SIGNAL(released()), this, SLOT(ship()));
    std::cout << noLongerSpecial;
}

void MainWindow::ship() {
   buttons[lastClicked]->setText("SHIP");
}

MainWindow::~MainWindow()
{
    delete board;
}
