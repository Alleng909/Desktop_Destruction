#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int heightButton = 40;
int widthButton = 40;
int heightOffset = 10;
int widthOffset = 10;


MainWindow::MainWindow(GameBoard* b, QWidget *parent) : board(b), QMainWindow(parent), lastClicked("Ocean")
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

        std::vector<Desktop_Icon*> icons = board->returnIcons();
        for(auto icon : icons) {
           int index = board->getHeight()*icon->getX()+icon->getY();
           std::string nam = icon->getName();
           QString newNam = QString::fromStdString(nam);
           buttons[index]->setText(newNam);
           connect(buttons[index], SIGNAL(released()), this, SLOT(ship()));
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
    if(noLongerSpecial == "Ocean") {
        //Means Nothing
    } else {
        //Do a thing (still need to use LastClicked)
    }
    //buttons[lastClicked]->setText("Ocean");

    //When ship moves, connections do too.
    //connect(buttons[lastClicked], SIGNAL(released()), this, SLOT(ship()));
}

void MainWindow::ship() {
   //buttons[lastClicked]->setText("SHIP");
}

MainWindow::~MainWindow()
{
    delete board;
}
