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

};

#endif // TYPEPARMI_H
