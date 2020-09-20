#include "application.h"
#include "ui_application.h"

application::application(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowTitle("Quoala");

    ui->sleepLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9.]{0,2}"), this ));
    ui->mealsLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9.]{0,2}"), this ));
    ui->workLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9.]{0,2}"), this ));
    ui->exerciseLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9.]{0,3}"), this ));
    ui->ageLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9.]{0,2}"), this ));
    ui->createProfile->setFocus();


    ui->sleepLineEdit->setPlaceholderText("How many hours do you sleep at night?");
    ui->mealsLineEdit->setPlaceholderText("How many meals do you have per day?");
    ui->exerciseLineEdit->setPlaceholderText("How many minutes of exercise do you do a day?");
    ui->workLineEdit->setPlaceholderText("How many hours do you work in a day?");
    ui->ageLineEdit->setPlaceholderText("Enter your age");

    QPixmap pixmap("/Users/kennethcasimiro/Downloads/kaola-no-bg.png");
    ui->label_2->setPixmap(pixmap);

    QPixmap pixmap2("/Users/kennethcasimiro/Downloads/kaola-no-bg-2.png");
    ui->label_3->setPixmap(pixmap2);
    ui->label_4->setPixmap(pixmap2);

}

application::~application()
{
    delete ui;
}

Profile* application::getProfile(){
    return user;
}

void application::setProfile(Profile *profile){
    user = profile;
}

void application::on_createProfile_clicked()
{
    if(((ui->sleepLineEdit->text().toDouble() + ui->mealsLineEdit->text().toDouble() + ui->workLineEdit->text().toDouble() + ui->exerciseLineEdit->text().toDouble())) > 0 &&
            (24 - (ui->sleepLineEdit->text().toDouble() + ui->mealsLineEdit->text().toDouble() + ui->workLineEdit->text().toDouble() + ui->exerciseLineEdit->text().toDouble()/60)) <=24 &&
            ui->ageLineEdit->text().toDouble() > 0)
    {
        // create profile
        this->setProfile( new Profile(ui->sleepLineEdit->text().toDouble(),ui->mealsLineEdit->text().toDouble(),ui->workLineEdit->text().toDouble(),ui->exerciseLineEdit->text().toDouble(),ui->ageLineEdit->text().toInt()));
        ui->stackedWidget->setCurrentIndex(1);
        ui->label_2->show();
    }
    else {
                QMessageBox::information(this,QObject::tr("System Message"),tr("Please input correct numbers"),QMessageBox::Ok);
                ui->sleepLineEdit->clear();
                ui->mealsLineEdit->clear();
                ui->workLineEdit->clear();
                ui->exerciseLineEdit->clear();
    }



}

void application::resetButtons() {
    ui->badButton->setAutoFillBackground(false);
    ui->okayButton->setAutoFillBackground(false);
    ui->goodButton->setAutoFillBackground(false);
}

int application::getFeel()
{
    return feel;
}




void application::on_badButton_clicked()
{
    resetButtons();
    feel = 1; // temp value
    QPalette pal = ui->badButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::magenta));
    ui->badButton->setAutoFillBackground(true);
    ui->badButton->setPalette(pal);
    ui->badButton->update();
}

void application::on_okayButton_clicked()
{
    resetButtons();
    QPalette pal = ui->okayButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::magenta));
    ui->okayButton->setAutoFillBackground(true);
    ui->okayButton->setPalette(pal);
    ui->okayButton->update();
    feel = 2;
}

void application::on_goodButton_clicked()
{
    resetButtons();
    QPalette pal = ui->goodButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::magenta));
    ui->goodButton->setAutoFillBackground(true);
    ui->goodButton->setPalette(pal);
    ui->goodButton->update();
    feel = 3;
}

void application::on_addListButton_clicked()
{
    user->addTask(ui->taskLineEdit->text(), ui->funBox->checkState());
    QMessageBox::information(this,QObject::tr("System Message"),tr("Task has been added!"),QMessageBox::Ok);
    ui->taskLineEdit->clear();
}

void application::on_doneButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_3->show();
    ui->listTask->setText(user->outputTasks()); // <----- fucks up right here yesssirrrrrrrrrr
}

void application::on_restartButton_clicked()
{
    QApplication::quit();
}
