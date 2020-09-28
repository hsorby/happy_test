
Happy Test
==========

Simple test to try and figure out how to get SWIG to do what I want.

Running
-------

This test uses CMake to create the build commands.
The following are the instructions for running the code on macOS or GNU/Linux for Windows changes will need to be made::

  git clone git@github.com:hsorby/happy_test.git
  mkdir build
  cd build
  cmake ../happy_test
  make
  python3 ../happy_test/test.py

Output
------

::

  :)
  b first is None.

This is the output that I am looking for.

Problem
-------

The problem that I have is that the `ExpressionPair` type appears in the `happy.py` file while I would like it to appear in the `projecttypes.py` file.
On line 11 of `happy.i` I have decalared the following template::

  %template(ExpressionPair) std::pair<SmilePtr, SmilePtr>;

Which works.
However I get the `ExpressionPair` class defined in the `happy.py` file while what I want is for the `ExpressionPair` class to be defined in the `projecttypes.py` file.
But, if I comment out line 11 in `happy.i` and instead define the template on line 15 of `projecttypes.i` I do not get the correct output that I get above.

