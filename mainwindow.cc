#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    min1 = min2 = 0;
    max1 = max2 = 100;
    alumns = 0;
    cost = minHours = expen = goalToPay = perPos = perNeg = 0.0f;
    ui->setupUi(this);
}

void MainWindow::allEmit()
{
    double all =double(alumns)*cost - expen;
    double ben, pay;
    if (all < goalToPay) {
        ben = (1.0f - perNeg)*all;
        pay = perNeg*all;
    }
    else {
        double excedentes = all - goalToPay;
        ben = (1.0f - perPos)*excedentes;
        pay = perPos*excedentes + goalToPay;
    }
    double payH = pay/minHours;
    if (minHours == 0) payH = 0;
    if (pay == 0) payH = 0;
    emit total(all);
    emit benefits(ben);
    emit payout(pay);
    emit costHours(payH);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::min_slice_1(int min)
{
    min1 = min;
    emit slice1(min1,max1);
}

void MainWindow::max_slice_1(int max)
{
    max1 = max;
    emit slice1(min1,max1);
}

void MainWindow::min_slice_2(int min)
{
    min2 = min;
    emit slice2(min2,max2);
}

void MainWindow::max_slice_2(int max)
{
    max2 = max;
    emit slice2(min2,max2);
}

void MainWindow::qtty_alums(int qtty)
{
    alumns = qtty;
    allEmit();
}

void MainWindow::price(double p)
{
    cost = p;
    allEmit();
}

void MainWindow::minPay(double p)
{
    goalToPay = p;
    allEmit();
}

void MainWindow::hours(double h)
{
    minHours = h;
    allEmit();
}

void MainWindow::porNegative(int p) {
    perNeg = double (p)/100.0f;
    allEmit();
}

void MainWindow::porPositive(int p) {
    perPos = double (p)/100.0f;
    allEmit();
}

void MainWindow::expenses(double c) {
    expen = c;
    allEmit();
}
