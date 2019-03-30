#ifndef TYPEPARMI_H
#define TYPEPARMI_H



#include <QString>
#include <QDateTime>

class TypeParmi
{
private:
    int idTypeParmi;
    QString typeName;
public:
    TypeParmi();
    ~TypeParmi();

    int getIdTypeParmi() const { return this->idTypeParmi; }
    QString getTypeName() const { return this->typeName; }
    void setIdTypeParmi(int id) { idTypeParmi = id; }
    void setTypeName(QString str) { typeName = str; }
};

#endif // TYPEPARMI_H
