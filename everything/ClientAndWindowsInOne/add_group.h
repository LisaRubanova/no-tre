#ifndef ADD_GROUP_H
#define ADD_GROUP_H
#include "back_func.h"
#include "cannot_change.h"
#include <QWidget>
#include <QRegularExpression>
#include <QMap>
#include <QRegularExpressionMatch>

namespace Ui {
class add_group;
}

class add_group : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief add_group::add_group конструктор, создание формы
     * @param parent
     */
    explicit add_group(QWidget *parent = nullptr);
    /**
     * @brief add_group::~add_group деструктор, закрытие формы
     */
    ~add_group();
    /**
     * @brief add_group::clean очищает поля
     */
    void clean();

private slots:
    /**
     * @brief add_group::on_pushButton_clicked добавление группы
     */
    void on_pushButton_clicked();
    /**
     * @brief add_group::no_changes вызов флрмы предупреждения
     */
    void no_changes();

private:
    Ui::add_group *ui;
    cannot_change * changes;
};

#endif // ADD_GROUP_H
