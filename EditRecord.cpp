#include "EditRecord.h"
#include<QPushButton>
#include<QGridLayout>
extern bool ok_flag;
extern char edit_id[10];
extern char edit_name[20];
extern char edit_producer[20];
extern int  edit_price;

EditRecordDlg::EditRecordDlg(QWidget *parent)
	: QDialog(parent){
    setWindowTitle(tr("Edit a record"));
    
    idLabel = new QLabel(tr("ID:"));
    idEdit = new QLineEdit;
    idEdit->setText(edit_id);
    idEdit->setEnabled(true);

    nameLabel = new QLabel(tr("name:"));
    nameEdit = new QLineEdit;       
    nameEdit->setText(edit_name);
    nameEdit->setEnabled(true);

    producerLabel = new QLabel(tr("producer:"));
    producerEdit = new QLineEdit;
    producerEdit->setText(edit_producer);
    producerEdit->setEnabled(true);

    priceLabel = new QLabel(tr("price:"));
    priceEdit = new QLineEdit;
    char s[10];memset(s,0,10);
    sprintf(s,"%d",edit_price);
    priceEdit->setText(s);
    priceEdit->setEnabled(true);

    okButton = new QPushButton(tr("OK"));
    cancleButton = new QPushButton(tr("Cancle"));

    connect(okButton,SIGNAL(clicked()),this,SLOT(okClicked()));
    connect(cancleButton,SIGNAL(clicked()),this,SLOT(cancleClicked()));  
   
    QGridLayout *left = new QGridLayout;
    left->addWidget(idLabel,0,0);
    left->addWidget(idEdit,0,1);
    left->addWidget(nameLabel,1,0);
    left->addWidget(nameEdit,1,1);
    left->addWidget(producerLabel,2,0);
    left->addWidget(producerEdit,2,1);
    left->addWidget(priceLabel,3,0);
    left->addWidget(priceEdit,3,1);
    QVBoxLayout *right = new QVBoxLayout;
    right->addWidget(okButton);
    right->addWidget(cancleButton);
    QHBoxLayout *mainlayout = new QHBoxLayout(this);
    mainlayout->addLayout(left);
    mainlayout->addLayout(right);
}

void EditRecordDlg::okClicked()
{
	ok_flag=1;
    memset(edit_id,0,sizeof(edit_id));
	memset(edit_name,0,sizeof(edit_name));
	memset(edit_producer,0,sizeof(edit_producer));
	edit_price=0;
    sprintf(edit_id,"%s",((idEdit->text()).toLatin1()).data());
	sprintf(edit_name,"%s",((nameEdit->text()).toLatin1()).data());
	sprintf(edit_producer,"%s",((producerEdit->text()).toLatin1()).data());
	edit_price=(priceEdit->text()).toInt();
	/*测试
	QString s;
	s.sprintf("scale:%d;quan:%f;kx:%f;ky:%f;kz:%f;len:;;;%d",scale,quan,chaos_kx,chaos_ky,chaos_kz,wk_length);
	QMessageBox::information(NULL,"ddd",s);
	*/
	close();
}
void EditRecordDlg::cancleClicked()
{
    close();
}

