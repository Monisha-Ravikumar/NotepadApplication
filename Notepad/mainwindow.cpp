#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionUndo_triggered()
{
 ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
  ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
  ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
 ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
   ui->textEdit->paste();
}

void MainWindow::on_actionDelete_triggered()
{
   ui->textEdit->deleteLater();
}


void MainWindow::on_actionNew_triggered()
{
    file_path=" ";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
    QFile file(file_name);
    file_path=(file_name);
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"open","file not open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"Save","file as not save..");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    file.flush();
    file.close();
}
void MainWindow::on_actionSave_As_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"save the file");
    QFile file(file_name);
    file_path=(file_name);
    if(file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"Save as","file as not save");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    file.flush();
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSelect_font_triggered()
{
    bool fontselected;
    QFont font=QFontDialog::getFont(&fontselected,this);
    if(fontselected)
    {
        ui->textEdit->setFont(font);
    }
}
void MainWindow::on_actionBackground_font_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"choose a color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}

void MainWindow::on_actionFont_color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"choose a color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionBackground_text_edit_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"choose a color");
    if(color.isValid())
    {
        ui->textEdit->setPalette(QPalette(color));
    }
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName(" ");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}



void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text;
    about_text = "licence under Microsoft Window\n";
    about_text += "Date : 02/05/2021\n";
    about_text += "version 20H2";
    QMessageBox::about(this,"About Notepad",about_text);
}


void MainWindow::on_actionBold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}


void MainWindow::on_actionItalic_triggered()
{
    ui->textEdit->setFontItalic(true);
}

void MainWindow::on_actionUnderline_triggered()
{
    ui->textEdit->setFontUnderline(true);
}
