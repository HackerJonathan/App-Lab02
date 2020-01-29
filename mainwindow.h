#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

int cardType = 1;
int cardVisa = 1;
int cardMaster = 2;
int cardAmEx = 3;
int cardDiscover = 4;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_nameTextEdit_textChanged();
    void on_radioSizeA_clicked(bool checked);
    void on_radioSizeB_clicked(bool checked);
    void on_radioViewA_clicked(bool checked);
    void on_radioViewB_clicked(bool checked);
    void on_startDate_userDateChanged(const QDate &date);
    void on_lengthBox_valueChanged(int arg1);
    void on_numAdultsBox_valueChanged(int arg1);
    void on_numChildrenBox_valueChanged(int arg1);
    void on_parkingCheck_stateChanged(int arg1);

    void on_nextButtonA_clicked();

    void on_backButtonB_clicked();

    void on_payButtonB_clicked();

    void on_buttonExit_clicked();

    void on_visaButton_clicked();

    void on_masterCardButton_clicked();

    void on_discoverButton_clicked();

    void on_amExpressButton_clicked();

private:
    Ui::MainWindow *ui;

    void updatePeopleBounds();
    void updateCost();
    void updateCostLabels();
};
#endif // MAINWINDOW_H
