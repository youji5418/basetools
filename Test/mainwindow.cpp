#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>

#include "../uchardet/uchardet.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openfileBtn_released()
{
    QString url = QFileDialog::getOpenFileName();

    QFile file(url);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream text(&file);

        QString content = text.read(100);
        std::string code;
        Uchardet::parse(content.toStdString().data(), 100, code);

        ui->resultLabel->setText(code.data());
    }
}

