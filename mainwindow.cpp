#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int heightButton = 60;
int widthButton = 60;
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

        icons = board->returnIcons();
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

void MainWindow::blank() { //Blank is connected to the empty tiles "Ocean".
    QPushButton* clickedMe = qobject_cast<QPushButton* >(sender());
    QString imSpecial = clickedMe->text(); //Annoying bugger needs a special function to be converted.
    std::string noLongerSpecial = imSpecial.toStdString();
    //Sets label to ocean
    if(noLongerSpecial == "Ocean") {
        lastClicked = "Ocean";
    } else {
        Desktop_Icon* lastClickedIcon = findIcon(lastClicked);
        //if() Need checkIfInRange function
        size_t index = lastClickedIcon->getX()*board->getHeight()+lastClickedIcon->getY();
        connect(buttons[index], SIGNAL(released()), this, SLOT(blank())); //Set previous part to Ocean
        buttons[index]->setText("Ocean");                                 //And don't forget the name
        clickedMe->setText(QString::fromStdString(lastClickedIcon->getName())); //Change Ocean button to ship.
        //NEED TO FIND X AND Y OF THE NEW BUTTON
    }

    //When ship moves, connections do too.
    //connect(buttons[lastClicked], SIGNAL(released()), this, SLOT(ship()));
}

void MainWindow::ship() { //Ship is called when an icon is pressed
   QPushButton* clickedMe = qobject_cast<QPushButton* >(sender());
   std::string iconName = clickedMe->text().toStdString();
   if (lastClicked == "Ocean") { //If last clicked is ocean, it is selecting a ship.
       lastClicked = iconName;
       return;
   } else if (iconName == lastClicked) { //Click on it twice should deselect it.
       lastClicked = "Ocean";
       return;
   }
   Desktop_Icon* lastClickedIcon = findIcon(lastClicked);
   Desktop_Icon* thisIcon = findIcon(iconName);
   thisIcon->gotDamaged(lastClickedIcon->getWeapon());
}

//Trying to make a template function to check if move is allowable
template <typename FirstClicked, typename SecondClicked>
bool isValidMove(FirstClicked* first, SecondClicked* second) {
    int distance = abs(first->getX() - second->getX()) + abs(first->getY() - second->getY());
    if (distance < first->getRange())
        return true;
    return false;
}

//private helper function to find icon corresponding to text.
Desktop_Icon* MainWindow::findIcon(std::string s) {
    /* Previous function
    for(auto x: icons) {
        if (x->getName() == s) {
            return x;
        }
    }
    */
    //Trying to incorporate lambda and for_each.
    int index = 0;
    std::for_each(icons.begin(), icons.end(), []() {
        if (icons[n]->getName() == s) {
            return *icons.begin();
        }
        ++index;
    });
    return nullptr;
}

MainWindow::~MainWindow()
{
    delete board;
}
