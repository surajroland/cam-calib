#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsPixmapItem>

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
    void loadButtonClicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
