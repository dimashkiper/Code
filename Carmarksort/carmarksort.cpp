#include <QtWidgets>

struct Car {
    QString brand;
    QString model;
    int year;
};

bool compareCars(const Car& car1, const Car& car2) {
    return car1.brand < car2.brand;
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // Створюємо вектор автомобілів
    std::vector<Car> cars = {
      {"BMW", "M5", 2023},
      {"Mercedes-Benz", "C-Class", 2022},
      {"Audi", "A4", 2021},
    };

    // Сортуємо вектор за маркою машини
    std::sort(cars.begin(), cars.end(), compareCars);

    QWidget w;
    w.resize(500, 500);

    QTableWidget* table = new QTableWidget(&w);
    table->setRowCount(3);
    table->setColumnCount(3);

    table->setHorizontalHeaderLabels({ "Марка", "Модель", "Рік випуску" });

    for (int i = 0; i < 3; ++i) {
        table->setItem(i, 0, new QTableWidgetItem(cars[i].brand));
        table->setItem(i, 1, new QTableWidgetItem(cars[i].model));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(cars[i].year)));
    }

    w.show();

    return a.exec();
}
