#ifndef GAUSS_H
#define GAUSS_H

#include <QMainWindow>

namespace Ui {
class gauss;
}

class gauss : public QMainWindow
{
    Q_OBJECT

public:
    explicit gauss(QWidget *parent = 0);
    ~gauss();
    double numero;
    double x1,x2,x3,x4;
    double ind1,ind2,ind3,ind4;
    double matriz[4][4];
    double indep[4][1];
    double temporal[1][4];
    double temporal2[1][4];
    int i=0,j=0;
public slots:
    void ejecutar();
    void limpiar();
    void agregar();

private:
    Ui::gauss *ui;
};

#endif // GAUSS_H
