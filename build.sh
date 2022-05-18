####################################
# Script to build all files
####################################
# Make the bash program executable
# by +x (adding execute permission to all)
# chmod +x *.sh
####################################
#!/bin/bash

mkdir build
echo "create directory"
cd build
echo "move into build"
cmake -DCMAKE_BUILD_TYPE=Debug ..
echo "run cmake"
make
echo "run make"
cd ..

# add terminal you use if you dont have
# mate-terminal
pwd

cd build/app/emulator/ && gnome-terminal --geometry 50x12+0-0 --command="valgrind --leak-check=yes --log-file=valgrind_emulator.txt ./emulator" &
echo "open emulator terminal"
cd build/app/input_handler/ && gnome-terminal --geometry 60x12+430-0 --command="valgrind --leak-check=yes --log-file=valgrind_input_handler.txt ./input_handler" &
echo "open input_handler terminal"
cd build/app/output_display/ && gnome-terminal --geometry 60x12+930-0   --command="./avic -c engineCAN" &
echo "open output display"
gnome-terminal  --geometry 60x12-0-0 --command="candump engineCAN" &
