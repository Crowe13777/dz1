#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем имена для RadioButton
        ui->radioButton->setText("Вариант 1");
        ui->radioButton_2->setText("Вариант 2");

        // Добавляем элементы в выпадающий список (не больше 10)
        ui->comboBox->addItems({
            "Элемент 1",
            "Элемент 2",
            "Элемент 3",
            "Элемент 4",
            "Элемент 5"
        });

        // Изменяем надпись на кнопке
        ui->pushButton->setText("Увеличить прогресс");

        // Меняем тип кнопки на Toggle
        ui->pushButton->setCheckable(true);

        // Настраиваем прогресс-бар: мин = 0, макс = 100, текущее = 0
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(100);
        ui->progressBar->setValue(0);
    }
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        // Получаем текущее значение прогресс-бара
        int currentValue = ui->progressBar->value();

        // Увеличиваем на 10%
        currentValue += 10;

        // Если значение превысило 100%, сбрасываем на 0
        if (currentValue > 100) {
            currentValue = 0;
        }

        // Обновляем значение прогресс-бара
        ui->progressBar->setValue(currentValue);

}

