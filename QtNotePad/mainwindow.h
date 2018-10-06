#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <ui_mainwindow.h>
#include <QMainWindow>
#include <QTextEdit>


namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPsate_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_As_triggered();

    void on_actionundo_triggered();

    void on_actionabout_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionWindow_Color_triggered();

    void on_actionPrint_triggered();

    void on_actionLeft_Allign_triggered();

    void on_actionCenter_Allign_triggered();

    void on_actionRight_Allign_triggered();

    void on_actionNumbering_triggered();

    void on_actionBullets_triggered();

    void on_actionimage_triggered();


private:
    Ui::MainWindow *ui;

    QString file_path;
};

#endif // MAINWINDOW_H
