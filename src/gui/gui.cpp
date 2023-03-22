#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../backend/expression.cpp"

parse p;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

        // Create the main window
        QMainWindow mainWindow;

        // Create the label and text field
        QLabel *label = new QLabel("f(x)=");
        QLabel *label2 = new QLabel("Empty");
        QLineEdit *textField = new QLineEdit;

        // Create the submit button
        QPushButton *submitButton = new QPushButton("Plot");

        // Connect the submit button to a slot
        QObject::connect(submitButton, &QPushButton::clicked, [&]() {
            QString text = textField->text();

            //Convert QString to char*
            const char* const_cstr = text.toStdString().c_str();
            char cstr[20];
            strcpy(cstr,const_cstr);
            //Pass String to Intopost
            p.intopost(cstr);
            //Print value of f(x) when x=1
            int fx = p.evalpost(3);
            QString result_str = QString::number(fx);
            // Do something with the text
            label2->setText(result_str);
        });

        // Create the layout
        QVBoxLayout *layout = new QVBoxLayout;
        QHBoxLayout *rowLayout = new QHBoxLayout;
        rowLayout->addWidget(label);
        rowLayout->addWidget(textField);
        layout->addLayout(rowLayout);
        layout->addWidget(submitButton);
        layout->addWidget(label2);

        // Set the layout on the main window
        QWidget *centralWidget = new QWidget;
        centralWidget->setLayout(layout);
        mainWindow.setCentralWidget(centralWidget);

        // Show the main window
        mainWindow.show();

        // Run the event loop
        return app.exec();
}
