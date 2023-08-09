#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    QVBoxLayout layout;

    QLabel keyLabel;
    QLabel valueLabel;

    QFile file("C:/StudyFolder/ApplicationProgramming/14_1/test/config.ini");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isNull()) {
            QStringList parts = line.split("=");
            if (parts.size() == 2) {
                QString key = parts.at(0).trimmed();
                QString value = parts.at(1).trimmed();
                keyLabel.setText("Key: " + key);
                valueLabel.setText("Value: " + value);
                int ivalue = value.toInt();
                window.resize(200, ivalue);
            }
            line = in.readLine();
        }
        file.close();
    } else {
        qDebug() << "Failed to open file!";
    }

    layout.addWidget(&keyLabel);
    layout.addWidget(&valueLabel);

    window.setLayout(&layout);
    window.show();

    return app.exec();
}
