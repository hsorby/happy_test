
#pragma once

#include <memory>
#include <utility>

class Smile;
using SmilePtr = std::shared_ptr<Smile>;

class Expression;
using ExpressionPair = std::pair<SmilePtr, SmilePtr>;
