#include <iostream>

struct string_data
{
	int length;
	int buffer;
	int esp_checker;
	char* char_data;

	string_data(int i, int j)
	{
		length = i;
		buffer = j;
		esp_checker = 1;
		char_data = reinterpret_cast<char*>(malloc(sizeof(char) * buffer));
	}

	int input()
	{
		do
		{
			if (length > buffer)
			{
				char_data = (char*)realloc(char_data, sizeof(char) * (length + 32));
				buffer += 32;
			}
			char_data[length++] = std::getchar();
			if (char_data[length -1] == 27)
			{
				esp_checker = 0;
				char_data[length -1] = '\0';
				break;
			}
		} while (char_data[length-1] != '\n');
	}

	void output()
	{
		for (int i = 0; i < length; i++)
		{
			std::putchar(char_data[i]);
		}
	}

	void free_buffer()
	{
		if (char_data)
		{
		free(char_data);
		}
		char_data = nullptr;
	}

};


int main()
{
	struct string_data moji(0, 32);

	while (moji.esp_checker)
	{
		moji.input();
		moji.output();
	}
	moji.free_buffer();
}
