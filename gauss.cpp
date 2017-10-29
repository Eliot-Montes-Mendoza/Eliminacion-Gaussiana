#include "gauss.h"
#include "ui_gauss.h"

gauss::gauss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gauss)
{
    ui->setupUi(this);
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
    connect(ui->agrega,SIGNAL(clicked()),this,SLOT(agregar()));
    ui->iniciar->setDisabled(true);
    ui->limpiar->setDisabled(true);

}
void gauss::agregar(){
    ui->limpiar->setDisabled(false);
    matriz[i][0]=ui->valorx1->value();
    matriz[i][1]=ui->valorx2->value();
    matriz[i][2]=ui->valorx3->value();
    matriz[i][3]=ui->valorx4->value();
    indep[i][0]=ui->valorindep->value();
    ui->matrix->setItem(i,0,new QTableWidgetItem(ui->valorx1->text()));
    ui->matrix->setItem(i,1,new QTableWidgetItem(ui->valorx2->text()));
    ui->matrix->setItem(i,2,new QTableWidgetItem(ui->valorx3->text()));
    ui->matrix->setItem(i,3,new QTableWidgetItem(ui->valorx4->text()));
    ui->matrix->setItem(i,4,new QTableWidgetItem(ui->valorindep->text()));
    i++;
    if(i==4){
        ui->agrega->setDisabled(true);
        ui->iniciar->setDisabled(false);

    }


}

void gauss::ejecutar(){
    int i=0, j=0;
    QTableWidgetItem posicion;
    for(i=4;i>=0;i--){
                if(matriz[0][i]==0){
                    ind1=indep[0][0];
                    ind2=indep[i+1][0];
                    for(j=0;j<4;j++){
                        temporal[0][j]=matriz[0][j];
                        temporal2[0][j]=matriz[i+1][j];
                        matriz[i+1][j]=temporal[0][j];
                        matriz[0][j]=temporal2[0][j];
                        indep[i+1][0]=ind1;
                        indep[0][0]=ind2;
                    }
                }
            }
        for(i=0;i<4;i++){
            for(j=0;j<i;j++){
                matriz[i][j]=(matriz[i][j]-(matriz[0][j]*(matriz[i][j]/matriz[0][j])));
            }
        }
        x4=(indep[3][0]/matriz[3][3]);
        x3=(indep[2][0]-(matriz[2][3]*x4))/(matriz[2][2]);
        x2=(indep[1][0]-(matriz[1][2]*x3)-(matriz[1][3]*x4))/(matriz[1][1]);
        x1=(indep[0][0]-(matriz[0][1]*x2)-(matriz[0][2]*x3)-(matriz[0][3]*x4))/(matriz[0][0]);
        ui->valor1->display(x1);
        ui->valor2->display(x2);
        ui->valor3->display(x3);
        ui->valor4->display(x4);
    }


void gauss::limpiar(){
    ui->valorx1->setValue(0.0);
    ui->valorx2->setValue(0.0);
    ui->valorx3->setValue(0.0);
    ui->valorx4->setValue(0.0);
    ui->valorindep->setValue(0.0);
    ui->matrix->clearContents();
    ui->iniciar->setDisabled(true);
    ui->agrega->setDisabled(false);
    ui->matrix->clearContents();
    ui->valor1->display(0.0);
    ui->valor2->display(0.0);
    ui->valor3->display(0.0);
    ui->valor4->display(0.0);
    i=0;
}

gauss::~gauss()
{
    delete ui;
}
