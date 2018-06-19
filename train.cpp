#include <iostream>

int input();
void free_bufferfer(char*);
void output(char*, int);

char* buffer;
int flag = 0;

struct Data
{
int length = 1；

};


int main()
{
								buffer = (char*)malloc(sizeof(char));
								if (buffer == nullptr)
								{
																return -1;
								}
								while (flag != 1)
								{
																output(buffer, input());
								}
								free_bufferfer(buffer);
}

int input()
{
								int length = 0;
								do
								{
																buffer[length] = std::getchar();
																if (buffer[length] == 27)
																{
																								flag = 1;
																								break;
																}
																buffer = (char*)realloc(buffer, sizeof(char) * (++length + 2));
								} while (buffer[length] != '\0');
								buffer[length] = '\0';
								return length;
}

void output(char* s, int n)
{
								for (int i = 0; i < n; i++)
								{
																std::putchar(s[i]);
								}
}

void free_bufferfer(char* s)
{
								if (s)
								{
																free(s);
								}
								s = nullptr;
}
