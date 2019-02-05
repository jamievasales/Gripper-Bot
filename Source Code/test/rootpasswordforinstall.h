#ifndef ROOTPASSWORDFORINSTALL_H
#define ROOTPASSWORDFORINSTALL_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
class rootPasswordForInstall;
}

class rootPasswordForInstall : public QDialog
{
    Q_OBJECT

public:
    explicit rootPasswordForInstall(QWidget *parent = 0);
    QListWidget* dependencyInstallOutput;
    QVector<qint64> thepid;
    ~rootPasswordForInstall();

private:
    Ui::rootPasswordForInstall *ui;
     void closeEvent(QCloseEvent *event) override;
};

#endif // ROOTPASSWORDFORINSTALL_H
