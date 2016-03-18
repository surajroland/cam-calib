#include "gui/mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

  QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());

  if(!fileName.isEmpty())
  {
      imageObject = new QImage();
      imageObject->load(fileName);
      image = QPixmap::fromImage(*imageObject);
      scene = new QGraphicsScene(this);
      scene->addPixmap(image);
      scene->setSceneRect(image.rect());
      ui->graphicsView->setScene(scene);
  }

}
