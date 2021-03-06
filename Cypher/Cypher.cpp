// Cypher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <openssl\aes.h>
#include <openssl/conf.h>
#include <openssl/evp.h> //сами криптографические функции http://wiki.openssl.org/index.php/EPV
#include <openssl/err.h> //коды внутренних ошибок OpenSSL и их расшифровка
using namespace std;

int main()
{	
	//как правило, в литературе, структуры использутся для хранения только данных
	//ни слова о методах и конструкторах/деструкторах
	struct name_of_my_struct
	{
		name_of_my_struct()
		{

		}
		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char *text = (unsigned char *)"Some text Some text Some text Some text";//исходный текст
	int text_lenght = strlen((char *)text);//длина текста
	unsigned char *key = (unsigned char *)"0123456789";//пароль
	unsigned char *vect = (unsigned char *)"01234567890123456789";//инициализирующий вектор
	unsigned char cryptedtext[256];
	unsigned char decryptedtext[256];

	//1.создается указатель на несуществующую структуру
	EVP_CIPHER_CTX *ctx;//structure;

	//2.для указателя создается пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new();//создание структуры с настройками метода
	
	//3.cтруктура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, vect);

	//4.сам процесс шифрования — функция EVP_EncryptUpdate
	int lenght;
	EVP_EncryptUpdate(ctx, cryptedtext, &lenght, text, text_lenght);
	int cryptedtext_lenght = lenght;

	//5.финализация процесса шифрования
	EVP_EncryptFinal_ex(ctx, cryptedtext + lenght, &lenght);
	cryptedtext_lenght += lenght;

	//6.удаление структуры
	EVP_CIPHER_CTX_free(ctx);
	for (int i = 0; i < cryptedtext_lenght; i++)
	{
		cout << hex << (unsigned int *)cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	/*BIO_dump_fp(stdout, (const char *)cryptedtext, cryptedtext_lenght - 1);*/

	//1.
	ctx = EVP_CIPHER_CTX_new(); 

	//2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, vect);

	//3.
	EVP_DecryptUpdate(ctx, decryptedtext, &lenght, cryptedtext, cryptedtext_lenght);

	//4.
	int decrypted_lenght = lenght;
	EVP_DecryptFinal_ex(ctx, decryptedtext + lenght, &lenght);

	//5.
	decrypted_lenght += lenght;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[decrypted_lenght] = '\0';
	cout << decryptedtext << endl;

	//шифрование файла 
	//производится порциями в цикле (точно так же)
	fstream f0, f_encrypted, f_decrypted;
	f0.open("f0.txt", std::fstream::in | std::fstream::binary);
	f_encrypted.open("f_encrypted.txt", std::fstream::out | std::fstream::trunc | std::fstream::binary);
	
	char buffer[256] = { 0 };
	char out_buffer[256] = { 0 };

	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, vect);
	lenght = 0;
	f0.read(buffer, 256);
	while (f0.gcount() > 0) //цикл, пока из файла что-то считывается
	{
		//шифрование
		EVP_EncryptUpdate(ctx, //объект с настройками
			(unsigned char *)out_buffer, //входной параметр: ссылка, куда помещать зашиф.данные
			&lenght, //выходной параметр, длина полученного шифра
			(unsigned char *)buffer, //входной параметр: что шифровать
			f0.gcount());//входной параметр: длина входных данных
		//вывод зашифрованной порции;
		f_encrypted.write(out_buffer, lenght);

		//считывание следующей порции;
		f0.read(buffer, 256);

		EVP_EncryptFinal_ex(ctx, (unsigned char*)out_buffer, &lenght);
		f_encrypted.write(out_buffer, lenght);
		f_encrypted.close();
		f0.close();

		memset(buffer, 0, sizeof(char)*256)
	
//не законченно

	getchar();
    return 0;
}

