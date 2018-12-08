mkdir $1
cd $1
for (( i=1; $i < 8; i=i+1 )); do
    touch $i.cpp
    cat ../szablon.cpp > $i.cpp
done
touch test.in
touch run.sh
chmod +x run.sh
cat ../skr.sh > run.sh