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
  fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());

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


void MainWindow::saveButtonClicked()
{
    fileName = QFileDialog::getSaveFileName(this,"Open Image File",QDir::currentPath());
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    image.save(&file, "PNG");
}

void MainWindow::applyButtonClicked()
{
    if(ui->filterCorners->isChecked())
    {
        emit sendSelectedFilter(FeatureDetectors::CORNERS);
    }
    if(ui->filterEdges->isChecked())
    {
        emit sendSelectedFilter(FeatureDetectors::EDGES);
    }
    emit sendImageToProcessor(*imageObject);
}
