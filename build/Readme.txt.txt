//Tool description
Class IntentRecognition is used to recognize and print the intent of the input given by user.

It has two member functions.
1. PrepareIntent() : This function is used to prepare the data required to classify the input.
                  map STL has been used to store the data. 
                  Here Key is the Intent and Value is the regular expression of the Intent.

2. Extract Intent() : This function is used to extract the intent from the given input string.




//Build

code should be built with below commands.
$cd build
$cmake ..
$make
$./build "input string"  




//Unit test

IntentTests.cpp file contains Gtest cases for the functions of class IntentRecognition.

