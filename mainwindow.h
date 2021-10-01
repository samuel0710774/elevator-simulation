#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include "building.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectDB();


private slots:
    void on_runButton_clicked();

    void on_get_People_Info_clicked();

    void on_start_simulate_button_clicked();

    void slot_update_data();

private:
    Ui::MainWindow *ui;
    Data windata;
    Building building;
};
#endif // MAINWINDOW_H
