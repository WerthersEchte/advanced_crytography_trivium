# Stream-cypher Trivium with visualization gui

This is a implementation of the stream-cypher Trivium in c++
It is tested trough automated unittests with boost-test and has an extra gui for visualising the inner workings of Trivium

Note for the Tests
The bitstream coming out of Trivium is high endian, while the vector to compare
them with is a bytestream, where the bytes are low endian. This means the tests need
to convert the bitstream to this bytestream to be able to compare them.

To build this project, following is needed:
- C++11 or better compiler
- Cmake 2.8 or better for project build
- Boost unit test for the tests
- QT5.x for the gui

