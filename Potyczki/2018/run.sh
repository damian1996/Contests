g++ -std=c++14 -O2 -g $1.cpp -o ex
for((j=0;j<20;++j)); 
do
    #for((i=1;i<7;++i));do ulimit -v 4096; ./ex < pal_tests/$i.in > out; diff -w out pal_tests/$i.out; done
    #python3 gen.py > paltests/test$j.in;
    ./ex < paltests/test$j.in > paltests/test$j.out
    #cat test.in;
done

#for((i=0;i<15;++i));do ./ex < kon_tests/kon$i.in > out; diff -w out kon_tests/kon$i.out;done
