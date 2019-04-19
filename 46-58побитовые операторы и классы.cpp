// Example program
#include <iostream>
#include <string>
#include <bitset>
int main()
{
enum class Options{
	isHungry = 0x01, // шестнадцатеричный литерал для 0000 0001
	isSad = 0x02, // шестнадцатеричный литерал для 0000 0010
	isMad = 0x04, // шестнадцатеричный литерал для 0000 0100
	isHappy = 0x08, // шестнадцатеричный литерал для 0000 1000
	isLaughing = 0x10, // шестнадцатеричный литерал для 0001 0000
	isAsleep = 0x30, // шестнадцатеричный литерал для 0010 0000
	isDead = 0x40, // шестнадцатеричный литерал для 0100 0000
	isCrying = 0x80  // шестнадцатеричный литерал для 1000 0000
};
 
unsigned char me{ 0 };
me |= (static_cast<int>(Options::isHappy) | static_cast<int>(Options::isLaughing)); // Включить 1 и 5 опции (0001 0001)


std::bitset me<8> (0x00);

   
/*	// Запрашиваем сразу несколько состояний (мы будем использовать static_cast<bool> для конвертации результатов в значения типа bool)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
	
	std::cout << "Bit 4 has value: " << bits.test(option_5) << '\n';
    std::cout << "Bit 5 has value: " << bits.test(option_6) << '\n';
    */
    std::cout << "All the bits: " << bits << '\n';
 
	return 0;
	

}
