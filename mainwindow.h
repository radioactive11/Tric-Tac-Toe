#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void MainGame(int);
    void win();
    void reset();
    void push_button1();
    void push_button2();
    void push_button3();
    void push_button4();
    void push_button5();
    void push_button6();
    void push_button7();
    void push_button8();
    void push_button9();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
