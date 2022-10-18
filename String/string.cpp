// Персональный шаблон
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>//библиотека позволяющая работать с классом string
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void show_arr(T arr[], const int length);
std::string repeat_str(std::string str,int num);
bool is_spam(std::string str);
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//строковые массивы
	/*
	char char_str[4]{ 'H','i','!','\0'};
	for (int i = 0; i < 4; i++)
		std::cout << char_str[i];
	std::cout << '\n';
	std::cout << char_str << '\n';
	char char_str2[]{ "Helo world!" };
	std::cout << char_str2 << '\n';
	std::cout << char_str2[3] << '\n';
	*/
	//строковые переменные
	/*
	std::string str;//создание строковой переменной типа string //всегда получает эффект пустой строки
	str = "привет мир";
	std::cout << str << '\n';
	str += "\n пока!";//конкатенация
	std::cout << str+" wow" << '\n';
	*/
	//ввод строки
	/*
	std::string name;
	std::cout << "Введите имя:";
	//std::cin >> name;//ввод до близжайшего разделителя
	std::getline(std::cin, name);//ввод до конца строки
	std::cout << "Привет " << name << '\n';
	short age;
	std::cout << "введите возраст:";
	std::cin >> age;
	std::cin.ignore();// очистка потока input stream
	std::cout <<age << "wow" << '\n';
	std::cout << "Введите должность:";
	std::string pos;
	getline(std::cin, pos);
	std::cout << "всегда хотел быть!" << pos << '\n';
	std::cout << "Пока мистер, " << name[0] << '\n';
	*/
	//методы
	
	std::string str1 = "hello world!";
	/*
	//методы length и size. Возвращают длинну строки
	std::cout << str1.length() << '\n';
	std::cout << str1.size() << '\n';
	//метод .insert() Вставка содержимого внутрь строки
	str1.insert(3, "))");
	std::cout << str1 << '\n';
	// метод .replace - замена части строки новый содержимым
	str1.replace(6, 3, "ll");
	std::cout << str1 << "\n";
	//метод find-поиск первого вхожденипя подстраки в строку (возвращает индекс)
	std::cout << str1.find("or") << '\n';
	std::cout << str1.find("l", 5);
	//метод rfind()- поиск последнего вхождения подстроки в строку
	std::cout << str1.rfind("ora") << "\n";// возвращает мусор
	// метод substr
	std::cout << str1.substr(3) << "\n";//возвращает подстроку начиинающиюся с переданной позиции
	std::cout << str1.substr(3, 5) << "\n";//возвращает подстроку начинающиюся с 3 позиции длинной 5 символов
	*/
	//функции
	//число в строку
	/*
	std::cout << "Введите число: ";
	std::cin>>n;
	str1 = std::to_string(n);
	std::cout << str1 + '\n';
	*/
	//строка в число
	/*
	std::cout << "введите число:";
	getline(std::cin, str1);
	int num = stoi(str1);
	num++;
	std::cout << num << '\n';
	*/
	//toupper переводит в верхний регистер
	/*for (int i = 0; i < str1.length(); i++)
		str1[i] = toupper(str1[i]);
	std::cout << str1 << "\n";
	*/
	//toulower  в нижний регистр
	/*
	for (int i = 0; i < str1.length(); i++)
		str1[i] = tolower(str1[i]);
	std::cout << str1 << "\n";
	*/
	//Задача 1.повторение строки
	/*
	std::cout << "Введите строку:";
	getline(std::cin, str1);
	std::cout << repeat_str(str1, 4)<<'\n';
	*/
	//Задача 3 . поиск спама
	std::cout << "введите сообщение:";
	getline(std::cin, str1);
	if (is_spam(str1))
		std::cout << "обнаружен спам!\n";
	else
		std::cout << "спама необнаружено\n";
	return 0;
	
}
//возвращает строку указаное количество раз
std::string repeat_str(std::string str, int num){
	std::string tmp;
	for (int i = 0; i < num; i++)
		tmp += str;
	return tmp;
}
//заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//ищет спам в строке
bool is_spam(std::string str) {
	for (int i = 0; i > str.length(); i++)
		str[i] = tolower(str[i]);
	std::string spams[3]{ 
		"100% free",
		"sales increase",
		"only today"};
	for (int i = 0; i < 3; i++)
		if (str.find(spams[i]) < str.length())
			return true;
	return false;
}
