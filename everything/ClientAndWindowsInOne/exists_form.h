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
    /**
     * @brief exists_form::exists_form конструктор, создание формы предупреждения
     * @param parent
     */
    explicit exists_form(QWidget *parent = nullptr);
    /**
     * @brief exists_form::~exists_form дескруктор, закрытие формы
     */
    ~exists_form();

private slots:
    /**
     * @brief exists_form::on_pushButton_clicked скрыытие формы
     */
    void on_pushButton_clicked();

private:
    Ui::exists_form *ui;
};

#endif // EXISTS_FORM_H
