#ifndef GRIPPERBOTSTRUCTURES_H
#define GRIPPERBOTSTRUCTURES_H

#include <QStack>
namespace GripperStructures {

    struct PlatformStruct {
        QPushButton* thePlatform;
        int platformNumber;
        QStack<int> platformStack;
    };
}
#endif // GRIPPERBOTSTRUCTURES_H
