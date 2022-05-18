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
cmake ..
echo "run cmake"
make
echo "run make"
cd ..

# add terminal you use if you dont have
# mate-terminal
pwd

cd build/app/emulator/ && gnome-terminal --geometry 50x12+0-0 -e ./emulator &
echo "open emulator terminal"
cd build/app/input_handler/ && gnome-terminal --geometry 60x12+430-0 -e ./input_handler &
echo "open input_handler terminal"
cd build/app/output_display/ && gnome-terminal --geometry 60x12+930-0   --command="./avic -c engineCAN" &
echo "open output display"
gnome-terminal  --geometry 60x12-0-0 --command="candump engineCAN" &
