#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QRadioButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void init();

private slots:
    void loadButtonClicked();
    void applyButtonClicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
