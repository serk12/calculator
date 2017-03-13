#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QObject>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void max_slice_1(int max);
    void min_slice_1(int min);
    void max_slice_2(int max);
    void min_slice_2(int min);
    void qtty_alums(int qtty);
    void price(double p);
    void minPay(double p);
    void hours(double h);
    void porNegative(int p);
    void porPositive(int p);
    void allEmit();
    void expenses(double c);
signals:
    void slice1(int, int);
    void slice2(int, int);
    void total(double);
    void benefits(double);
    void payout(double);
    void costHours(double);

private:
    Ui::MainWindow *ui;
    int min1, max1, min2,max2, alumns;
    double cost, minHours, goalToPay, perPos, perNeg, expen;
};

#endif // MAINWINDOW_HH
