#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char* argv[])
{
	printf("Для выхода введите 1\n");
	while (1) {
	int result = 0, arr[10][10] = { 0 };
	char src[256];
	scanf("%s",src);
	char* next = NULL;
	char* first = strtok_r(src, "+", &next); //Разделяем введенную строку относительно "+" на 2 части
	int i = 0;
		do {
			int j = 0; 
			char* part;
			char* posn;

			//printf("%s\n", first);
			part = strtok_r(first, "*", &posn);// Проверяем 1 часть строки и разделяем ее относительно знака "*";
				while (part != 0)
				{
					//printf(" [%s]\n", part);
					arr[i][j] = atoi(part); // Записываем в массив, либо 1 число при сложении, либо 2 и более при умножении;
					part = strtok_r(NULL, "*", &posn);
					j++;
				}
			i++;
		} while ((first = strtok_r(NULL, "+", &next)) != NULL);
			
			//Далее цикл перемножает числа, если в строке 2 и более ненулевых элемента.
		for (int i = 0; i != 10; i++) {
			for (int j = 0; j != 10; j++) {
				if (arr[i][j + 1] != NULL)
					arr[i][0] *= arr[i][j + 1];

				if (arr[i][j + 1] == NULL)
					break;
			}
		}
		for (int i = 0; i != 10; i++) { 
				result += arr[i][0];
		}
	printf("Result: %d\n", result);
			if (result == 1)
				break;
	}

	return 0;
}
