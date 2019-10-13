#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QDebug>
#include <QMediaPlayer>

/*
 * flag=0 --> unoccupied
 * flag=1 --> player occupied
 * flag=2 --> computer occupied
 */

int flag_button[9]={0};
int buttonIndex[9]={2,7,6,9,5,1,4,3,8};
int gameMove=0;
int botScore=0;
int flag1=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton1,SIGNAL(released()),SLOT(push_button1()));
    connect(ui->pushButton2,SIGNAL(released()),SLOT(push_button2()));
    connect(ui->pushButton3,SIGNAL(released()),SLOT(push_button3()));
    connect(ui->pushButton4,SIGNAL(released()),SLOT(push_button4()));
    connect(ui->pushButton5,SIGNAL(released()),SLOT(push_button5()));
    connect(ui->pushButton6,SIGNAL(released()),SLOT(push_button6()));
    connect(ui->pushButton7,SIGNAL(released()),SLOT(push_button7()));
    connect(ui->pushButton8,SIGNAL(released()),SLOT(push_button8()));
    connect(ui->pushButton9,SIGNAL(released()),SLOT(push_button9()));
    connect(ui->pushButton,SIGNAL(released()),SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::win()
{
    botScore++;
    ui->lcdNumberHuman_2->display(botScore);
    for (int i=0;i<9;i++)
    {
        flag_button[i]=2;
    }
    QMediaPlayer * Moosic = new QMediaPlayer();
    Moosic->setMedia(QUrl("qrc:/moosix/go.wav"));
    Moosic->play();
}

void MainWindow::reset()
{
    for(int i=0;i<9;i++)
    {
        flag_button[i]=0;
    }
    flag1=0;
    gameMove=0;
    ui->pushButton1->setText("");
    ui->pushButton2->setText("");
    ui->pushButton3->setText("");
    ui->pushButton4->setText("");
    ui->pushButton5->setText("");
    ui->pushButton6->setText("");
    ui->pushButton7->setText("");
    ui->pushButton8->setText("");
    ui->pushButton9->setText("");
}
void MainWindow::push_button1()
{
    if (flag_button[0]==0)
    {
        gameMove++;
        ui->pushButton1->setText("X");
        flag_button[0]=1;
        MainGame(1);
    }
}
void MainWindow::push_button2()
{
    if (flag_button[1]==0)
    {
        gameMove++;
        ui->pushButton2->setText("X");
        flag_button[1]=1;
        MainGame(2);
    }
}

void MainWindow::push_button3()
{
    if (flag_button[2]==0)
    {
        gameMove++;
        ui->pushButton3->setText("X");
        flag_button[2]=1;
        MainGame(3);
    }
}

void MainWindow::push_button4()
{
    if (flag_button[3]==0)
    {
        gameMove++;
        ui->pushButton4->setText("X");
        flag_button[3]=1;
        MainGame(4);

    }
}

void MainWindow::push_button5()
{
    if (flag_button[4]==0)
    {
        gameMove++;
        ui->pushButton5->setText("X");
        flag_button[4]=1;
        MainGame(5);

    }
}

void MainWindow::push_button6()
{
    if (flag_button[5]==0)
    {
        gameMove++;
        ui->pushButton6->setText("X");
        flag_button[5]=1;
        MainGame(6);

    }
}

void MainWindow::push_button7()
{
    if (flag_button[6]==0)
    {
        gameMove++;
        ui->pushButton7->setText("X");
        flag_button[6]=1;
        MainGame(7);
    }
}

void MainWindow::push_button8()
{
    if (flag_button[7]==0)
    {
        gameMove++;
        ui->pushButton8->setText("X");
        flag_button[7]=1;
        MainGame(8);
    }
}

void MainWindow::push_button9()
{
    if (flag_button[8]==0)
    {
        gameMove++;
        ui->pushButton9->setText("X");
        flag_button[8]=1;
        MainGame(9);

    }
}

void MainWindow::MainGame(int playerMove)
{
    // Move 1
    if(gameMove==1)
    {
        if (playerMove==1||playerMove==3||playerMove==7||playerMove==9)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if(playerMove==2)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if(playerMove==4)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if(playerMove==6)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if(playerMove==8)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if(playerMove==5)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }

    }

    // Move 2
    //Player Plays Ideally
    if(gameMove==2)
    {
        int sum=0;
        for(int i=0;i<9;i++)
        {

            if(flag_button[i]==1)
            {

                sum=sum+buttonIndex[i];
            }
        }
        sum=15-sum;
        if (sum==1 && flag_button[5]==0)
        {
            ui->pushButton6->setText("O");
            flag_button[5]=2;
        }
        else if (sum==2 && flag_button[0]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if (sum==3 && flag_button[7]==0)
        {
            ui->pushButton8->setText("O");
            flag_button[7]=2;
        }
        else if (sum==4 && flag_button[6]==0)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        else if (sum==5 && flag_button[4]==0)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
        }
        else if (sum==6 && flag_button[2]==0)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
        }
        else if (sum==7 && flag_button[1]==0)
        {
            ui->pushButton2->setText("O");
            flag_button[1]=2;
        }
        else if (sum==8 && flag_button[8]==0)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        else if (sum==9 && flag_button[3]==0)
        {
            ui->pushButton4->setText("O");
            flag_button[3]=2;
        }

        // if player Doesnt Play Ideally

        else if (sum==5 && flag_button[4]==2 && flag_button[3]==0)
        {
            ui->pushButton4->setText("O");
            flag_button[3]=2;
        }
        else if(sum==5 && flag_button[3]==1 && flag_button[5]==1)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
        }
        else if (sum==2 && flag_button[0]==2 && flag_button[2]==0)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
        }
        else if (sum==6 && flag_button[2]==2 && flag_button[0]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if (sum==2 && flag_button[0]==2 && flag_button[6]==0)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        else if (sum==4 && flag_button[6]==2 && flag_button[0]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if(flag_button[8]==1 && flag_button[1]==1)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
        }

        else if(flag_button[3]==1 && flag_button[2]==1)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if(flag_button[1]==1 && flag_button[6]==1)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if (flag_button[7]==1 && flag_button[2]==1)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        else if (flag_button[7]==1 && flag_button[0]==1)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        else if (flag_button[6]==1 && flag_button[5]==1)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        else if (flag_button[0]==1 && flag_button[5]==1)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        else if (flag_button[8]==1 && flag_button[3]==1)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        else if (flag_button[1]==1 && flag_button[3]==1)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        else if (flag_button[1]==1 && flag_button[5]==1)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
        }
        else if (flag_button[7]==1 && flag_button[5]==1)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        else if (flag_button[7]==1 && flag_button[3]==1)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }

    }
    if(gameMove==3)
        // Wining Strike for BOT
    {
        int sum =0;
        for (int i=0;i<9;i++)
        {
            if (flag_button[i]==2)
            {
                sum=sum+buttonIndex[i];
            }
        }
        sum=15-sum;
        if (sum==1 && flag_button[5]==0)
        {
            ui->pushButton6->setText("O");
            flag_button[5]=2;
            MainWindow::win();
        }
        else if (sum==2 && flag_button[0]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
            MainWindow::win();
        }
        else if (sum==3 && flag_button[7]==0)
        {
            ui->pushButton8->setText("O");
            flag_button[7]=2;
            MainWindow::win();
        }
        else if (sum==4 && flag_button[6]==0)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
            MainWindow::win();
        }
        else if (sum==5 && flag_button[4]==0)
        {
            ui->pushButton5->setText("O");
            flag_button[4]=2;
            MainWindow::win();
        }
        else if (sum==6 && flag_button[2]==0)
        {
            ui->pushButton3->setText("O");
            flag_button[2]=2;
            MainWindow::win();
        }
        else if (sum==7 && flag_button[1]==0)
        {
            ui->pushButton2->setText("O");
            flag_button[1]=2;
            MainWindow::win();
        }
        else if (sum==8 && flag_button[8]==0)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
            MainWindow::win();
        }
        else if (sum==9 && flag_button[3]==0)
        {
            ui->pushButton4->setText("O");
            flag_button[3]=2;
            MainWindow::win();
        }

        // Blocking Human
        sum=0;
        for (int i=0;i<9;i++) //Main Loop for checking all entries
        {
            if (flag_button[i]==1)
            {
                for(int j=i+1;j<9;j++)
                {
                    sum=buttonIndex[i];
                    if(flag_button[j]==1)
                    {
                        sum=sum+buttonIndex[j];

                        sum=15-sum;
                        if (sum>0 && sum <10)
                        {
                            if (sum==1 && flag_button[5]==0)
                            {
                                ui->pushButton6->setText("O");
                                flag_button[5]=2;
                            }
                            else if (sum==2 && flag_button[0]==0)
                            {
                                ui->pushButton1->setText("O");
                                flag_button[0]=2;
                            }
                            else if (sum==3 && flag_button[7]==0)
                            {
                                ui->pushButton8->setText("O");
                                flag_button[7]=2;
                            }
                            else if (sum==4 && flag_button[6]==0)
                            {
                                ui->pushButton7->setText("O");
                                flag_button[6]=2;
                            }
                            else if (sum==5 && flag_button[4]==0)
                            {
                                ui->pushButton5->setText("O");
                                flag_button[4]=2;
                            }
                            else if (sum==6 && flag_button[2]==0)
                            {
                                ui->pushButton3->setText("O");
                                flag_button[2]=2;
                            }
                            else if (sum==7 && flag_button[1]==0)
                            {
                                ui->pushButton2->setText("O");
                                flag_button[1]=2;
                            }
                            else if (sum==8 && flag_button[8]==0)
                            {
                                ui->pushButton9->setText("O");
                                flag_button[8]=2;
                            }
                            else if (sum==9 && flag_button[3]==0)
                            {
                                ui->pushButton4->setText("O");
                                flag_button[3]=2;
                            }
                        }
                        sum=0;
                    }
                }
            }
        }
        if(flag_button[1]==1 && flag_button [7]==1)
        {
            if (flag_button[5]==1)
            {
                ui->pushButton7->setText("O");
                flag_button[6]=2;
            }
            if (flag_button[3]==1)
            {
                ui->pushButton9->setText("O");
                flag_button[8]=2;
            }
        }

        if (flag_button[1]==1 && flag_button[8]==1 && flag_button[3]==1) // ok
        {
            ui->pushButton6->setText("O");
            flag_button[5]=2;
        }
        if (flag_button[1]==1 && flag_button[5]==1 && flag_button[6]==1) // ok
        {
            ui->pushButton8->setText("O");
            flag_button[7]=2;
        }
        if (flag_button[0]==1 && flag_button[5]==1 && flag_button[7]==1)
        {
            ui->pushButton4->setText("O");
            flag_button[3]=2;
        }
        if (flag_button[2]==1 && flag_button[3]==1 && flag_button[7]==1)
        {
            ui->pushButton2->setText("O");
            flag_button[1]=2;
        }
        if (flag_button[2]==1 && flag_button[3]==1 && flag_button[7]==1)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        if (flag_button[0]==1 && flag_button[2]==1 && flag_button[7]==1 && flag_button[6]==0 && flag_button[8]==0)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        if (flag_button[2]==1 && flag_button[8]==1 && flag_button[3]==1 && flag_button[6]==0 && flag_button[0]==0)
        {
            ui->pushButton7->setText("O");
            flag_button[6]=2;
        }
        if (flag_button[1]==1 && flag_button[8]==1 && flag_button[6]==1 && flag_button[0]==0 && flag_button[2]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        if (flag_button[1]==1 && flag_button[8]==1 && flag_button[6]==1 && flag_button[0]==0 && flag_button[2]==0)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        if (flag_button[0]==1 && flag_button[5]==1 && flag_button[6]==1 && flag_button[8]==0 && flag_button[2]==0)
        {
            ui->pushButton9->setText("O");
            flag_button[8]=2;
        }
        // Debug 1::6::7
        if(flag_button[2]==1 && flag_button[4]==1 && flag_button[7]==1)
        {
            ui->pushButton6->setText("O");
            flag_button[5]=2;
        }
        if(flag_button[2]==1 && flag_button[4]==1 && flag_button[3]==1)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
        if(flag_button[2]==1 && flag_button[4]==1 && flag_button[3]==1)
        {
            ui->pushButton1->setText("O");
            flag_button[0]=2;
        }
    }
    if (gameMove==4)
    {
        int sum=0;
        for(int i=0;i<9;i++) // driving loop
        {
            if (flag_button[i]==2)
            {
                sum=sum+buttonIndex[i];
                for(int j=i+1;j<9;j++)
                {
                    sum=buttonIndex[i];
                    if (flag_button[j]==2)
                    {
                        sum=sum+buttonIndex[j];
                        sum=15-sum;
                        if (sum==1 && flag_button[5]==0)
                        {
                            ui->pushButton6->setText("O");
                            flag_button[5]=2;
                            MainWindow::win();
                        }
                        else if (sum==2 && flag_button[0]==0)
                        {
                            ui->pushButton1->setText("O");
                            flag_button[0]=2;
                            MainWindow::win();
                        }
                        else if (sum==3 && flag_button[7]==0)
                        {
                            ui->pushButton8->setText("O");
                            flag_button[7]=2;
                            MainWindow::win();
                        }
                        else if (sum==4 && flag_button[6]==0)
                        {
                            ui->pushButton7->setText("O");
                            flag_button[6]=2;
                            MainWindow::win();
                        }
                        else if (sum==5 && flag_button[4]==0)
                        {
                            ui->pushButton5->setText("O");
                            flag_button[4]=2;
                            MainWindow::win();
                        }
                        else if (sum==6 && flag_button[2]==0)
                        {
                            ui->pushButton3->setText("O");
                            flag_button[2]=2;
                            MainWindow::win();
                        }
                        else if (sum==7 && flag_button[1]==0)
                        {
                            ui->pushButton2->setText("O");
                            flag_button[1]=2;
                            MainWindow::win();
                        }
                        else if (sum==8 && flag_button[8]==0)
                        {
                            ui->pushButton9->setText("O");
                            flag_button[8]=2;
                            MainWindow::win();
                        }
                        else if (sum==9 && flag_button[3]==0)
                        {
                            ui->pushButton4->setText("O");
                            flag_button[3]=2;
                            MainWindow::win();
                        }
                        sum=0;
                    }

                }
            }
            sum=0;
        }
        sum=0;
        for (int i=0;i<9;i++) //Main Loop for checking all entries
        {
            if (flag_button[i]==1 && flag1==0)
            {
                for(int j=i+1;j<9;j++)
                {
                    sum=buttonIndex[i];
                    if(flag_button[j]==1)
                    {
                        sum=sum+buttonIndex[j];

                        sum=15-sum;
                        if (sum>0 && sum <10)
                        {
                            if (sum==1 && flag_button[5]==0)
                            {
                                ui->pushButton6->setText("O");
                                flag_button[5]=2;
                                flag1=1;

                            }
                            else if (sum==2 && flag_button[0]==0)
                            {
                                ui->pushButton1->setText("O");
                                flag_button[0]=2;
                                flag1=1;
                            }
                            else if (sum==3 && flag_button[7]==0)
                            {
                                ui->pushButton8->setText("O");
                                flag_button[7]=2;
                                flag1=1;

                            }
                            else if (sum==4 && flag_button[6]==0)
                            {
                                ui->pushButton7->setText("O");
                                flag_button[6]=2;
                                flag1=1;
                            }
                            else if (sum==5 && flag_button[4]==0)
                            {
                                ui->pushButton5->setText("O");
                                flag_button[4]=2;
                                flag1=1;
                            }
                            else if (sum==6 && flag_button[2]==0)
                            {
                                ui->pushButton3->setText("O");
                                flag_button[2]=2;
                                flag1=1;
                            }
                            else if (sum==7 && flag_button[1]==0)
                            {
                                ui->pushButton2->setText("O");
                                flag_button[1]=2;
                                flag1=1;
                            }
                            else if (sum==8 && flag_button[8]==0)
                            {
                                ui->pushButton9->setText("O");
                                flag_button[8]=2;
                                flag1=1;
                            }
                            else if (sum==9 && flag_button[3]==0)
                            {
                                ui->pushButton4->setText("O");
                                flag_button[3]=2;
                                flag1=1;
                            }
                        }
                        sum=0;
                    }
                }
            }

        }
        for (int i=0;i<9;i++)
        {
            if (flag_button[i]==0 && flag1==0)
            {
                if (i==0)
                {
                    ui->pushButton1->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==1)
                {
                    ui->pushButton2->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==2)
                {
                    ui->pushButton3->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==3)
                {
                    ui->pushButton4->setText("O");
                    flag_button[i]=2;
                    qDebug() << "pressed 3";
                    break;
                }
                if (i==4)
                {
                    ui->pushButton5->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==5)
                {
                    ui->pushButton6->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==6)
                {
                    ui->pushButton7->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==7)
                {
                    ui->pushButton8->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==8)
                {
                    ui->pushButton9->setText("O");
                    flag_button[i]=2;
                    break;
                }
            }
        }
        if (flag_button[0]==1 && flag_button[2]==1 && flag_button[4]==1 && flag_button[7]==1)
        {
            ui->pushButton4->setText("O");
            flag_button[3]=2;
        }
        if (flag_button[2]==1 && flag_button[3]==1 && flag_button[4]==1 && flag_button[8]==1)
        {
            ui->pushButton2->setText("O");
            flag_button[1]=2;
        }
    }
    if (gameMove==5)
    {
        for(int i=0;i<9;i++)
        {
            if (flag_button[i]==0 && flag1==0)
            {
                if (i==0)
                {
                    ui->pushButton1->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==1)
                {
                    ui->pushButton2->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==2)
                {
                    ui->pushButton3->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==3)
                {
                    ui->pushButton4->setText("O");
                    flag_button[i]=2;
                    qDebug() << "pressed 3";
                    break;
                }
                if (i==4)
                {
                    ui->pushButton5->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==5)
                {
                    ui->pushButton6->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==6)
                {
                    ui->pushButton7->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==7)
                {
                    ui->pushButton8->setText("O");
                    flag_button[i]=2;
                    break;
                }
                if (i==8)
                {
                    ui->pushButton9->setText("O");
                    flag_button[i]=2;
                    break;
                }
            }
        }
    }
}






