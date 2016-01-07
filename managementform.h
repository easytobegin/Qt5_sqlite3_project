#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QDialog>
#include "ui_management.h"
#include "sqlite3.h"
#include<string>

using namespace std;
class ManagementForm : public QDialog
{
Q_OBJECT
public:
ManagementForm(QWidget *parent = 0);
public:
void sql_for_tableWidget(char *, char *);
int selected_radio;
int table_status;
bool judge_format(char edit_id[],char edit_name[],char edit_producer[],int num,string Error_message);
private:
Ui::Form ui;
private slots:
void on_importRecordradioButton_clicked();
void on_exportRecordradioButton_clicked();
void on_storageradioButton_clicked();
void on_refreshStorageButton_clicked();
void on_querypushButton_clicked();
void on_increaseradioButton_clicked();
void on_descendradioButton_clicked();
void on_addpushButton_clicked();
void on_deletepushButton_clicked();
void on_modifypushButton_clicked();

void on_wrong_clicked(); //插入错误
void on_closepushButton_clicked();

};
#endif
