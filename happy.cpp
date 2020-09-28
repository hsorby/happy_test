
#include "happy.h"

#include <iostream>

ExpressionPair Expression::twoFace(bool isNull)
{
    auto smile1 = std::make_shared< Smile >();
    auto smile2 = std::make_shared< Smile >();

    return isNull ? std::make_pair(nullptr, nullptr) : std::make_pair(smile1, smile2);
}

void Smile::perform() const
{
    std::cout << ":)" << std::endl;
}
