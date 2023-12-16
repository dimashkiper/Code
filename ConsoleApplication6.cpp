class Car {
private:
	int speed;
	int direction;

public:
	void Accelerate(int amount) { speed += amount; }
	void Turn(int degrees) { direction += degrees; }
	int GetSpeed() { return speed; }
	int GetDirection() { return direction; }
};


class SportsCar : public Car {
public:
	void Accelerate(int amount) {
		if (speed + amount <= Car::MAX_SPEED) {
			speed += amount;
		}
		else {
			speed = Car::MAX_SPEED;
		}
	}
};

class Car {
public:
	virtual void Accelerate() = 0;
};

class SportsCar : public Car {
public:
	void Accelerate() override {
		speed += 20;
	}
};

class RegularCar : public Car {
public:
	void Accelerate() override {
		speed += 10;
	}
};

#include <algorithm>
#include <iostream>

using namespace std;

struct Car {
	string brand;
	string model;
	int year;
};

bool compare_by_brand(const Car& a, const Car& b) {
	return a.brand < b.brand;
}

int main() {
	Car cars[] = {
	  {"BMW", "M5", 2023},
	  {"Mercedes-Benz", "C-Class", 2022},
	  {"Audi", "A4", 2021},
	};

	sort(cars, cars + 3, compare_by_brand);

	for (const Car& car : cars) {
		cout << car.brand << " " << car.model << " " << car.year << endl;
	}

	return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;

struct Car {
	string brand;
	string model;
	int year;
};

bool compare_by_brand_and_year(const Car& a, const Car& b) {
	int result = a.brand.compare(b.brand);
	if (result == 0) {
		return a.year < b.year;
	}
	return result < 0;
}

int main() {
	Car cars[] = {
	  {"BMW", "M5", 2023},
	  {"Mercedes-Benz", "C-Class", 2022},
	  {"Audi", "A4", 2021},
	};

	sort(cars, cars + 3, compare_by_brand_and_year);

	for (const Car& car : cars) {
		cout << car.brand << " " << car.model << " " << car.year << endl;
	}

	return 0;
}
#include <QtWidgets>

int main() {
	QApplication a(argc, argv);

	QWidget w;
	w.resize(500, 500);

	QTableWidget* table = new QTableWidget(w);
	table->setRowCount(3);
	table->setColumnCount(3);

	table->setHorizontalHeaderLabels({ "Марка", "Модель", "Рік випуску" });

	Car cars[] = {
	  {"BMW", "M5", 2023},
	  {"Mercedes-Benz", "C-Class", 2022},
	  {"Audi", "A4", 2021},
	};

	for (int i = 0; i < 3; ++i) {
		table->setItem(i, 0, new QTableWidgetItem(cars[i].brand));
		table->setItem(i, 1, new QTableWidgetItem(cars[i].model));
		table->setItem(i, 2, new QTableWidgetItem(QString::number(cars[i].year)));
	}

	w.show();

	return a.exec();
}


QDialog dialog;


QComboBox* comboBox = new QComboBox(dialog);
comboBox->addItems({ "brand", "model", "year" });
comboBox->setGeometry(QRect(10, 10, 200, 25));


QPushButton* button = new QPushButton(dialog, "Сортувати");
button->setGeometry(QRect(220, 10, 100, 25));


connect(button, &QPushButton::clicked, [&]() {
	
	const QString& property = comboBox->currentText();

	
	std::sort(cars.begin(), cars.end(), [property](const Car& a, const Car& b) {
		return a[property] < b[property];
		});
	});


dialog.exec();


QDialog dialog;


QComboBox* comboBox = new QComboBox(dialog);
comboBox->addItems({ "brand", "model", "year" });
comboBox->setGeometry(QRect(10, 10, 200, 25));


QPushButton* button = new QPushButton(dialog, "Сортувати");
button->setGeometry(QRect(220, 10, 100, 25));


connect(button, &QPushButton::clicked, [&]() {
	
	std::sort(cars.begin(), cars.end(), [property](const Car& a, const Car& b) {
		return a[property] < b[property];
		});

	
	dialog.setWindowTitle("Властивості сортування");
	for (const std::string& property : properties) {
		comboBox->addItem(property);
	}
	dialog.exec();
	});


dialog.exec();

