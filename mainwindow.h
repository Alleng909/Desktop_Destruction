#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <string>
#include "desktop_icon.h";
#include "gameboard.h";


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0) {}
    //I have no clue what I'm doing, but trying to make a constructor where I can input a board.
    MainWindow(GameBoard* b, QWidget *parent = 0);
    virtual ~MainWindow();
private slots:
    void blank();
    void ship();

private:
    GameBoard* board;
    std::vector<QPushButton*> buttons;
    QLabel information;
    std::string lastClicked;
    std::vector<Desktop_Icon*> icons;

    Desktop_Icon* findIcon(std::string);
};

#endif // MAINWINDOW_H
