#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QRadioButton>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//signals:
//    void applySelectedFilter();

private slots:
    void loadButtonClicked();
    void applyButtonClicked();
    void saveButtonClicked();

private:
    Ui::MainWindow *ui;

    QString fileName;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;    
};

#endif // MAINWINDOW_H
