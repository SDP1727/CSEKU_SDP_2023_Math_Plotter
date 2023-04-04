#include <cstring>
#include <QMainWindow>
#include <QPalette>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "../backend/plotter.cpp"
plot pl;

QString str = "";
int rng = 1;


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

        QWidget window;

        QLabel *label = new QLabel("f(x)=");

        QLabel *textField = new QLabel("");
            textField->setFixedWidth(300);
            textField->setFrameStyle(QFrame::Box | QFrame::Plain);
            textField->setLineWidth(1);
            textField->setAlignment(Qt::AlignLeft);
            QFont font = textField->font();
                font.setPointSize(15);
                textField->setFont(font);
        QLabel *range = new QLabel(QString::number(rng));
        range->setFixedWidth(25);
        range->setAlignment(Qt::AlignCenter);

        QPushButton *submitButton = new QPushButton("Plot");
        QPalette palette = submitButton->palette();
            palette.setColor(QPalette::Button, QColor(Qt::yellow));
            submitButton->setAutoFillBackground(true);
            submitButton->setPalette(palette);
            submitButton->update();


        QPushButton *variable = new QPushButton("x");
        QPushButton *point = new QPushButton(".");
        QPushButton *power = new QPushButton("^");
        QPushButton *plus = new QPushButton("+");
        QPushButton *divide = new QPushButton("/");
        QPushButton *mul = new QPushButton("*");
        QPushButton *minus = new QPushButton("-");
        QPushButton *brace1 = new QPushButton("(");
        QPushButton *brace2 = new QPushButton(")");
        QPushButton *zero = new QPushButton("0");
        QPushButton *one = new QPushButton("1");
        QPushButton *two = new QPushButton("2");
        QPushButton *three = new QPushButton("3");
        QPushButton *four = new QPushButton("4");
        QPushButton *five = new QPushButton("5");
        QPushButton *six = new QPushButton("6");
        QPushButton *seven = new QPushButton("7");
        QPushButton *eight = new QPushButton("8");
        QPushButton *nine = new QPushButton("9");
        QPushButton *sine = new QPushButton("sin");
        QPushButton *cosine = new QPushButton("cos");
        QPushButton *tangent = new QPushButton("tan");
        QPushButton *logarithm = new QPushButton("log");
        QPushButton *clear = new QPushButton("CLEAR");
        QPushButton *incr = new QPushButton("▲");
        incr->setFixedWidth(35);
        QPushButton *dcr = new QPushButton("▼");
        dcr->setFixedWidth(35);


        QObject::connect(submitButton, &QPushButton::clicked, [&]() {

            const char* const_cstr = str.toStdString().c_str();
            char cstr[20];
            strcpy(cstr,const_cstr);
            pl.setRange(rng);

            pl.startPlot(argc, argv, cstr);
            str.clear();
            textField->setText(str);


        });


        QObject::connect(variable, &QPushButton::clicked,[&](){
            str.append("x");
            textField->setText(str);
        });
        QObject::connect(point, &QPushButton::clicked,[&](){
            str.append(".");
            textField->setText(str);
        });

        QObject::connect(power, &QPushButton::clicked,[&](){
            str.append("^");
            textField->setText(str);
        });

        QObject::connect(plus, &QPushButton::clicked,[&](){
            str.append("+");
            textField->setText(str);
        });

        QObject::connect(divide, &QPushButton::clicked,[&](){
            str.append("/");
            textField->setText(str);
        });

        QObject::connect(mul, &QPushButton::clicked,[&](){
            str.append("*");
            textField->setText(str);
        });

        QObject::connect(minus, &QPushButton::clicked,[&](){
            str.append("-");
            textField->setText(str);
        });

        QObject::connect(brace1, &QPushButton::clicked,[&](){
            str.append("(");
            textField->setText(str);
        });

        QObject::connect(brace2, &QPushButton::clicked,[&](){
            str.append(")");
            textField->setText(str);
        });

        QObject::connect(zero, &QPushButton::clicked,[&](){
            str.append("0");
            textField->setText(str);
        });

        QObject::connect(one, &QPushButton::clicked,[&](){
            str.append("1");
            textField->setText(str);
        });

        QObject::connect(two, &QPushButton::clicked,[&](){
            str.append("2");
            textField->setText(str);
        });

        QObject::connect(three, &QPushButton::clicked,[&](){
            str.append("3");
            textField->setText(str);
        });

        QObject::connect(four, &QPushButton::clicked,[&](){
            str.append("4");
            textField->setText(str);
        });

        QObject::connect(five, &QPushButton::clicked,[&](){
            str.append("5");
            textField->setText(str);
        });

        QObject::connect(six, &QPushButton::clicked,[&](){
            str.append("6");
            textField->setText(str);
        });

        QObject::connect(seven, &QPushButton::clicked,[&](){
            str.append("7");
            textField->setText(str);
        });

        QObject::connect(eight, &QPushButton::clicked,[&](){
            str.append("8");
            textField->setText(str);
        });

        QObject::connect(nine, &QPushButton::clicked,[&](){
            str.append("9");
            textField->setText(str);
        });

        QObject::connect(sine, &QPushButton::clicked,[&](){
            str.append("sin");
            textField->setText(str);
        });

        QObject::connect(cosine, &QPushButton::clicked,[&](){
            str.append("cos");
            textField->setText(str);
        });

        QObject::connect(tangent, &QPushButton::clicked,[&](){
            str.append("tan");
            textField->setText(str);
        });
        QObject::connect(clear, &QPushButton::clicked,[&](){
            str.clear();
            textField->setText(str);
        });
        QObject::connect(incr, &QPushButton::clicked,[&](){
            if(rng < 49)
            {
                rng++;
                range->setText(QString::number(rng));
            }
        });
        QObject::connect(dcr, &QPushButton::clicked,[&](){
            if(rng > 1)
            {
                rng--;
                range->setText(QString::number(rng));
            }
        });








        QVBoxLayout *vLayout1 = new QVBoxLayout;
        QHBoxLayout *hLayout = new QHBoxLayout;
            QHBoxLayout *hLayout1 = new QHBoxLayout;
            QHBoxLayout *hLayout2 = new QHBoxLayout;
            QHBoxLayout *hLayout3 = new QHBoxLayout;
            QHBoxLayout *hLayout4 = new QHBoxLayout;
            QHBoxLayout *hLayout5 = new QHBoxLayout;
            QHBoxLayout *hLayout6 = new QHBoxLayout;
            QHBoxLayout *hLayout7 = new QHBoxLayout;

            // Add the buttons to the layouts
            hLayout->addWidget(label);
            hLayout->addWidget(textField);

            hLayout1->addWidget(sine);
            hLayout1->addWidget(cosine);
            hLayout1->addWidget(tangent);
            hLayout1->addWidget(logarithm);

            hLayout2->addWidget(one);
            hLayout2->addWidget(two);
            hLayout2->addWidget(three);
            hLayout2->addWidget(divide);

            hLayout3->addWidget(four);
            hLayout3->addWidget(five);
            hLayout3->addWidget(six);
            hLayout3->addWidget(mul);

            hLayout4->addWidget(seven);
            hLayout4->addWidget(eight);
            hLayout4->addWidget(nine);
            hLayout4->addWidget(minus);

            hLayout5->addWidget(point);
            hLayout5->addWidget(zero);
            hLayout5->addWidget(power);
            hLayout5->addWidget(plus);

            hLayout6->addWidget(variable);
            hLayout6->addWidget(brace1);
            hLayout6->addWidget(brace2);
            hLayout6->addWidget(clear);


            hLayout7->addWidget(incr);
            hLayout7->addWidget(range);
            hLayout7->addWidget(dcr);
            hLayout7->addWidget(submitButton);


            vLayout1->addLayout(hLayout);
            vLayout1->addLayout(hLayout1);
            vLayout1->addLayout(hLayout2);
            vLayout1->addLayout(hLayout3);
            vLayout1->addLayout(hLayout4);
            vLayout1->addLayout(hLayout5);
            vLayout1->addLayout(hLayout6);
            vLayout1->addLayout(hLayout7);


        window.setLayout(vLayout1);

        window.show();

        return app.exec();
}
