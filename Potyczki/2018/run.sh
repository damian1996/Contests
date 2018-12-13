g++ -std=c++14 -O2 -g $1.cpp -o ex
./ex < test.in
./2B < test.in
#for((i=0;i<15;++i));do ./ex < kon_tests/kon$i.in > out; diff -w out kon_tests/kon$i.out;done
