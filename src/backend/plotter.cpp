#include <GL/glut.h>
#include <cmath>

//float ns =2;

char expression[200];
char post[200][10];
char stack[200][10];
char fstack[100];
int ftop = -1;
int stackTop = -1;
int postInd = -1;
double evalstack[200];
int floattop = -1;



class plot {

    void pushfloat(double val) {
        floattop++;
        evalstack[floattop] = val;
    }
    double popfloat() {
        return evalstack[floattop--];
    }
    void push(char ele[]) {
        stackTop++;
        strcpy(stack[stackTop], ele);
    }
    int priority(char op) {
        switch (op) {
            case '+':
                return 0;
                break;
            case '-':
                return 0;
                break;
            case '*':
                return 1;
                break;
            case '/':
                return 1;
                break;
            case '^':
                return 2;
                break;
            case '(':
                return -1;
                break;
        }
        return 0;
    }
    int intopost(char exp[]) {
        strcpy(expression, exp);
        //scanf("%s",expression);
        int i, numInd = 0;
        int len = strlen(expression);
        int unary = 1;
        char pushE[10];
        for (i = 0; i<len; i++) {
            if (isdigit(expression[i]) || expression[i] == '.') {
                if (numInd == 0) {
                    pushE[0] = '+';
                    pushE[1] = expression[i];
                    numInd = 2;
                }
                else {
                    pushE[numInd] = expression[i];
                    numInd++;
                }
                unary = 0;
            }
            else if (expression[i] == ' ') {
                continue;
            }
            else if (expression[i] == 'x') {
                if (numInd == 0) {
                    pushE[0] = '+';
                }
                pushE[1] = expression[i];
                pushE[2] = '\0';
                strcpy(post[++postInd], pushE);
                unary = 0;
                numInd = 0;
            }
            else {
                if (numInd>0) {
                    pushE[numInd] = '\0';
                    numInd = 0;
                    strcpy(post[++postInd], pushE);
                }
                if (expression[i] == '(') {
                    if (stack[stackTop][0] == '$') {
                        stackTop--;
                    }
                    pushE[0] = expression[i];
                    pushE[1] = '\0';
                    push(pushE);
                    unary = 1;
                }
                else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
                    if ((expression[i] == '+' || expression[i] == '-') && unary == 1) {
                        pushE[0] = expression[i];
                        numInd = 1;
                    }
                    else {
                        if (stackTop == -1) {
                            pushE[0] = expression[i];
                            pushE[1] = '\0';
                            push(pushE);
                        }
                        else if (stack[stackTop][0] == '(') {
                            pushE[0] = expression[i];
                            pushE[1] = '\0';
                            push(pushE);
                        }
                        else {
                            while (stack[stackTop][0] == '+' || stack[stackTop][0] == '-' || stack[stackTop][0] == '*' || stack[stackTop][0] == '/' || stack[stackTop][0] == '^') {
                                if (stackTop == -1) {
                                    break;
                                }
                                if (priority(stack[stackTop][0])<priority(expression[i])) {
                                    break;
                                }
                                else {
                                    postInd++;
                                    strcpy(post[postInd], stack[stackTop]);
                                    stackTop--;
                                }
                            }
                            pushE[0] = expression[i];
                            pushE[1] = '\0';
                            push(pushE);
                        }
                    }
                    unary = 1;
                }
                else if (expression[i] == 's' || expression[i] == 'c' || expression[i] == 'l' || expression[i] == 't') {
                    if (numInd == 0) {
                        pushE[0] = '+';
                    }
                    pushE[1] = expression[i];
                    pushE[2] = '\0';
                    push(pushE);
                    pushE[0] = '$';
                    pushE[1] = '\0';
                    push(pushE);

                }
                else if (expression[i] == ')') {
                    unary = 1;
                    printf("%s", stack[stackTop]);
                    while (stack[stackTop][0] != '(') {
                        postInd++;
                        if (stackTop>-1) {
                            strcpy(post[postInd], stack[stackTop]);
                        }
                        stackTop--;
                    }
                    if (stackTop>-1) {
                        //printf("pop");
                        stackTop--;
                    }
                }
                if (stack[stackTop][1] == 's') {
                    strcpy(post[++postInd], stack[stackTop]);
                    stackTop--;
                    unary = 0;
                }

            }
        }
        if (numInd>0) {
            pushE[numInd] = '\0';
            numInd = 0;
            strcpy(post[++postInd], pushE);
        }
        while (stackTop>-1) {
            postInd++;
            strcpy(post[postInd], stack[stackTop]);
            stackTop--;
        }
        return 0;
    }
    double op(double f1, double f2, char o) {
        switch (o) {
            case '+':
                return f1 + f2;
                break;
            case '-':
                return f1 - f2;
                break;
            case '*':
                return f1*f2;
                break;
            case '/':
                return f1 / f2;
                break;
            case '^':
                return pow(f1, f2);
                break;
        }
        return 0;

    }
    double func(char op, double x) {
        switch (op) {
            case 's':
                return sin(x);
                break;
            case 'c':
                return cos(x);
                break;
            case 't':
                return tan(x);
                break;
            case 'l':
                return log(x);
                break;
        }
        return 0;
    }
    double evalpost(double x) {
        float val;
        int i;
        for (i = 0; i <= postInd; i++) {
            if ((post[i][0] == '+' || post[i][0] == '-') && strlen(post[i])>1) {
                if (post[i][1] == 's' || post[i][1] == 'c' || post[i][1] == 'l' || post[i][1] == 't') {
                    if (post[i][0] == '+') {
                        pushfloat(func(post[i][1], evalstack[floattop--]));
                    }
                    else if (post[i][0] == '-') {
                        pushfloat(-1 * func(post[i][1], evalstack[floattop--]));
                    }
                }
                else if (post[i][1] == 'x') {
                    if (post[i][0] == '+') {
                        pushfloat(x);
                    }
                    else if (post[i][0] == '-') {
                        pushfloat(-1 * x);
                    }
                }
                else {
                    pushfloat(strtof(post[i], NULL));
                }

            }
            else if (post[i][0] == '+' || post[i][0] == '-' || post[i][0] == '*' || post[i][0] == '/' || post[i][0] == '^') {
                float f1, f2, f;
                if (floattop<1) {
                    throw std::runtime_error("Invalid Expression.");
                }
                f2 = popfloat();
                f1 = popfloat();
                f = op(f1, f2, post[i][0]);
                pushfloat(f);
            }
        }
        val = popfloat();
        if (floattop != -1) {
            throw std::runtime_error("Invalid Expression.");
        }
        return val;
    }

    void drawAxes() {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        // x-axis
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
        // y-axis
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
        glEnd();
    }

    void drawFunction() {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
        for (float x = -1.0; x <= 1.0; x += 0.01) {
            glVertex2f(x, evalpost(x));
        }
        glEnd();
    }

    static void displayPlot() {
        plot thisP;
        glClear(GL_COLOR_BUFFER_BIT);
        thisP.drawAxes();
        thisP.drawFunction();
        glFlush();
    }

    public :int startPlot(int argc, char** argv, char exp[]) {
        intopost(exp);

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("Function Plotter");

        glClearColor(1.0, 1.0, 1.0, 1.0);
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

        glutDisplayFunc(displayPlot);

        glutMainLoop();

        return 0;
    }

};


