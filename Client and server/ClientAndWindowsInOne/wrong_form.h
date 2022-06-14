#ifndef WRONG_FORM_H
#define WRONG_FORM_H

#include <QWidget>

namespace Ui {
class wrong_form;
}

class wrong_form : public QWidget
{
    Q_OBJECT

public:
    explicit wrong_form(QWidget *parent = nullptr);
    ~wrong_form();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void registration();
private:
    Ui::wrong_form *ui;
};

#endif // WRONG_FORM_H
