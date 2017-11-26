# sizeConversionso
Simple helper C++ library to format an integer containing a value in bytes into a std::string i.e.: 1023 -> "1023 B", 1024 -> "1 MB"...
Uses the 1024 base (no 1024 * 1000)
Allows 1-4 "decimals", it chops (no rounding)

Compilation
-----------
Requires qmake (not the full Qt library).

Run (in sizeConversionso source directory or pointing to it):

    qmake

and then:

    make
