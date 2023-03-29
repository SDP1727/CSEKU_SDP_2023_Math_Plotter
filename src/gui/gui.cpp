#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "../backend/plotter.cpp"
plot pl;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

        QMainWindow mainWindow;

        QLabel *label = new QLabel("f(x)=");
        QLineEdit *textField = new QLineEdit;

        QPushButton *submitButton = new QPushButton("Plot");

        QObject::connect(submitButton, &QPushButton::clicked, [&]() {
            QString text = textField->text();

            const char* const_cstr = text.toStdString().c_str();
            char cstr[20];
            strcpy(cstr,const_cstr);

            pl.startPlot(argc, argv, cstr);


        });

        QVBoxLayout *layout = new QVBoxLayout;
        QHBoxLayout *rowLayout = new QHBoxLayout;
        rowLayout->addWidget(label);
        rowLayout->addWidget(textField);
        layout->addLayout(rowLayout);
        layout->addWidget(submitButton);

        QWidget *centralWidget = new QWidget;
        centralWidget->setLayout(layout);
        mainWindow.setCentralWidget(centralWidget);

        mainWindow.show();

        return app.exec();
}
