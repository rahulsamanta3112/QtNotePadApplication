#include "mainwindow.h"
#include "ui_mainwindow.h"

// Rahul Added ...

#include <QMainWindow>
#include<QTextStream>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsItem>
#include <QtDebug>
#include <QTextEdit>
#include <QTextCursor>
#include<qtextcursor.h>
// For  Font ........
#include<QFontDialog>
#include<QFont>

// For Color .....
#include<QColorDialog>
#include<QColor>
#include <QImage>

// For Print ..
#include<QPrinter>
#include<QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textE);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
   file_path = "";
   ui->textE->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name =  QFileDialog::getOpenFileName(this,"Open File");
    QFile file (file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
          QMessageBox::warning(this,"..","File Is not Open");

          return;
    }

    QTextStream in (&file);
    QString text = in.readAll();
    ui->textE->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    //QString file_name =  QFileDialog::getSaveFileName(this,"Open File");
    QFile file (file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
          QMessageBox::warning(this,"..","File Is not Open");

          return;
    }

    QTextStream out (&file);
    QString text = ui->textE->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
        ui->textE->cut();
}

void MainWindow::on_actionCopy_triggered()
{
          ui->textE->copy();
}

void MainWindow::on_actionPsate_triggered()
{
       ui->textE->paste();
}

void MainWindow::on_actionRedo_triggered()
{
     ui->textE->redo();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name =  QFileDialog::getSaveFileName(this,"Open File");
    QFile file (file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
          QMessageBox::warning(this,"..","File Is not Open");

          return;
    }

    QTextStream out (&file);
    QString text = ui->textE->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionundo_triggered()
{
          ui->textE->undo();
}

void MainWindow::on_actionabout_triggered()
{
    QString about_text ;
    about_text ="Author : Embdes   ";
    about_text+= "  Date : 00/00/2018   ";
    about_text+= "  (C) QTNotePad (R)   ";
    QMessageBox ::about(this," About QTNotePad ",about_text);
}

void MainWindow::on_actionFont_triggered()
{
      bool ok ;
       QFont font = QFontDialog::getFont(&ok,this);
       if(ok){
              ui->textE->setFont(font);
       }
       else return;
}

void MainWindow::on_actionColor_triggered()
{
       QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");

       if (color.isValid()){

          ui->textE->setTextColor(color);

       }
}

void MainWindow::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");

    if (color.isValid()){

       ui->textE->setTextBackgroundColor(color);

    }
}

void MainWindow::on_actionWindow_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");
    if (color.isValid()){
       ui->textE->setPalette(QPalette(color));

    }
}

void MainWindow::on_actionPrint_triggered()
{
     QPrinter printer;
     printer.setPrinterName("name");
     QPrintDialog dialog (&printer,this);
     if(dialog.exec() == QDialog::Rejected)
     return;
     ui->textE->print(&printer);
}

void MainWindow::on_actionLeft_Allign_triggered()
{
       ui->textE->setAlignment(Qt::AlignLeft);
}
void MainWindow::on_actionCenter_Allign_triggered()
{
      ui->textE->setAlignment(Qt::AlignCenter);
}
void MainWindow::on_actionRight_Allign_triggered()
{
     ui->textE->setAlignment(Qt::AlignRight);
}



void MainWindow::on_actionNumbering_triggered()
{


        // will insert a numbered list
       ui->textE->insertHtml("<ol><li>  .</li></ol><br />");

}

void MainWindow::on_actionBullets_triggered()
{
     // will insert a bulleted list
   ui->textE->insertHtml("<ul><li> .</li></ul> <br />");
}

void MainWindow::on_actionimage_triggered()
{

        QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:/",tr("Images (*.png *.xpm *.jpg)"));
        ui->textE->setHtml(fileName);
}

