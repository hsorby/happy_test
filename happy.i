%module(package="charles") happy

%import "projecttypes.i"

%{
#include "happy.h"
%}

%include "happy.h"

%template(ExpressionPair) std::pair<SmilePtr, SmilePtr>;
