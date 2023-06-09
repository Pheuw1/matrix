#!/bin/bash

#if there is an argument, assume it is the number of the file to test
if [ $# -eq 1 ]; then

    if [ $1 -eq 14 ]; then
        make
        ./display
        rm display

    else
        echo "Running ex$(printf "%02d" $1).cpp ..."
        g++ -o  tests/ex$(printf "%02d" $1) tests/ex$(printf "%02d" $1).cpp -I./
        ./tests/ex$(printf "%02d" $1)
        rm tests/ex$(printf "%02d" $1)
    fi

else

    for ((i=0; i<=15; i++)); do
        clear
        f="tests/ex$(printf "%02d" $i)" 
        
        if [ $i -eq 14 ]; then
            make
            ./display
        else
            echo "Running $f.cpp ..."
            g++ -o  $f $f.cpp -I./
        fi


        if [ $? -eq 0 ] && [ "$i" != 14 ]; then
            ./$f 

            read -p "Press enter to continue..."
            rm $f
        else
            echo "Compilation of ex$(printf "%02d" $i) failed. Skipping..."
        fi
    done

fi
