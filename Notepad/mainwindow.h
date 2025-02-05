#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionDelete_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionSelect_font_triggered();


    void on_actionBackground_font_triggered();

    void on_actionFont_color_triggered();

    void on_actionBackground_text_edit_triggered();

    void on_actionPrint_triggered();

    void on_actionAbout_Notepad_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};
#endif // MAINWINDOW_H
