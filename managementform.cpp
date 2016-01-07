#include <QtGui>
#include "managementform.h"
#include "EditRecord.h"
#include<QMessageBox>
#include <QTextStream>
 #include <stdio.h>
#include<iostream>
#include<cstring>

using namespace std;
enum
{
        TABLE_IMPORT,
        TABLE_EXPORT,
        TABLE_STORAGE
};
const char *table[3]={"import","export","storage"};
bool ok_flag=false;
char edit_id[10]; //学号
char edit_name[20];//姓名
char edit_producer[20];//班级
int  edit_price; //借出数

ManagementForm::ManagementForm(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	ui.increaseradioButton->setChecked(true);
	selected_radio=0;
	ui.storageradioButton->setChecked(true);
	table_status=TABLE_STORAGE;
	sql_for_tableWidget("data.db","select * from storage;");
       /* QPixmap pixmap("./image/bg.png"); 
        //添加背景
        QPalette palette;
        palette.setBrush(backgroundRole(), QBrush(pixmap));
        setPalette(palette);
        */
/*notice:the following signal-slot is defined in ui_management.h by default. so we should ignore the following for signal-slot connections. otherwise, the clicking event will be executed twice! but if you modify the slot name,you must give the signal-slot connection. for example,you change the slot funciton on_storageButton_clicked() to on_storageButton1_clicked(),you have to provide the signal-slot connection as following:
    connect(ui.storageButton, SIGNAL(clicked()), this, SLOT(on_storageButton1_clicked()));
*/
/*	connect(ui.importRecordButton, SIGNAL(clicked()), this, SLOT(on_importRecordButton_clicked()));
	connect(ui.exportRecordButton, SIGNAL(clicked()), this, SLOT(on_exportRecordButton_clicked()));
	connect(ui.storageButton, SIGNAL(clicked()), this, SLOT(on_storageButton_clicked()));
	connect(ui.refreshStorageButton, SIGNAL(clicked()), this, SLOT(on_refreshStorageButton_clicked()));
*/
}
/*
int importrecordsbutton=0;
int exportrecordsbutton=0;
int storagebutton=0;
int refreshstoragebutton=0;
*/
void ManagementForm::on_importRecordradioButton_clicked()
{
	//if(importrecordsbutton==0){importrecordsbutton=1;}
        //else{importrecordsbutton=0;return;}
        //char sql_str[100];memset(sql_str,0,100);
	//sprintf(sql_str,"select * from import;");
	table_status=TABLE_IMPORT;
	sql_for_tableWidget("data.db","select * from import;");
	return;
}
void ManagementForm::on_exportRecordradioButton_clicked()
{
        //if(exportrecordsbutton==0){exportrecordsbutton=1;}
        //else{exportrecordsbutton=0;return;}
	table_status=TABLE_EXPORT;
	sql_for_tableWidget("data.db","select * from export;");
        return;
}
void ManagementForm::on_storageradioButton_clicked()
{
        //if(storagebutton==0){storagebutton=1;}
        //else{storagebutton=0;return;}
	table_status=TABLE_STORAGE;
    sql_for_tableWidget("data.db","select * from storage;");
        return;
}
/*
on_refreshStorageButton_clicked function:
create a new table named storage according to table import and table export.
*/
void ManagementForm::on_refreshStorageButton_clicked()
{
        //if(refreshstoragebutton==0){refreshstoragebutton=1;}
        //else{refreshstoragebutton=0;return;}
	table_status=TABLE_STORAGE;
	repaint();
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open("data.db", &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	char **dbResult_import;
	int nRow_import, nColumn_import;
	char **dbResult_export;
	int nRow_export, nColumn_export;
	rc = sqlite3_get_table(db,"select * from import;", &dbResult_import, &nRow_import,&nColumn_import, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}	
	rc = sqlite3_get_table(db,"select * from export;", &dbResult_export, &nRow_export,&nColumn_export, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	  //create new table storage begin
	
        rc = sqlite3_exec(db,"create table storage(ID varchar(10),name varchar(20),producer varchar(20),price smallint);", 0, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
        }
	
        rc = sqlite3_exec(db,"delete from storage;", 0, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
        }

	int i,j;
	int index_import=nColumn_import;
	int index_export=nColumn_export;
	for(i=0; i<nRow_import; i++){
		bool out_flag=false;//mark for export.
		index_export=nColumn_export;
		for(j=0;j<nRow_export;j++)
		{
			if(strcmp(dbResult_import[index_import],dbResult_export[index_export])==0)
			{
				out_flag=true;
				break;
			}
			index_export+=nColumn_export;
		}
		if(!out_flag)
		{
			char ss[100];memset(ss,0,100);
                        sprintf(ss,"insert into storage values('%s', '%s', '%s', %d);",dbResult_import[index_import],dbResult_import[index_import+1],dbResult_import[index_import+2],atoi((const char*)dbResult_import[index_import+3]));//currently support 4 columns. make perfect later.
                        rc = sqlite3_exec(db,ss, 0, 0, &zErrMsg);
	
		}
		index_import+=nColumn_import;
	}
	//create new table storage end
	sqlite3_close(db);
	sql_for_tableWidget("data.db","select * from storage;");

        return;
}
void ManagementForm::sql_for_tableWidget(char * fp, char * sql_str)
{	
	repaint();
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open(fp, &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	char **dbResult;
	int nRow, nColumn;
	rc = sqlite3_get_table(db,sql_str, &dbResult, &nRow,&nColumn, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
	int i,j;
	int index=nColumn;
	ui.tableWidget->setRowCount(nRow);
	for(i=0; i<nRow; i++){
		for(j=0;j<nColumn;j++){
			//printf("%s = %s  ", dbResult[j], dbResult[index]);
			QTableWidgetItem *item = new QTableWidgetItem(dbResult[index]);
			ui.tableWidget->setItem(i, j, item);
			index++;
		}
	}
        return;
}
const char *column[4]={"ID","name","producer","price"};
const char *con[2]={"and","or"};
const char *radio[2]={"asc","desc"};
void ManagementForm::on_querypushButton_clicked()
{
	char sql_str[150];
	memset(sql_str,0,150);	
	char sql_str1[35];memset(sql_str1,0,35);
	sprintf(sql_str1,"select * from %s where",table[table_status]);
	//const char *sql_str1="select * from import where";
	QString s =  ui.textlineEdit->text();
	QByteArray ba = s.toLatin1();
	char sql_str2[40];memset(sql_str2,0,40);
	sprintf(sql_str2,"%s='%s'",column[ui.columncomboBox->currentIndex()],ba.data());
	
	QString s1 =  ui.littlelineEdit->text();
	QString s2 =  ui.biglineEdit->text();
	char sql_str3[15];memset(sql_str3,0,15);
	if(s1.length())
	{
		sprintf(sql_str3,"price>%d",s1.toInt());
	}
	char sql_str4[15];memset(sql_str4,0,15);
	if(s2.length())
        {
                sprintf(sql_str4,"price<%d",s2.toInt());
        }
	char sql_str5[15];memset(sql_str5,0,15);      
	sprintf(sql_str5,"order by %s",column[ui.columncomboBox2->currentIndex()]);
        
	char sql_str6[15];memset(sql_str6,0,15);
	sprintf(sql_str6,"%s",radio[selected_radio]);
        
	
        if (s.length())
	{
		if((!s1.length()) && (!s2.length())){
			sprintf(sql_str,"%s %s %s %s;",sql_str1,sql_str2,sql_str5,sql_str6);
		}
		else if((!s1.length()) && s2.length()){
			sprintf(sql_str,"%s %s %s %s %s %s;",sql_str1,sql_str2,con[ui.andorcomboBox->currentIndex()],sql_str4,sql_str5,sql_str6);
		}
		else if(s1.length() && (!s2.length())){
			sprintf(sql_str,"%s %s %s %s %s %s;",sql_str1,sql_str2,con[ui.andorcomboBox->currentIndex()],sql_str3,sql_str5,sql_str6);
		}
		else {
			sprintf(sql_str,"%s %s %s price between %d and %d %s %s;",sql_str1,sql_str2,con[ui.andorcomboBox->currentIndex()],s1.toInt(),s2.toInt(),sql_str5,sql_str6);
		}
	}
	else if((!s1.length()) && s2.length()){
		sprintf(sql_str,"%s %s %s %s;",sql_str1,sql_str4,sql_str5,sql_str6);
	}
	else if(s1.length() && (!s2.length())){
		sprintf(sql_str,"%s %s %s %s;",sql_str1,sql_str3,sql_str5,sql_str6);
	}
	else if(s1.length() && s2.length()){
		sprintf(sql_str,"%s price between %d and %d %s %s;",sql_str1,s1.toInt(),s2.toInt(),sql_str5,sql_str6);
	}
	else{
		 sprintf(sql_str,"select * from %s %s %s;",table[table_status],sql_str5,sql_str6);
	}
    QMessageBox::information(this,"Information",sql_str);
	sql_for_tableWidget("data.db",sql_str);

}
void ManagementForm::on_increaseradioButton_clicked()
{
	selected_radio=0;
}
void ManagementForm::on_descendradioButton_clicked()
{
	selected_radio=1;
}


/*
判断输入格式是否正确
 */

bool ManagementForm::judge_format(char edit_id[],char edit_name[],char edit_producer[],int num,string Error_message)
{
    string str1 = "输入信息部分为空"+Error_message+"错误!";  //报错信息
    char *s1 = (char *)str1.data();//string转int
    bool flag = false; //初始化为false
    //cout<<edit_id<<endl;
    if(strcmp(edit_id,"") == 0 || strcmp(edit_name,"") == 0 || strcmp(edit_producer,"") == 0 || edit_price < 0)  //如果有一个输入为空,错误，添加失败
    {
        cout<<"输入信息部分为空,"+Error_message<<"错误!"<<endl;
        QMessageBox::information(this,"友情提示",s1);
        flag = true; //发现为空
        return false;  //直接返回
    }

    bool flag1 = false;
    /*
     加判断
    学号一定要在1300000000 - 1309999999之间  学号必须是10位
    */
    string str2 = "学号应在1300000000~1309999999这个范围之间, 请您确认后重新"+Error_message+"!";
    char *s2 = (char *)str2.data(); //string转char*
    //cout<<s2<<endl;
    //cout<<edit_id<<endl;
    edit_id[10] = '\0';
    int len = strlen(edit_id);
    if(len == 10 && edit_id[0] == '1' && edit_id[1] == '3' && edit_id[2] == '0') //必须是10位，而且是130开头
    {
        cout<<edit_id<<endl;
        flag1 = true;
    }
    else
        flag1 = false;
    if(flag1 == false)
    {
            QMessageBox::information(this,"友情提示",s2);
            return false;
    }
    return true;
}





void ManagementForm::on_addpushButton_clicked()
{	
	ok_flag=false;
    memset(edit_id,0,10);
	memset(edit_name,0,20);
	memset(edit_producer,0,20);
    edit_price=0; //初始化
	EditRecordDlg *dlg=new EditRecordDlg;
	dlg->exec();
	if(ok_flag)
	{
		sqlite3 *db;
        	char *zErrMsg = 0;
        	int rc;
        	rc = sqlite3_open("data.db", &db);
        	if( rc ){
                	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db))
;
                	sqlite3_close(db);
                	exit(1);
        	}
		char ss[100];memset(ss,0,100);


       bool final_result =  judge_format(edit_id,edit_name,edit_producer,edit_price,"添加");  //调用判断正确性





        /*if(flag == true)
                sprintf(ss,"insert into %s values('%s', '%s', '%s', %d);",table[table_status],edit_id,edit_name,edit_producer,edit_price);//currently support 4 columns. make perfect later.
        else
                cout<<"插入失败!"<<endl;*/








        if(final_result)            //如果验证输入信息是正确的就存入数据库
        {
            sprintf(ss,"insert into %s values('%s', '%s', '%s', %d);",table[table_status],edit_id,edit_name,edit_producer,edit_price);//currently support 4 columns. make perfect later.


            rc = sqlite3_exec(db,ss, 0, 0, &zErrMsg);
            sqlite3_close(db);
            memset(ss,0,100);
            sprintf(ss,"select * from %s;",table[table_status]);
            sql_for_tableWidget("data.db",ss);
        }
	}
}
void ManagementForm::on_deletepushButton_clicked()
{
    if(QMessageBox::question(this,"Question",tr("您是否要删除当前的记录?"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
	{
        return;
    }

    //数据库操作
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open("data.db", &db);
	if( rc ){
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

    int row=ui.tableWidget->currentRow(); //获取当前行

    /*
     * 优化用户体验，防止程序崩溃退出.
     */
    if(row == -1)
    {
        QMessageBox::information(this,"友情提示",tr("您的删除有误,请选中后再删除!"));
        return;  //直接return掉,不return程序崩溃后退出.
    }

	//int column=ui.tableWidget->columnCount();//4
    char id_str[10];
    memset(id_str,0,10);
    QTableWidgetItem *item=ui.tableWidget->item(row,0); //学号
    QString str=item->text();
    sprintf(id_str,"%s",(str.toLatin1()).data());



	char name_str[20];memset(name_str,0,20);
        item=ui.tableWidget->item(row,1); //姓名
        str=item->text();
        sprintf(name_str,"%s",(str.toLatin1()).data());
	


        char producer_str[20];memset(producer_str,0,20);
        item=ui.tableWidget->item(row,2); //班级
        str=item->text();
        sprintf(producer_str,"%s",(str.toLatin1()).data());
	
	int price_str;
        item=ui.tableWidget->item(row,3);//借阅册数
        str=item->text();
    price_str=str.toInt(); //转成int型
	



	char sql_str[150];memset(sql_str,0,150);
    sprintf(sql_str,"delete from %s where ID='%s' and name='%s' and producer='%s' and price=%d;",table[table_status],id_str,name_str,producer_str,price_str);
	rc = sqlite3_exec(db,sql_str, 0, 0, &zErrMsg);  
	sqlite3_close(db);
	memset(sql_str,0,150);
        sprintf(sql_str,"select * from %s;",table[table_status]);
        sql_for_tableWidget("data.db",sql_str);

	return;
}



/*
 *
 * 修改做了优化,一开始如果没有选中，点击修改即退出,用户体验不好
 *
 */

void ManagementForm::on_modifypushButton_clicked()
{
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        rc = sqlite3_open("data.db", &db);
        if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
               exit(1);
        }
        int row=ui.tableWidget->currentRow();



        if(row == -1)
        {
            QMessageBox::information(this,"友情提示",tr("修改失败,原因是您没有选中,请选中行号后再次点击修改!"));
            return;  //没有这句程序会异常退出,因为row没有选中的时候为-1,所以增加了一个过滤！！！！！！！！！！！！！！！！！！
        }


        //cout<<row<<endl;
        //int column=ui.tableWidget->columnCount();//4
        char id_str[10];memset(id_str,0,10);
        QTableWidgetItem *item=ui.tableWidget->item(row,0);
        QString str=item->text();
        sprintf(id_str,"%s",(str.toLatin1()).data());

        char name_str[20];memset(name_str,0,20);
        item=ui.tableWidget->item(row,1);
        str=item->text();
        sprintf(name_str,"%s",(str.toLatin1()).data());

        //cout<<name_str<<endl; 还没到这步程序异常停止

        char producer_str[20];memset(producer_str,0,20);
        item=ui.tableWidget->item(row,2);
        str=item->text();
        sprintf(producer_str,"%s",(str.toLatin1()).data());

        int price_str;
        item=ui.tableWidget->item(row,3);
        str=item->text();
        price_str=str.toInt();
	
	ok_flag=false;
    memset(edit_id,0,10);strcat(edit_id,id_str);
        memset(edit_name,0,20);strcat(edit_name,name_str);
        memset(edit_producer,0,20);strcat(edit_producer,producer_str);
	edit_price=price_str;
	
        EditRecordDlg *dlg=new EditRecordDlg;
        dlg->exec();
        if(!ok_flag)
        {
                return;
        }

        bool final_result1 = judge_format(edit_id,edit_name,edit_producer,edit_price,"修改");

    if(final_result1) //如果输入的修改信息完全正确则添加，否则照旧
    {
        char sql_str[150];memset(sql_str,0,150);
        sprintf(sql_str,"update %s set ID='%s', name='%s',producer='%s',price=%d where ID='%s' and name='%s' and producer='%s' and price=%d;",table[table_status],edit_id,edit_name,edit_producer,edit_price,id_str,name_str,producer_str,price_str);
        rc = sqlite3_exec(db,sql_str, 0, 0, &zErrMsg);
        sqlite3_close(db);
        memset(sql_str,0,150);
        sprintf(sql_str,"select * from %s;",table[table_status]);
        sql_for_tableWidget("data.db",sql_str);
    }
	return;
}

/*
void ManagementForm::on_wrong_clicked()
{
    QMessageBox::information(this,"Information",tr("anything you want tell user"));
}*/

void ManagementForm::on_closepushButton_clicked()
{
    QMessageBox::information(this,"友情提示",tr("谢谢使用本软件,欢迎下次继续使用,再见..."));
}
