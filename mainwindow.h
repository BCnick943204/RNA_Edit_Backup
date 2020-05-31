#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QListWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSharedPointer>
#include "parsexml.h"
#include "rnalib.h"
#include "IAlgorithm.h"
#include "optionchooser.h"
#include "graphicswindow.h"

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
    void on_newSeqButton_clicked();

    void on_uploadSeqButton_clicked();

    void on_listItem_changed(QListWidgetItem* list, QLabel* description, QString* names, QString* desc);

    void on_generateButton_clicked();

private:
    Ui::MainWindow *ui;
    void createFileBar();
    QDialog* createAlgoList();
    bool checkSequence(QString* sequence);
    IAlgorithm* loader(QString* filepath, QString name);
    void showTab(QMap<QString, double>, IAlgorithm*);

    QString file_path;
    QString directory_path;
    QListWidget* algoList;
    int FASTAcount;
    GraphicsWindow* tabWindow;

};
#endif // MAINWINDOW_H
