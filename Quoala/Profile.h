#ifndef PROFILE_H
#define PROFILE_H
#include <QVector>
#include <QString>

struct userTasks{
    QString taskName;
    bool isFun;
};

class Profile {
public:
    Profile(){sleepHours = 0; meals = 0; exerciseHours = 0; workHours = 0; hoursLeft = 0; weightedValue = 12; feeling = 0; age = 0;};

    Profile(double sleep, double meals, double exercise, double work, int age) {
        sleepHours = sleep;
        this->meals = meals;
        this->exerciseHours = exercise/60;
        this->workHours = work;
        hoursLeft = (24 - sleep - meals - exercise - work);
        this->age = age;
    }

    void setWeight(double value) {
        weightedValue = value;
    }
    void addTask(QString task, bool isFun){
        tasks.push_back({task, isFun});
    }
    QString outputTasks() {
        QString list;
        if (weightedValue == 2){
            list = "You should take a day off and relax!";
        }
        else if (weightedValue < 6)
        {
            int num = 1;
            for (int i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].isFun == true)
                {
                    list = list + "#" + QString::number(num) + ": " + tasks[i].taskName + "\n";
                    num++;
                    tasks.erase(tasks.begin()+i);
                }
            }
            for (int i = 0; i < tasks.size(); i++)
            {
                list = list + "#" + QString::number(num) + ": " + tasks[i].taskName + "\n";
                num++;
            }
        }
        else{
            int num = 1;
            for (int i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].isFun == false)
                {
                    list = list + "#" + QString::number(num) + ": " + tasks[i].taskName + "\n";
                    num++;
                    tasks.erase(tasks.begin()+i);
                }
            }
            for (int i = 0; i < tasks.size(); i++)
            {
                list = list + "#" + QString::number(num) + ": " + tasks[i].taskName + "\n";
                num++;
            }
        }

        return list;
    }
    void calculateWeight(){
        if (age <= 17 && (sleepHours < 8 || sleepHours > 10) )
        {
            weightedValue-= 4;
        }
        if (age > 17 && (sleepHours < 7 || sleepHours > 9) )
        {
            weightedValue-= 3;
        }

        if (meals == 2)
        {
            weightedValue-=2;
        }
        else if (meals == 1)
        {
            weightedValue-=4;
        }
        if (hoursLeft >5 || hoursLeft<4)
        {
            weightedValue -= 2;
        }
    }
    void setFeeling(int feel){
        feeling = feel;
    }
    int getFeeling(){
        return feeling;
    }
    int getTaskSize(){
        return tasks.size();
    }
private:
    double sleepHours;
    double meals;
    double exerciseHours;
    double workHours;
    double hoursLeft;
    double weightedValue;
    int feeling;
    int age;
    QVector<userTasks> tasks;
};

#endif // PROFILE_H
