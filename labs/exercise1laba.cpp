	#include <iostream>
#include <string>
using namespace std;
int main(){
    
    //Задание 1. Работа с отладчиком. Базовые типы данных. Выполняя программу по шагам, 
	//следите за значениями переменных и интерпретируйте результат (помните, что 
	//количество байт, отводимых под int, системо-зависимо).
	//Обратите внимание на разную интерпретацию отладчиком signed и unsigned целых типов 
	//данных, а также на внутреннее представление отрицательных целых чисел.

	
	char cByte = 'A';
	cByte    = 0x42; 
	cByte    = 66;  
	cByte    = -1;   

	unsigned char ucByte = 0x41; 
	ucByte   = 'B';
	ucByte   =	-1; 

	int iInt =  0xffffffff; 

	unsigned int uiInt = 0xffffffff; 

	float fFloat = 1.f;  
	double dDouble = 1.; 

	// Выполните фрагмент, приведенный далее. В комментариях отразите,
	// что реально заносится в переменную. Объясните разницу между этим 
	// значением и инициализатором.

	double float d = 0.1234567890123456789123456789; //0.0.1234567890123456789123456789
	float  f = 0.1234567890123456789123456789; //0.123457 у double больше размер памяти
    // cout << d << endl;
      

	d	=	1.; //1

	d	=	0.999999999999999999999999999999999; //1

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t n = sizeof(cw); 
     // cout << "size cw (wchar_t): " << n << L" byte" << endl; : 20x40507e
}