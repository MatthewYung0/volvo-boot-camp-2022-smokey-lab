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

cd build/app/emulator/ && mate-terminal -e ./emulator &
echo "open emulator terminal"
cd build/app/input_handler/ && mate-terminal  -e ./input_handler &
echo "open input_handler terminal"
cd build/app/output_display/ && mate-terminal  --command="./avic -c engineCAN" &
echo "open output display"
