%module(package="charles") projecttypes


%include <std_pair.i>
%include <std_shared_ptr.i>

%shared_ptr(Smile)

%{
#include "projecttypes.h"
%}

%include "projecttypes.h"

//%template(ExpressionPair) std::pair<SmilePtr, SmilePtr>;
