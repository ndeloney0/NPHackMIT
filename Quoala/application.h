#ifndef APPLICATION_H
#define APPLICATION_H

#include <QDialog>
#include <QRegExpValidator>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include "Profile.h"

namespace Ui {
class application;
}

class application : public QDialog
{
    Q_OBJECT

public:
    explicit application(QWidget *parent = nullptr);
    Profile *getProfile();
    void resetButtons();
    int getFeel();
    void setProfile(Profile *profile);
    ~application();

private slots:
    void on_createProfile_clicked();

    void on_badButton_clicked();

    void on_okayButton_clicked();

    void on_goodButton_clicked();

    void on_addListButton_clicked();

    void on_doneButton_clicked();

    void on_restartButton_clicked();

private:
    Ui::application *ui;
        Profile *user;
            int feel;
};

#endif // APPLICATION_H
