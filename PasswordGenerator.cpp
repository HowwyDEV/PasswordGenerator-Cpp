#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


char randomChar() {
    const std::string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int index = rand() % charSet.length();
    return charSet[index];
}


std::string generatePassword(int length, bool includeSpecialChars) {
    std::string password;
    const std::string specialChars = "!@#$%^&*()";

    for (int i = 0; i < length; ++i) {
        if (includeSpecialChars && rand() % 2 == 0) {
            password += specialChars[rand() % specialChars.length()];
        } else {
            password += randomChar();
        }
    }
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int passwordLength;
    std::cout << "Podaj dlugosc hasla: ";
    std::cin >> passwordLength;

    char includeSpecialChars;
    std::cout << "Czy haslo ma zawierac znaki specjalne? (T/N): ";
    std::cin >> includeSpecialChars;

    bool shouldIncludeSpecialChars = (includeSpecialChars == 'T' || includeSpecialChars == 't');

    std::string password = generatePassword(passwordLength, shouldIncludeSpecialChars);
    std::cout << "Wygenerowane haslo: " << password << std::endl;

    return 0;
}
