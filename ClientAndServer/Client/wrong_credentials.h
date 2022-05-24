#ifndef WRONG_CREDENTIALS_H
#define WRONG_CREDENTIALS_H
//#include "authform.h"
#include <QDialog>

namespace Ui {
class wrong_credentials;
}

class wrong_credentials : public QDialog
{
    Q_OBJECT

public:
    explicit wrong_credentials(QWidget *parent = nullptr);
    ~wrong_credentials();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();
signals:
    void registration();
private:
    Ui::wrong_credentials *ui;
    //AuthForm *auth_form;
};

#endif // WRONG_CREDENTIALS_H
