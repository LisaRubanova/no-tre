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
    /**
     * @brief wrong_form конструктор, открытие формы
     * @param parent
     */
    explicit wrong_form(QWidget *parent = nullptr);
    /**
     * @brief wrong_form::~wrong_form деструктор, закрытие формы
     */
    ~wrong_form();

private slots:
    /**
     * @brief on_pushButton_clicked скрытие формы
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_2_clicked переход к регистрации
     */
    void on_pushButton_2_clicked();

signals:
    void registration();
private:
    Ui::wrong_form *ui;
};

#endif // WRONG_FORM_H
