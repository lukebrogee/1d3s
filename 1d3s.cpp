#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}

int main() {

    auto expression = 5 / 2.0;
    std::cout << expression;

    int shiftDirection{ 0 };

    std::ifstream input_file{};
    input_file.open("input.txt");
    

    char direction{'a'};
    if (!(input_file >> direction)) {
        std::cout << "Oops: Could not read the direction from the input file.\n";
        return 0;
    }
    
        /*Will move encryption left*/
        if (direction == 'r') {
            shiftDirection = 1;
        }
        /*Will move encryption right*/
        else if (direction == 'l') {
            shiftDirection = -1;
        }
        else {
            std::cout << "Oops: Invalid direction in the input file.\n";
            return 0;
        }

    int number{0};

    if (!(input_file >> number)) {
        std::cout << "Oops: Could not read the shift number from the input file.\n";
        return 0;
    }
    /*Will determine the amount of spaces to move character*/
        int shiftNumber = (shiftDirection * number);
    

    

     while (!std::iscntrl(input_file.peek()) && !input_file.eof()) {
         int positionNegative{};
         char something{ };
         input_file >> something;

         int aNumber = number_from_letter(something);

         int position = aNumber + shiftNumber;

         int remainderPosition = position % 26;

         if (remainderPosition < 0) {
             positionNegative = remainderPosition + 26;
         }
         else {
             positionNegative = remainderPosition;
         }
         
         char finalLetter = letter_from_number(positionNegative);

         std::cout << finalLetter;
        

    }

     std::cout << "\n";

    
    input_file.close();


    return 0;
}