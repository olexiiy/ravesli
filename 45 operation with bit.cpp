
#include <bitset>
#include <iostream>

// Обратите внимание, используя std::bitset, наши options отвечают порядковым номерам битов, а не их значениям
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8 = 7;

int main()
{
	// Помните, отсчет битов начинается не с 1, а с 0
	std::bitset<8> bits(0x2); // нам нужно 8 бит, начнем с битового шаблона 0000 0010
	bits.set(option_5); // включаем 4-ый бит - его значение меняется на 1 (теперь мы имеем 0001 0010)
	bits.flip(option_6); // меняем значения 5-ого бита на противоположное (теперь мы имеем 0011 0010)
	bits.reset(option_6); // выключаем 5-ый бит - его значение снова 0 (теперь мы имеем 0001 0010)

	std::cout << "Bit 4 has value: " << bits.test(option_5) << '\n';
	std::cout << "Bit 5 has value: " << bits.test(option_6) << '\n';
	std::cout << "All the bits: " << bits << '\n';

	
		const unsigned int lowMask = 0xF; // битовая маска для хранения последних 4 битов (шестнадцатеричный литерал для 0000 0000 0000 1111)

		std::cout << "Enter an integer: ";
		int num;
		std::cin >> num;

		num &= lowMask; // стираем первые биты, чтобы оставить последние 

		std::cout << "The 4 low bits have value: " << num << '\n';


		const unsigned int redBits = 0xFF000000;
		const unsigned int greenBits = 0x00FF0000;
		const unsigned int blueBits = 0x0000FF00;
		const unsigned int alphaBits = 0x000000FF;

		std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
		unsigned int pixel;
		std::cin >> std::hex >> pixel; // std::hex позволяет вводить шестнадцатеричные значения

		// используем побитовое И для изоляции red pixels, затем сдвигаем значение вправо в диапазон 0-255
		unsigned char red = (pixel & redBits) >> 16;
		unsigned char green = (pixel & greenBits) >> 16;
		unsigned char blue = (pixel & blueBits) >> 8;
		unsigned char alpha = pixel & alphaBits;

		std::cout << "Your color contains:\n";
		std::cout << static_cast<int>(red) << " of 255 red\n";
		std::cout << static_cast<int>(green) << " of 255 green\n";
		std::cout << static_cast<int>(blue) << " of 255 blue\n";
		std::cout << static_cast<int>(alpha) << " of 255 alpha\n";
		
	return 0;
}
