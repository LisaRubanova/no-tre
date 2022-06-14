#ifndef EXISTS_FORM_H
#define EXISTS_FORM_H

#include <QWidget>

namespace Ui {
class exists_form;
}

class exists_form : public QWidget
{
    Q_OBJECT

public:
    explicit exists_form(QWidget *parent = nullptr);
    ~exists_form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exists_form *ui;
};

#endif // EXISTS_FORM_H
