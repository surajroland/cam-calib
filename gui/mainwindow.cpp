#include "gui/mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    connect(ui->applyButton, SIGNAL(clicked()), this, SLOT(applyButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadButtonClicked()
{
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

void MainWindow::applyButtonClicked()
{
    if(ui->filterCorners->isChecked())
    {

    }
    if(ui->filterEdges->isChecked())
    {

    }
}

void MainWindow::saveButtonClicked()
{

}
