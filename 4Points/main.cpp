#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter usind function distance 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD

QString printQuad(Point Array[4]);
QString printQuad(Point Array[4])
{
    Point current;
    QString qsTemp;
    QString qsRetVal = "Quadrilateral with points: ";
    for (int i=0; i < 4; i++) {
        current = Array[i];
        qsTemp = "%1[%2;%3] ";
        qsTemp = qsTemp.arg(current.Name).arg(current.x).arg(current.y);
        qsRetVal.append(qsTemp);
    }
    qsTemp = "\r\nHas perimeter %1 and area %2\r\n";
    qsTemp = qsTemp.arg(perimeter(Array)).arg(area(Array));
    qsRetVal.append(qsTemp);
    return qsRetVal;
}

float distance(Point A, Point B)
{
    int distance;
    distance = sqrt(pow(B.x-A.x, 2) + pow(B.y-A.y, 2));
    return distance;
}

float perimeter(Point Array[4])
{
    float AB, BC, CD, DA, perimeter;
    AB = distance(Array[0], Array[1]);
    BC = distance(Array[1], Array[2]);
    CD = distance(Array[2], Array[3]);
    DA = distance(Array[0], Array[3]);
    perimeter = AB+BC+CD+DA;
    return perimeter;
}

float area(Point Array[4])
{
    float AB,BC,CD,DA,di,p1,p2,area1,area2,area12;
    AB = distance(Array[0], Array[1]);
    BC = distance(Array[1], Array[2]);
    CD = distance(Array[2], Array[3]);
    DA = distance(Array[0], Array[3]);
    di = sqrt(2) * AB;
    p1 = (AB+BC+di)/2;
    p2 = (CD+DA+di)/2;
    area1 = sqrt(p1*(p1-AB)*(p1-BC)*(p1-di));
    area2 = sqrt(p2*(p2-CD)*(p2-DA)*(p2-di));
    area12 = area1+area2;
    return area12;
}

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);
    qDebug () <<"Homework: 4Points";
    Point quadOne[4];
    quadOne[0].Name='A';
    quadOne[0].x=-0.0;
    quadOne[0].y=-0.0;

    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=-0.0;

    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;

    quadOne[3].Name='D';
    quadOne[3].x=-0.0;
    quadOne[3].y=4.0;

    Point QE[4];
    QE[0].Name='Q';
    QE[0].x=-10;
    QE[0].y=-10;

    QE[1].Name='W';
    QE[1].x=10;
    QE[1].y=-10;

    QE[2].Name='E';
    QE[2].x=10;
    QE[2].y=10;

    QE[3].Name='R';
    QE[3].x=-10;
    QE[3].y=10;

    QFile file("PointsInFile.txt");
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writeStream(&file);
        writeStream << printQuad(quadOne);
        writeStream << printQuad(QE);
        file.close();
        qDebug () <<"Open 'PointsInfile.txt' in build directory!";
    }

    return /*a.exec*/(0);
}


